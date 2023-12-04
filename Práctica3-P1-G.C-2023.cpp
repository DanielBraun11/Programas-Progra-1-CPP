//PRACTICA DEL GRUPO C
#include <iostream>
#include <array>
#include <string>
using namespace std;

struct datosFrase{
    string frase;
    char primeraLetra;
};

struct datosVocal{
    array<int, 5> conteoPorFrase;
    int conteoTotal;
};

struct datosPalabras{
    string palabra;
    int conteoPorFrase;
    int numFrase; //Si no encuentra la palabra = -1
    int posFrase;
};

int main() {
    int opcion;
    int posicion;
    int posfrase;
    array<datosFrase, 5> frases;
    array<datosVocal,5> vocales; //a e i o u
    array<datosPalabras,5> palabras;
    array<char,5> lasVocales {'a' , 'e' , 'i' ,'o' , 'u'};


    // Menu de selección
    do{
        cout<<"Seleccione una opcion (1-4): "<<endl;
        cout<<"1. Tabla de frases"<<endl;
        cout<<"2. Informacion de vocales"<<endl;
        cout<<"3. Informacion de palabras"<<endl;
        cout<<"4. Salir del programa"<<endl;
        cin>>opcion;


        switch(opcion){
        // Matriz de frases
        case 1:
            cout<<"Introduzca 5 frases."<<endl;
            cin.ignore();

            //Pedir frases
            for(int i{0} ; i<frases.size() ; i++){
                cout<<"Frase "<<i+1<<": "<<endl;
                getline(cin, frases.at(i).frase);
            }

            cout<<endl;

            //Operar y mostrar
            for(int i{0} ; i<frases.size() ; i++){
                cout<<"Frase "<<i+1<<": "<<frases.at(i).frase<<endl;
                frases.at(i).primeraLetra = frases.at(i).frase.front();
                cout<<"Primera letra de la frase "<<i+1<<": "<<frases.at(i).primeraLetra<<endl;
                cout<<endl;
            }

            cout<<"-------------------------------"<<endl;

            break;

        case 2:
            //Comprobar que las frases se han rellenado
            if(frases.at(0).frase.empty()){
                cout<<"Las frases no se han rellendado aun."<<endl;
                cout<<"-------------------------------"<<endl;
                cout<<endl;
                break;
            }else{
                //Inicializo
                for(int i{0} ; i<vocales.size() ; i++){
                    vocales.at(i).conteoTotal = 0;
                    vocales.at(i).conteoPorFrase.fill(0);   //Uso fill() para inicialiar todos los elementos de la tabla a 0
                }

                for(int i{0} ; i<vocales.size() ; i++){
                    for(int j{0} ; j<frases.size() ; j++){
                        posicion = frases.at(j).frase.find(lasVocales.at(i));
                        while(posicion != -1){
                            vocales.at(i).conteoTotal++;
                            vocales.at(i).conteoPorFrase.at(j)++;
                            posicion = frases.at(j).frase.find(lasVocales.at(i), posicion + 1);
                        }
                    }
                }

                //Mostrar datos
                for(int i{0} ; i<vocales.size() ; i++){
                    cout<<"La vocal ("<<lasVocales.at(i)<<") aparece en "<<endl;
                    posfrase = 0;
                    for(int veces : vocales.at(i).conteoPorFrase){
                        cout<<"La frase "<<posfrase<<" y tiene "<<veces<<" vocales."<<endl;
                        posfrase++;
                    }
                    cout<<endl;
                }
            }

            cout<<"-------------------------------"<<endl;

            break;

        case 3:
            //Comprobar que las frases se han rellenado
            if(frases.at(0).frase.empty()){
                cout<<"Las frases no se han rellendado aun."<<endl;
                cout<<"-------------------------------"<<endl;
                cout<<endl;
                break;
            }else{
                //Rellenar las palabras
                cout<<"Introduce las palabras para buscar."<<endl;
                cin.ignore();
                for(int i{0} ; i<palabras.size() ; i++){
                    cout<<"Palabra "<<i+1<<": "<<endl;
                    getline(cin,palabras.at(i).palabra);
                }

                //Inicializo
                for(int i{0} ; i<palabras.size() ; i++){
                    palabras.at(i).numFrase = -1;
                    palabras.at(i).posFrase = -1;
                    palabras.at(i).conteoPorFrase = 0;

                    bool primeraVez = true;

                    for(int j{0} ; j<frases.size() ; j++){
                        posicion = frases.at(j).frase.find(palabras.at(i).palabra);
                        while(posicion != -1){
                            palabras.at(i).conteoPorFrase++;
                            if(primeraVez){
                                palabras.at(i).numFrase = j;
                                palabras.at(i).posFrase = posicion;
                                primeraVez = false;
                            }
                            posicion = frases.at(j).frase.find(palabras.at(i).palabra, posicion + 1);
                        }
                    }
                }

                //Mostrar datos
                for(int i{0} ; i<palabras.size() ; i++){
                    cout<<"La palabra ("<<palabras.at(i).palabra<<") aparece "<<palabras.at(i).conteoPorFrase<<" veces."<<endl;
                    cout<<"La palabra ("<<palabras.at(i).palabra<<") aparece en la frase "<<palabras.at(i).numFrase<<endl;
                    cout<<"La palabra ("<<palabras.at(i).palabra<<") aparece en la posicion "<<palabras.at(i).posFrase<<endl;
                    cout<<endl;
                }
            }

            cout<<"-------------------------------"<<endl;

            break;

        case 4:
            cout<<"Gracias y hasta pronto."<<endl;  //Salir del programa
            break;

        default:
            cout<<"La opcion no es valida. Por favor, vuelva a seleccionar otra opcion."<<endl;
        }

    }while(opcion != 4);

    return 0;
}
