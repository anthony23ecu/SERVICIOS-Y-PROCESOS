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
    double CalcularCarga(double cpu, double memoria_mb){
        double carga;
        return  carga = (cpu + memoria_mb) / 2;
    }

string clasificar(double cpu, double mem,
                  double a_cpu, double c_cpu,
                  double a_mem, double c_mem) {

    string clasificacion;

    if (cpu >= c_cpu || mem >= c_mem) {
        clasificacion = "CRITICO";
    } else if (cpu >= a_cpu || mem >= a_mem) {
        clasificacion = "ALERTA";
    } else {
        clasificacion = "NORMAL";
    }

    return clasificacion;
}



int main() {
    string nombre;
    double cpu;
    double memoria_mb;

    // ↓ Aquí declara los umbrales
    double umbral_alerta_cpu, umbral_critico_cpu;
    double umbral_alerta_mem, umbral_critico_mem;

    // Primero lees nombre, cpu y memoria
    cout << "Ingrese el nombre del proceso: ";
    getline(cin, nombre);
    cout << "Ingrese el uso de CPU (%): ";
    cin >> cpu;
    cout << "Ingrese el uso de Memoria (MB): ";
    cin >> memoria_mb;

    // Después lees los umbrales
    cout << "Umbral ALERTA CPU: ";
    cin >> umbral_alerta_cpu;
    cout << "Umbral CRITICO CPU: ";
    cin >> umbral_critico_cpu;
    cout << "Umbral ALERTA Memoria: ";
    cin >> umbral_alerta_mem;
    cout << "Umbral CRITICO Memoria: ";
    cin >> umbral_critico_mem;

    // Ahora sí, creas el proceso y luego ya podrás clasificar con esos umbrales
    Proceso proceso1(nombre, cpu, memoria_mb);
    // ...

    //aplicar penalizacion del 10%
    proceso1.aplicarPenalizacion(10);


//    cout << "Carga del proceso: " <<
    CalcularCarga(cpu, memoria_mb);
    cout << "Carga del proceso: " << CalcularCarga(cpu, memoria_mb) << endl;

// Esta función devuelve una cadena con la clasificación
    string estado = clasificar(cpu, memoria_mb,
                              umbral_alerta_cpu, umbral_critico_cpu,
                              umbral_alerta_mem, umbral_critico_mem);
    cout << "Estado del proceso: " << estado << endl;
    
    proceso1.mostrarFicha();
}
