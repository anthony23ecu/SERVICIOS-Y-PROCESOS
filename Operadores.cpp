#include <iostream>

using namespace std;

int main(){
    //Declaramos las variables solicitadas
    int edad = 30;
    double altura = 1.85;
    double peso = 75;

    //Realizamos las operaciones solicitadas
    int años_completos = edad * 2;
    // Convertir peso de kg a libras (1 kg = 2.20462 libras)
    double libras = peso * 2.20462;

    // Evaluamos las condiciones solicitadas
    bool es_alto = altura > 1.75;
    // El peso aceptable es menor o igual a 80 kg
    bool peso_aceptable = peso <= 80;

    // (es_alto ? "Sí" : "No") es una expresión condicional que devuelve "Sí" si es_alto es true y "No" si es false
    cout << "¿Es alto? " << (es_alto ? "Sí" : "No") << endl;
    cout << "¿Tiene un peso aceptable? " << (peso_aceptable ? "Sí" : "No") << endl;
    cout << "El peso en libras seria: " << libras << endl;
    cout << "Años completos" << años_completos << endl;
    
    

}