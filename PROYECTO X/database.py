import os
import sqlite3
from werkzeug.security import generate_password_hash

DB_NAME = os.getenv("DB_NAME", "erp.db")

def get_db():
    conn = sqlite3.connect(DB_NAME)
    conn.row_factory = sqlite3.Row
    return conn

def init_db():
    first_time = not os.path.exists(DB_NAME)
    conn = sqlite3.connect(DB_NAME)

    conn.execute(
        """
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            email TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL,
            role TEXT DEFAULT 'user'
        );
        """
    )

    conn.execute(
        """
        CREATE TABLE IF NOT EXISTS clients (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nombre TEXT NOT NULL,
            email TEXT,
            telefono TEXT,
            empresa TEXT,
            created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
        );
        """
    )

    conn.execute(
        """
        CREATE TABLE IF NOT EXISTS deals (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            client_id INTEGER NOT NULL,
            titulo TEXT NOT NULL,
            estado TEXT DEFAULT 'open',
            importe REAL DEFAULT 0,
            created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (client_id) REFERENCES clients(id)
        );
        """
    )

    # Índices recomendados
    conn.execute("CREATE INDEX IF NOT EXISTS idx_clients_email ON clients(email);")
    conn.execute("CREATE INDEX IF NOT EXISTS idx_deals_client ON deals(client_id);")

    conn.commit()

    if first_time:
        conn.execute(
            "INSERT INTO users (email, password, role) VALUES (?, ?, ?)",
            ("admin@ceac.local", generate_password_hash("<HASH>"), "admin"),
        )
        conn.commit()

    conn.close()