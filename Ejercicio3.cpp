/*Implementar un programa en C++ que pida al usuario 2 números
 *enteros por teclado y le pregunte qué operación matemática quiere
 *realizar con ellos (Suma=> opción 1, Resta=> opción 2). El programa
 *debe mostrar el resultado por pantalla en función de la opción elegida.
 */

#include <iostream>

using namespace std;

int main(){
    int numero1;
    int numero2;
    int seleccion;
    int suma;
    int resta;


    cout<<"Introduce un numero: "<<endl;
    cin>>numero1;

    cout<<"Introduce otro numero: "<<endl;
    cin>>numero2;

    cout<<"Menu seleccion: "<<endl;

    cout<<"Seleccione 1 para sumar o 2 para restar: "<<endl;
    cin>>seleccion;

    switch(seleccion){
    case 1: suma = numero1 + numero2;
        cout<<"La suma de ambos numeros es: "<<suma<<endl;
        break;
    case 2: resta = numero1 - numero2;
        cout<<"La resta de ambos numeros es: "<<resta<<endl;
        break;

    }

    return 0;
}
