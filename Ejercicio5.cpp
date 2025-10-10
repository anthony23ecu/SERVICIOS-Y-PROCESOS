#include <iostream>
#include <string>
using namespace std;

class Personaje {
private:
    string nombre;
    int vida;
    int estamina;

public:
    // Constructor
    Personaje(string nombre) {
        this->nombre = nombre;
        this->vida = 100;
        this->estamina = 100;
    }

    // Setters
    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    void setVida(int vida) {
        this->vida = vida;
    }

    void setEstamina(int estamina) {
        this->estamina = estamina;
    }

    // Getters
    string getNombre() {
        return this->nombre;
    }

    int getVida() {
        return this->vida;
    }

    int getEstamina() {
        return this->estamina;
    }

    // Método boxeo (acción)
    void boxeo(Personaje &oponente) {
        if (estamina >= 5) {
            oponente.vida = oponente.vida - 10;
            estamina = estamina - 5;
            cout << nombre << " golpea a " << oponente.nombre << "!" << endl;
            cout << "Vida de " << oponente.nombre << ": " << oponente.vida << endl;
            cout << "Estamina de " << nombre << ": " << estamina << endl;
        } else {
            cout << nombre << " está demasiado cansado para boxear." << endl;
        }
    }
    // En este metodo reposo hacemos que cada vez que se llame al metodo reposo, este haga un control en el cual si tiene 100 de vida no genere cura y si no genere una cura de estamina y vida.
    void reposo () {
        if(vida < 100){
            vida = vida + 5;
            estamina = estamina +10;
            cout <<"Estas regenerando vida" << endl;
             
        } else {
            cout <<"No puedes regenerar mas estamina y vida ya que tienes 100 de vida" << endl;
        }
    }




}; // ← recuerda cerrar la clase con punto y coma


int main(){
    Personaje p1("Rocky");
    Personaje p2("Apollo");
    p1.boxeo(p2);
    p2.boxeo(p1);
    p1.reposo();
    p2.reposo();
   
    return 0;
}