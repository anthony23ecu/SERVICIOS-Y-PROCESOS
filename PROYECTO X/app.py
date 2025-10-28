import os
import secrets
import hmac
from functools import wraps
import sqlite3
from flask import (
    Flask, render_template, request, redirect, url_for, session, g, abort
)
from database import init_db, get_db
from werkzeug.security import check_password_hash

app = Flask(__name__)
app.secret_key = os.getenv("SECRET_KEY", "dev-secret-cámbialo")

# ---------- DB lifecycle ----------

@app.before_request
def before_request():
    g.db = get_db()
    # CSRF token por sesión
    if "csrf_token" not in session:
        session["csrf_token"] = secrets.token_urlsafe(32)
    g.csrf_token = session["csrf_token"]

@app.teardown_request
def teardown_request(exception):
    db = getattr(g, 'db', None)
    if db is not None:
        db.close()

@app.context_processor
def inject_csrf():
    return {"csrf_token": session.get("csrf_token", "")}

def validate_csrf(token: str) -> bool:
    return bool(token) and hmac.compare_digest(token, session.get("csrf_token", ""))

# ---------- Auth ----------

def login_required(f):
    @wraps(f)
    def _wrap(*args, **kwargs):
        if "user_id" not in session:
            return redirect(url_for("login"))
        return f(*args, **kwargs)
    return _wrap

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        token = request.form.get("csrf_token", "")
        if not validate_csrf(token):
            abort(400, description="CSRF inválido")

        email = request.form.get("email", "").strip().lower()
        password = request.form.get("password", "")

        cur = g.db.execute("SELECT id, email, password, role FROM users WHERE email = ?", (email,))
        row = cur.fetchone()
        if row and check_password_hash(row["password"], password):
            session["user_id"] = row["id"]
            session["user_email"] = row["email"]
            session["role"] = row["role"]
            return redirect(url_for("list_clients"))
        return render_template("login.html", error="Credenciales inválidas")

    return render_template("login.html")

@app.route("/logout", methods=["POST"])
def logout():
    token = request.form.get("csrf_token", "")
    if not validate_csrf(token):
        abort(400, description="CSRF inválido")
    session.clear()
    return redirect(url_for("login"))

# ---------- Clientes (CRUD) ----------

@app.route("/")
def root():
    return redirect(url_for("list_clients"))

@app.route("/clients", methods=["GET"])
@login_required
def list_clients():
    cur = g.db.execute(
        "SELECT id, nombre, email, telefono, empresa, created_at FROM clients ORDER BY id DESC"
    )
    clients = cur.fetchall()
    return render_template("clients_list.html", clients=clients)

@app.route("/clients/new", methods=["GET", "POST"])
@login_required
def new_client():
    if request.method == "POST":
        if not validate_csrf(request.form.get("csrf_token", "")):
            abort(400, description="CSRF inválido")

        nombre = request.form.get("nombre", "").strip()
        email = request.form.get("email", "").strip()
        telefono = request.form.get("telefono", "").strip()
        empresa = request.form.get("empresa", "").strip()

        if not nombre:
            return render_template("client_form.html", mode="new", error="Nombre es obligatorio")

        g.db.execute(
            "INSERT INTO clients (nombre, email, telefono, empresa) VALUES (?, ?, ?, ?)",
            (nombre, email, telefono, empresa),
        )
        g.db.commit()
        return redirect(url_for("list_clients"))

    return render_template("client_form.html", mode="new")

@app.route("/clients/<int:client_id>", methods=["GET"])
@login_required
def view_client(client_id):
    cur = g.db.execute(
        "SELECT id, nombre, email, telefono, empresa, created_at FROM clients WHERE id = ?",
        (client_id,),
    )
    c = cur.fetchone()
    if not c:
        abort(404)
    return render_template("client_view.html", c=c)

@app.route("/clients/<int:client_id>/edit", methods=["GET", "POST"])
@login_required
def edit_client(client_id):
    if request.method == "POST":
        if not validate_csrf(request.form.get("csrf_token", "")):
            abort(400, description="CSRF inválido")

        nombre = request.form.get("nombre", "").strip()
        email = request.form.get("email", "").strip()
        telefono = request.form.get("telefono", "").strip()
        empresa = request.form.get("empresa", "").strip()

        if not nombre:
            cur = g.db.execute("SELECT * FROM clients WHERE id = ?", (client_id,))
            c = cur.fetchone()
            return render_template("client_form.html", mode="edit", c=c, error="Nombre es obligatorio")

        g.db.execute(
            "UPDATE clients SET nombre=?, email=?, telefono=?, empresa=? WHERE id=?",
            (nombre, email, telefono, empresa, client_id),
        )
        g.db.commit()
        return redirect(url_for("list_clients"))

    cur = g.db.execute("SELECT * FROM clients WHERE id = ?", (client_id,))
    c = cur.fetchone()
    if not c:
        abort(404)
    return render_template("client_form.html", mode="edit", c=c)

@app.route("/clients/<int:client_id>/delete", methods=["POST"])
@login_required
def delete_client(client_id):
    if not validate_csrf(request.form.get("csrf_token", "")):
        abort(400, description="CSRF inválido")
    g.db.execute("DELETE FROM clients WHERE id = ?", (client_id,))
    g.db.commit()
    return redirect(url_for("list_clients"))

# ---------- Main ----------

if __name__ == "__main__":
    init_db()
    app.run(debug=True)