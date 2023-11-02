/*Implementar un programa en C++ que pida al usuario el número
 *de términos de la secuencia de Fibonacci que quiere visualizar por
 *pantalla. Una vez que el usuario introduzca un número de términos
 *válido (>0), el programa mostrará por pantalla los términos indicados.
 */
#include <iostream>

using namespace std;

int main(){
    int a{0};
    int b{1};
    int c;
    int numero;

    cout<<"Introducce el numero de digitos que desees: "<<endl;
    cin>>numero;

    if(numero>0){
        for(int z{0}; z<numero; z++){
            if(z<=1){
                c=z;
            }else{
                a=b;
                b=c;
                c=a+b;
            }
            cout<<c<<endl;
        }
    }

    return 0;
}
