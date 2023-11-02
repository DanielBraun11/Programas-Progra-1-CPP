/*Implementar un programa en C++ que sea capaz de mostrar por terminal
 *los primeros 10 números multiplos de 3 que sean divisibles por 2.
*/
#include <iostream>

using namespace std;

int main() {
    int contador{0};
    int num{1}; //   0/algo no es posible.

    while (contador<10){
        if (num%3==0){
            if(num%2==0){
                cout<<num<<endl;
                contador++;
            }
        }
        num++;
    }

    return 0;
}
