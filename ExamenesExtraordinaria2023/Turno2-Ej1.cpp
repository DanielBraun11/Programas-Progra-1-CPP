//Daniel Braun Sandino
//Extraordinaria 2023 - Turno 2
//Ejercicio 1

#include<iostream>

using namespace std;

int main(){
    int numero;
    int posicion;
    string respuesta;
    bool seguir = true;


    do{
        try{
            cout<<"Introduce un numero: "<<endl;
            cin>>numero;

            cout<<"Introduce una posicion: "<<endl;
            cin>>posicion;
            cin.ignore();

            if(numero < 0 || posicion < 0){
                throw string ("Error, los valores no cumplen con los requisitos");
            }

            string cadena = to_string(numero);

            if(cadena.size() < posicion){
                throw string ("Posicion fuera de rango");
            }else{
                cout<<"Numero: "<<cadena<<endl;
                cout<<"Digito en la posicion "<<posicion<<" es "<<cadena.at(posicion)<<endl;
            }

            cout<<endl;

        }catch(const string &error){
            cout<<error<<endl;
        }

        cout<<"Desea continuar(si/no)?:"<<endl;
        getline(cin,respuesta);

        if(respuesta == "no"){
            seguir = false;
        }else{
            seguir = true;
        }

    }while(seguir == true);

    return 0;
}



