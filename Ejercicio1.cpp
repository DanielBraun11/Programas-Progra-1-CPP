/* Modificar el ejercicio de la tabla de multiplicar (E5 tarea semana 4)
 * para mostrar por pantalla todas las tablas de multiplicar (tabla del 1, del 2, … del 10)
 */
#include <iostream>
using namespace std;

int main() {
    int resultado;

    for(int i{0}; i<11; i++){
        for(int j{0}; j<11; j++){
            resultado = i * j;
            cout<<i<<"x"<<j<<"="<<resultado<<endl;
        }
        cout<<endl; //Mejora estetica
    }

    return 0;
}
