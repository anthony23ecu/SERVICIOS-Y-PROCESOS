#include <iostream>
#include <string>
using namespace std;

// 2. Clase Proceso 
class Proceso {
private:
    string nombre;
    double cpu;
    double memoria_mb;

public: 
    // Constructor, Getters y Setters
    Proceso(string nombre, double cpu, double memoria_mb) {
        this->nombre = nombre;
        this->cpu = cpu;
        this->memoria_mb = memoria_mb;
    }

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    void setCpu(double cpu) {
        this->cpu = cpu;
    }
    
    void setMemoria(double memoria_mb) {
        this->memoria_mb = memoria_mb;
    }

    string getNombre() {
        return this->nombre;
    }

    double getCpu() {
        return this->cpu;
    }

    double getMemoria() {
        return this->memoria_mb;
    }
    //  Metodos
    void aplicarPenalizacion(double porcentaje) {
        cpu += cpu * (porcentaje / 100);
        memoria_mb += memoria_mb * (porcentaje / 100);
    }
 
    void mostrarFicha() {
    cout << "---- Ficha del proceso ----" << endl;
    cout << "Nombre:  " << nombre << endl;
    cout << "CPU:     " << cpu << "%" << endl;
    cout << "Memoria: " << memoria_mb << " MB" << endl;
}




}; // Cerrar la clase con punto y coma.

    // FUNCIONES
    double Calcular(double cpu, double memoria_mb){
        double carga;
        return  carga = (cpu + memoria_mb) / 2;
    }

    string clasificar(double cpu, double mem, double a_cpu, double, double a_mem, double c_men){
        
    }

int main() {

    string nombre;
    double cpu;
    double memoria_mb;

}
