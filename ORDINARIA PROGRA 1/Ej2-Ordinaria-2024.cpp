//Daniel Braun Sandino
//Ejercicio 2

#include <iostream>
#include<sstream>
#include<vector>
#include<memory>

using namespace std;

struct infoFrase{
    int numPalab;
    int numPalabVocal;
    int numPalabNoVocal;
    string palabMasLarga;

    infoFrase() : numPalab(0), numPalabVocal(0), numPalabNoVocal(0), palabMasLarga("") {}
};

//FUNCION CONTAR PALABRAS
int contadorPalab(const vector<string> &almacenDePalab){
    return almacenDePalab.size();
}

//FUNCION CONTAR PALABRAS QUE EMPIECEN POR VOCAL
int contadorConVocal(const vector<string> &almacenDePalab){
    int contador{0};

    for(int i{0} ; i<almacenDePalab.size() ; i++){
        if(almacenDePalab.at(i).front() == 'a' || almacenDePalab.at(i).front() == 'e' || almacenDePalab.at(i).front() == 'i' || almacenDePalab.at(i).front() == 'o' || almacenDePalab.at(i).front() == 'u'){
            contador++;
        }
    }

    return contador;
}


//FUNCION CONTAR PALABRAS QUE NO EMPIECEN POR VOCAL
int contadorNoVocal(const vector<string> &almacenDePalab){
    int contador{0};

    for(int i{0} ; i<almacenDePalab.size() ; i++){
        if(almacenDePalab.at(i).front() != 'a' && almacenDePalab.at(i).front() != 'e' && almacenDePalab.at(i).front() != 'i' && almacenDePalab.at(i).front() != 'o' && almacenDePalab.at(i).front() != 'u'){
            contador++;
        }
    }

    return contador;
}

//FUNCION PALABRA MAS LARGA
string detectPalabra(const vector<string> &almacenDePalab){
    string palabraMayor = almacenDePalab.at(0);

    for(int i{1} ; i<almacenDePalab.size() ; i++){
        if(almacenDePalab.at(i).size() > palabraMayor.size()){
            palabraMayor = almacenDePalab.at(i);
        }
    }

    return palabraMayor;
}

//FUNCION ANALIZADORA
shared_ptr<infoFrase> analizador(const string &frase){
    shared_ptr<infoFrase> i = make_shared<infoFrase>();

    stringstream op (frase);
    string palabra;
    vector<string> almacenDePalab;

    while(op >> palabra){
        almacenDePalab.push_back(palabra);
    }

    i->numPalab = contadorPalab(almacenDePalab);
    i->numPalabVocal = contadorConVocal(almacenDePalab);
    i->numPalabNoVocal = contadorNoVocal(almacenDePalab);
    i->palabMasLarga = detectPalabra(almacenDePalab);

    return i;
}

//FUNCION MOSTRAR
void mostrarDatos(const shared_ptr<infoFrase> &f){
    cout<<"Informacion de frase: "<<endl;
    cout<<"Numero de palabras: "<<f->numPalab<<endl;
    cout<<"Numero de palabras que empiezan por vocal: "<<f->numPalabVocal<<endl;
    cout<<"Numero de palabras que NO empiezan por vocal: "<<f->numPalabNoVocal<<endl;
    cout<<"Palabra mas larga: "<<f->palabMasLarga<<endl;
    cout<<"--------------------------------------------"<<endl;
}

int main(){
    string frase;
    string respuesta;
    bool continuar = true;

    cout<<"Bienvenido"<<endl;

    do{
        cout<<"Introduce una frase: "<<endl;
        getline(cin, frase);

        shared_ptr<infoFrase> operacion = analizador(frase);
        mostrarDatos(operacion);

        cout<<"Desea continuar con una nueva palabra?(si/no): "<<endl;
        getline(cin, respuesta);

        if(respuesta == "no"){
            continuar = false;
        }


    }while(continuar == true);


    return 0;
}
