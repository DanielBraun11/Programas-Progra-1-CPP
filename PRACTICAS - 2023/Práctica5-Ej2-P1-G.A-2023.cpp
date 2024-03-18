//Práctica 5 - Grupo A
//Ejercicio 2
#include <iostream>
#include<array>
using namespace std;

void rellenarLaMatriz(array<array<int,3>,3>& matriz){
    for(int i{0} ; i<matriz.size() ; i++){
        for(int j{0} ; j<matriz.at(i).size() ; j++){
            cout<<"Pos ["<<i<<"] ["<<j<<"]: "<<endl;
            cin>>matriz.at(i).at(j);
        }
    }
}

void mostrarLaMatriz(array<array<int,3>,3>& matriz){
    for(int i{0} ; i<matriz.size() ; i++){
        for(int j{0} ; j<matriz.at(i).size() ; j++){
            cout<<" | "<<matriz.at(i).at(j);
        }
        cout<<" | "<<endl;
        cout<<"------------------"<<endl;
    }
}

array<array<int,3>,3> crearTraspuesta(array<array<int,3>,3>& matriz){
    array<array<int,3>,3> matrizTraspuesta;
    for(int i{0} ; i<matriz.size() ; i++){
        for(int j{0} ; j<matriz.at(i).size() ; j++){
            matrizTraspuesta.at(i).at(j) = matriz.at(j).at(i);
        }
    }
    return matrizTraspuesta;
}

bool checkDeSimetria(array<array<int,3>,3>& matriz, array<array<int,3>,3>& traspuesta){
    for(int i{0} ; i<matriz.size() ; i++){
        for(int j{0} ; j<matriz.at(i).size() ; j++){
            if(matriz.at(i).at(j) != traspuesta.at(i).at(j)){
                return false;
            }
        }
    }
    return true;
}

bool checkDeAntisimetria(array<array<int,3>,3>& matriz, array<array<int,3>,3>& traspuesta){
    for(int i{0} ; i<matriz.size() ; i++){
        for(int j{0} ; j<matriz.at(i).size() ; j++){
            if(matriz.at(i).at(j) != - traspuesta.at(i).at(j)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    array<array<int,3>,3> matriz;

    rellenarLaMatriz(matriz);

    mostrarLaMatriz(matriz);

    //Crear una matriz 2 = traspuesta de la anterior

    array<array<int,3>,3> traspuesta = crearTraspuesta(matriz);

    cout<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<endl;

    mostrarLaMatriz(traspuesta);

    //CHECK DE SIMETRIA
    if(checkDeSimetria(matriz,traspuesta)){
        cout<<"La matriz es simetrica."<<endl;
    }

    //CHECK DE ANTISIMETRIA
    if(checkDeAntisimetria(matriz, traspuesta)){
        cout<<"La matriz es antimestrica."<<endl;
    }

    if(checkDeSimetria(matriz,traspuesta) == false && checkDeSimetria(matriz,traspuesta) == false){
        cout<<"La matriz no tiene nada."<<endl;
    }

    return 0;
}
