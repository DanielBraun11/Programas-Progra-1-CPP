/*Implementar un programa en C++ que pida al usuario dos
 *números enteros (base y exponente) y muestre por pantalla
 *el resultado de la potenciación base.
 */
#include <iostream>
using namespace std;

int main(){
    int base, exponente;
    int resultado{1};


    cout<<"Introduce una base: "<<endl;
    cin>>base;

    cout<<"Introduce un exponente: "<<endl;
    cin>>exponente;

    for(int i{0}; i< exponente; i++){
        resultado *=base;
    }

    cout<<resultado<<endl;

    return 0;
}
