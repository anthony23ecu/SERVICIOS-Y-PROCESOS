#include <iostream>
#include <string>

using namespace std;

// Creo la funcion que registra los datos y printea los datos añadidos
void registrar_vuelta(int vuelta, double minutos){

 cout << "Vuelta registrada en:  " << vuelta << " vueltas y " << minutos << " minutos" << endl;

}

void resumen_entrenamiento(){

registrar_vuelta(8, 2.5);
registrar_vuelta(10, 3.5);

cout << "Resumen del entrenamiento: " << endl;
cout << "Total de vueltas: 18" << endl;
cout << "Total de minutos: 6" << endl;




}

// Se declara el main, añade los datos y se llama a la función la cual printea el resultado
int main(){

registrar_vuelta(10, 2.5);

resumen_entrenamiento();


return 0;
}