//Daniel Braun Sandino
//Parcial - Ejercicio 1

#include <iostream>
#include <array>
#include <cmath>
#include<vector>

using namespace std;

struct datos{
    vector<int> numerosPares{0};
    vector<int> numerosImpares{0};
};


int main() {
    array<int,50> cuadradosPerfectos;
    int x{0};
    datos d;

    for (int i{0}; x<cuadradosPerfectos.size(); i++) {
        int raiz = static_cast<int>(sqrt(i));                        //Calcula la raíz cuadrada y convierte a int
        if (raiz * raiz == i) {                                      // Verifico si es un cuadrado perfecto
            cuadradosPerfectos.at(x) = i;
            x++;
        }
    }

    for (int i{0}; i < cuadradosPerfectos.size(); i++) {             //Mostrar los cuadrados perfectos
        cout << cuadradosPerfectos.at(i) << " ";
    }

    cout<<endl;    //Estetico

    //Separar en pares o impares
    for(int i{1}; i<cuadradosPerfectos.size(); i++){
        if(cuadradosPerfectos.at(i)%2==0){                      //Par check
            d.numerosPares.push_back(cuadradosPerfectos.at(i));
        }else{
            d.numerosImpares.push_back(cuadradosPerfectos.at(i));
        }
    }


    //Mostrar pares con for(:)
    cout<<"Numeros pares: "<<endl;

    for(int y : d.numerosPares){
        cout<<y<<" ";
    }

    cout<<endl;

    //Mostrar impares con while()
    cout<<"Numeros Impares: "<<endl;
    int cont{0};
    while(cont<d.numerosImpares.size()){
        cout<<d.numerosImpares.at(cont)<<" ";
        cont++;
    }

    cout<<endl;  //Estetico

    return 0;
}
