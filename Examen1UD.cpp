#include <iostream>
#include <string>
using namespace std;

//Ejercicio examen,  Calculadora de descuentos con funciones.


//Funciones
//Lo que hace es aplicar el descuento segun el precio
//Si el precio es mayor o igual a 100 aplica un 10%
//Si el precio es mayor o igual a 50 y menor que 100 aplica un 5%
//Si el precio es menor que 50 no aplica descuento
double calcularDescuento(double precio, double descuento0, double descuento5, double descuento10){
    double precioFinal;
    if(precio >= 100){
        precioFinal = precio - (precio * (descuento10 / 100));
    } else if(precio >= 50 && precio < 100){
        precioFinal = precio - (precio * (descuento5 / 100));
    } else {
        cout << "No aplica descuento" << endl;
        precioFinal = precio;
        
    }
    return precioFinal;
}

double montoDescuento (double precio, double precioFinal){
    return precio - precioFinal;
}


int main(){
    //Declaracion de variables
    double precio;
    //Entrada de datos
    cout << "Ingrese el precio del producto: ";
    cin >> precio;

    //Declaracion de los descuentos
    double descuento0 = 0;
    double descuento5 = 5;
    double descuento10 = 10;

    // Calculamos el precio final con la funcion
    double precioFinal = calcularDescuento(precio, descuento0, descuento5, descuento10);

    cout << "El precio del producto es: " << precio << endl;

    cout << "Descuento aplicado en porcentaje: " << ((precio - precioFinal) / precio) * 100 << "%" << endl;

    cout << "Monto del descuento aplicado: " << montoDescuento(precio, precioFinal) << endl;
    
    cout << "El precio final es: " << precioFinal << endl;
    
    
    return 0;
    


}