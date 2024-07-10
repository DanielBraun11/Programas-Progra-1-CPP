//Daniel Braun Sandino
//Extraordinaria 2023 - Turno 1
//Ejercicio 1

#include<iostream>
#include<array>

using namespace std;

int main(){
    const int dim = 3;
    bool continuar = true;
    int resp;
    array<array<int,dim>,dim> matriz;
    array<array<int,dim>,dim> matrizTraspuesta;
    bool simetrica = true;
    bool antisimetrica = true;
    bool nada = true;

    do{
        //Rellenar la matriz
        for(int i{0} ; i<matriz.size() ; i++){
            for(int j{0} ; j<matriz.at(i).size() ; j++){
                cout<<"Valor["<<i<<"]["<<j<<"]: ";
                cin>>matriz.at(i).at(j);
            }
        }

        //Hacer traspuesta
        for(int i{0} ; i<matriz.size() ; i++){
            for(int j{0} ; j<matriz.at(i).size() ; j++){
                matrizTraspuesta.at(i).at(j) = matriz.at(j).at(i);
            }
        }

        cout<<endl;

        //Mostrar matriz
        cout<<"MATRIZ CUADRADA ORIGINAL"<<endl;
        for(int i{0} ; i<matriz.size() ; i++){
            for(int j{0} ; j<matriz.at(i).size() ; j++){
                cout<<" | "<<matriz.at(i).at(j);
            }
            cout<<" | "<<endl;
            cout<<"--------------"<<endl;
        }

        cout<<endl;

        //Mostrar matriz traspuesta
        cout<<"MATRIZ CUADRADA TRASPUESTA"<<endl;
        for(int i{0} ; i<matrizTraspuesta.size() ; i++){
            for(int j{0} ; j<matrizTraspuesta.at(i).size() ; j++){
                cout<<" | "<<matrizTraspuesta.at(i).at(j);
            }
            cout<<" | "<<endl;
            cout<<"--------------"<<endl;
        }

        //Calcular tipo
        for(int i{0} ; i<matriz.size() ; i++){
            for(int j{0} ; j<matriz.at(i).size() ; j++){
                //Simetrica
                if(matriz.at(i).at(j) != matrizTraspuesta.at(i).at(j)){
                    simetrica = false;
                }
                //Antisimetrica
                if(matriz.at(i).at(j) != (matrizTraspuesta.at(i).at(j)/-1)){
                    antisimetrica = false;
                }
            }
        }

        //Resultados
        if(simetrica){
            cout<<"La matriz es siemtrica"<<endl;
        }else if(antisimetrica){
            cout<<"La matriz es antisiemtrica"<<endl;
        }else{
            cout<<"La matriz no es nada"<<endl;
        }

        //Desea continuar?
        cout<<"Desea operar con otra matriz si(0) no(1)?: "<<endl;
        cin>>resp;
        if(resp == 1){
            continuar = false;
        }

    }while(continuar);


    return 0;
}


