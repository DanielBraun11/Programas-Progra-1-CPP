//Práctica 3 - Geupo A
#include <iostream>
#include <array>
#include <string>
using namespace std;

struct datosFrase{
    string frase;
    int longitud;
};

struct datosLetra{
    char letra;
    int contador;
};

struct datosPalabra{
    string palabra;
    int contador;
    int numFrase;   //Numero de la frase donde aparece
    int posFrase;
};

int main() {
    int opcion;
    int posicion;
    bool primeraVez{true};
    array<datosFrase,5> frases;
    array<datosLetra,5> letras;
    array<datosPalabra,5> palabras;

    do {
        cout<<"Seleccione una opcion (1-4): "<<endl;
        cout<<"1. Matriz de frases"<<endl;
        cout<<"2. Informacion de letra"<<endl;
        cout<<"3. Informacion de palabras"<<endl;
        cout<<"4. Salir del programa"<<endl;
        cin>>opcion;

        switch(opcion){
        case 1:
            cout<<"Introduzca 5 frases."<<endl;
            cin.ignore();

            //Rellenar las frases
            for(int i = 0; i < frases.size(); i++){
                cout<<"Frase " << i + 1 << ": "<<endl;
                getline(cin, frases.at(i).frase);
            }

            cout<<endl;
            //Calcular el tamaño y mostrar la frase y este
            for(int i = 0; i < frases.size(); i++){
                cout<<"Frase "<< i + 1<< ": "<< frases.at(i).frase<<endl;
                frases.at(i).longitud = frases.at(i).frase.size();
                cout<<"Longitud de la frase "<< i + 1<< ": "<< frases.at(i).longitud<<endl;
                cout<<endl;
            }

            cout<<"-------------------------------"<<endl;

            break;

        case 2:
            //Comprobar que las frases se han rellenado
            if(frases.at(0).frase.empty()){
                cout<<"Las frases aun no se han rellenado."<<endl;
                cout<<endl;
            }else{
                //Relleno las letras
                cout<<"Introduzca 5 letras."<<endl;
                for(int x{0} ; x<letras.size() ; x++){
                    cout<<"Letra "<<x+1<<": "<<endl;
                    cin>>letras.at(x).letra;
                    letras.at(x).contador = 0;  //Aprovecho e inicializo el contador de cada letra en 0
                }

                //Busco y cuento las letras
                for(int i{0} ; i<letras.size() ; i++){
                    for(int j{0} ; j<frases.size() ; j++){
                        posicion = frases.at(j).frase.find(letras.at(i).letra); //Buscar desde 0
                        while(posicion != -1){
                            letras.at(i).contador++;
                            posicion = frases.at(j).frase.find(letras.at(i).letra, posicion+1);  //Si encuentra, buscar desde 1 posicion mas de la devuelta
                        }

                    }
                }

                //Muestro los datos optenidos de las letras
                for(int i{0} ; i<letras.size() ; i++){
                    cout<<"Letra "<<i+1<<": "<<letras.at(i).letra<<endl;
                    cout<<"Veces que aparece la letra "<<i+1<<": "<<letras.at(i).contador<<endl;
                    cout<<endl;
                }
            }

            cout<<"-------------------------------"<<endl;

            break;

        case 3:
            //Comprobar que las frases se han rellenado
            if(frases.at(0).frase.empty()){
                cout<<"Las frases aun no se han rellenado."<<endl;
                cout<<endl;
            }else{
                //Rellenos las palabras
                cout<<"Introduce 5 palabras."<<endl;
                cin.ignore();
                for(int x{0} ; x<palabras.size() ; x++){
                    cout<<"Palabra "<<x+1<<": "<<endl;
                    getline(cin,palabras.at(x).palabra);
                    palabras.at(x).contador = 0;  //Aprovecho e inicializo el contador de cada palabra en 0
                    palabras.at(x).posFrase = -1; //Aprovecho e inicializo la posicion de cada palabra en -1
                    palabras.at(x).numFrase = -1; //Aprovecho e inicializo el numero de la frase de cada palabra en -1
                }

                cout<<endl;

                for(int i{0} ; i<palabras.size() ; i++){
                    primeraVez = true;
                    for(int j{0} ; j<frases.size() ; j++){
                        posicion = frases.at(j).frase.find(palabras.at(i).palabra);
                        while(posicion != -1){
                            palabras.at(i).contador++;
                            //posicion = frases.at(j).frase.find(palabras.at(i).palabra, posicion+1);
                            if(primeraVez == true){
                                palabras.at(i).numFrase = j;
                                palabras.at(i).posFrase = posicion;
                                primeraVez = false;
                            }
                            posicion = frases.at(j).frase.find(palabras.at(i).palabra, posicion+1);
                        }
                    }
                }

                //Muestro los datos optenidos de las palabras
                for(int i{0} ; i<palabras.size() ; i++){
                    cout<<"Palabra "<<i+1<<": "<<palabras.at(i).palabra<<endl;
                    if(palabras.at(i).contador > 0){
                        cout<<"Veces que aparece la palabra "<<i+1<<": "<<palabras.at(i).contador<<endl;
                        cout<<"Posicion de la palabra "<<i+1<<": "<<palabras.at(i).posFrase<<endl;
                        cout<<"Numero de frase donde aparece la palabra "<<i+1<<": "<<palabras.at(i).numFrase<<endl;
                    }else{
                        cout<<"Palabra no encontrada en las frases."<<endl;
                    }
                    cout<<endl;
                }
            }

            cout<<"-------------------------------"<<endl;

            break;

        case 4:
            //Salir del programa
            break;

        default:
            cout << "La opcion no es valida. Por favor, vuelva a seleccionar otra opcion." << endl;
        }

    } while (opcion != 4);

    return 0;
}
