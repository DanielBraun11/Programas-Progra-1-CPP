#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


bool textoIncorrecto(const string& t) {        //Texto check
    for(char c : t){
        if(c == '.' || c == ',' || c == '?' || c == '!'){
            return true;        //Texto incorrecto
        }
    }
    return false;
}

struct datosNoCorrecto{
    int caracteresNoValidos{0};
    int caracteresValidos{0};
    int caracteresTotales{0};
};

int main(){
    bool on{true};
    string texto;
    datosNoCorrecto d;

    while(on){
        cout<<"Introduce un texto sin signos de puntuacion: "<<endl;
        cout<<"Introduce 'fin' para finalizar: "<<endl;
        getline(cin, texto);

        if(texto == "fin"){
            on = false;
        }else if(textoIncorrecto(texto)){   //Texto incorrecto
            for(char c : texto){
                if(c == '.' || c == ',' || c == '?' || c == '!'){
                    d.caracteresNoValidos++;
                }else{
                    d.caracteresValidos++;
                }
            }

            // Mostrar los datos del texto no válido
            cout<<"Caracteres no validos: "<<d.caracteresNoValidos<<endl;
            cout<<"Caracteres validos: "<<d.caracteresValidos<<endl;
            cout<<"Caracteres totales: "<<d.caracteresNoValidos + d.caracteresValidos<<endl;

            cout<<"---------------------------------"<<endl;
        }else{
            // Texto válido, dividirlo en palabras
            stringstream separar(texto);
            string cadena;
            vector<string> palabras;

            while(separar >> cadena){
                palabras.push_back(cadena);
            }

            // Mostrar las palabras del vector
            for(const string& palabra : palabras){
                cout<<palabra<<endl;
            }
            cout<<"---------------------------------"<<endl;
        }
    }

    return 0;
}
