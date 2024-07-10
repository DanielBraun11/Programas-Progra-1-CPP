//Daniel Braun Sandino
//Extraordinaria 2023 - Turno 2
//Ejercicio 3

#include<iostream>

using namespace std;

string cambiar(string &t,const string &patr ,const string &sust){
    string textoNuevo = t;

    if(t.find(patr) == -1){
        return t;
    }

    while(textoNuevo.find(patr) != -1){
        int pos = textoNuevo.find(patr);
        textoNuevo.erase(pos,patr.size());
        textoNuevo.insert(pos,sust);

    }

    return textoNuevo;
}

string cifrar(string &t,int pos){
    string textoCifrado = t;

    string rotar = textoCifrado.substr(0,pos);

    textoCifrado.erase(0,pos);
    textoCifrado = textoCifrado + rotar;

    return textoCifrado;
}

int main(){
    string texto;
    string patron;
    string sustitucion;
    int posCif;

    cout<<"Introduce un texto: "<<endl;
    getline(cin,texto);

    cout<<"Introduce un patron a buscar: "<<endl;
    getline(cin,patron);

    cout<<"Introduce un texto para sustituir: "<<endl;
    getline(cin,sustitucion);

    //Funcion 1
    string nuevoTexto = cambiar(texto,patron,sustitucion);

    cout<<"Texto inicio: "<<texto<<endl;
    cout<<"Texto final: "<<nuevoTexto<<endl;
    
    cout<<endl;
    //---------------------------

    cout<<"Introduce las posiciones de cifrado: "<<endl;
    cin>>posCif;

    //Funcion 2
    string textoCifrado = cifrar(texto,posCif);

    cout<<"Texto inicial: "<<texto<<endl;
    cout<<"Texto cifrado: "<<textoCifrado<<endl;


    return 0;
}



