#include <iostream>
#include <string>
using namespace std;
//Programa que da consejos de boxeo segun el nivel del usuario
int main(){
    //Se declara la variable nivel
    string nivel;
    //Se pide al usuario que ingrese su nivel de boxeo
    cout << "Que nivel de boxeo tienes? (Princiante / Intermedio / Avanzado)" << endl;
    //Se lee el nivel ingresado por el usuario
    cin >> nivel;
//Se evalua el nivel ingresado y se muestran los consejos correspondientes
    if (nivel == "Principiante")
    {
        cout << "Debes seguir los siguientes consejos:" << endl;
        cout << "- Aprende la postura básica y la guardia." << endl;
        cout << "- Practica el jab y el cross correctamente." << endl;
        cout << "- Trabaja en tu condición física y resistencia." << endl;
        cout << "- Escucha siempre a tu entrenador." << endl;
        cout << "- Usa protección adecuada y calienta antes de entrenar." << endl;
    }else if (nivel == "Intermedio")
    {
        cout << "Debes seguir los siguientes consejos:" << endl;
        cout << "- Mejora la técnica de tus golpes y combinaciones." << endl;
        cout << "- Trabaja en tu defensa y movimientos de pies." << endl;
        cout << "- Incrementa la intensidad de tus entrenamientos." << endl;
        cout << "- Sparring con compañeros de diferentes estilos." << endl;
        cout << "- Mantén una dieta equilibrada y descansa adecuadamente." << endl;

} else if (nivel == "Avanzado")
    {
        cout << "Debes seguir los siguientes consejos:" << endl;
        cout << "- Perfecciona tus habilidades técnicas y tácticas." << endl;
        cout << "- Analiza a tus oponentes y adapta tu estrategia." << endl;
        cout << "- Entrena con boxeadores de alto nivel." << endl;
        cout << "- Enfócate en la preparación mental y la concentración." << endl;
        cout << "- Cuida tu cuerpo con fisioterapia y recuperación activa." << endl;
        //Se muestra un mensaje de error si el nivel ingresado no es reconocido
    } else {
        cout << "Nivel no reconocido. Por favor, ingresa Principiante, Intermedio o Avanzado." << endl;
    }
    //Finaliza el programa
    return 0;
}