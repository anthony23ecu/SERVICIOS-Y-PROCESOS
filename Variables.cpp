#include <iostream>
#include <string>
using namespace std;

int main(){
    //Declaramos las variable solicitadas
    string nombre_atleta = "Juan Perez";
    int edad = 30;
    double peso = 75.5;
    int horas_de_entrenamiento = 2;

    //Se calcula las horas de entrenamiento * 7 y este se divide ente 7 para dar el promedio de las horas diarias en las cuales has estado en el gimnasio
    int promedio_horas = (horas_de_entrenamiento * 7) / 7;

    // Mostramos por pantalla los datos solicitados
    cout << "Nombre del atleta: " << nombre_atleta << endl;
    cout << "Edad: " << edad << endl;
    cout << "Peso:" << peso << endl;
    cout << "Hora de entrenamiento: " << horas_de_entrenamiento << endl;
    cout << "Promedio semanal: " << promedio_horas << endl;

}