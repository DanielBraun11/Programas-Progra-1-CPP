/*Implementar un programa en C++ que solicite al usuario ingresar
 *un número entero para que a continuación muestre por pantalla la tabla
 *de multiplicar de dicho número.
 */
#include <iostream>
using namespace std;

int main(){
    int numero;
    int resultado;

    cout<<"Dame un numero: "<<endl;
    cin>>numero;

    for(int i{0}; i<11; i++){
        resultado = numero * i;
        cout<<numero<<"x"<<i<<"="<<resultado<<endl;
    }

    return 0;
}
