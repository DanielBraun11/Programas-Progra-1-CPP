//Práctica 2 Grupo C
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct InfoFecha{
    int anio;
    int mes;
    int dia;
};

struct InfoCifras{
    int nCifrasPares{0};
    int nCifrasImpares{0};
    int nCifrasTotales{0};
};

struct InfoTexto{
    int totalVocales{0};
    int totalPalabras{0};
    int totalCaracteres{0};

};

int contadorPares(const vector<int>& cifras){
    int contadorDePares{0};
    for(int i : cifras){
        if(i % 2 == 0){
            contadorDePares++;
        }
    }
    return contadorDePares;
}

int contadorImpares(const vector<int>& cifras){
    int contadorDeImpares{0};
    for(int i : cifras){
        if(i % 2 != 0){
            contadorDeImpares++;
        }
    }
    return contadorDeImpares;
}

int contadorVocales(string& texto){
    int nVocales{0};
    for(int i{0} ; i<texto.size() ; i++){
        if(texto.at(i) == 'a' || texto.at(i) == 'e' || texto.at(i) == 'i' || texto.at(i) == 'o' || texto.at(i) == 'u'){
            nVocales++;
        }else if(texto.at(i) == 'A' || texto.at(i) == 'E' || texto.at(i) == 'I' || texto.at(i) == 'O' || texto.at(i) == 'U'){
            nVocales++;
        }
    }
    return nVocales;
}

int contadorPalabras(string& texto){
    int nPalabras{0};
    istringstream stream(texto);
    string palabra;

    while(stream >> palabra){
        nPalabras++;
    }
    return nPalabras;
}

int contadorCaracteres(string& texto){  //Distintos al espacio '';
    int nCaracteres{0};
    for(int i{0} ; i<texto.size() ; i++){
        if(texto.at(i) != ' '){
            nCaracteres++;
        }
    }
    return nCaracteres;
}

bool checkBisiesto(int a){
    if(a % 4 == 0 && a % 100 != 0){
        return true;
    }else if (a % 400 == 0){
        return true;
    }
    return false;
}

int main(){
    int opcion, numero;
    string texto;
    InfoFecha infoFecha;
    InfoCifras infoCifras;
    InfoTexto infoTexto;



    do{
        cout<<"Selecciona una opcion: "<<endl;

        cout<<"1. Validar fecha."<<endl;
        cout<<"2. Determinar las cifras pares/impares de un numero."<<endl;
        cout<<"3. Determinar letras y palabras de un texto."<<endl;
        cout<<"4. Salir del programa."<<endl;
        cin>>opcion;

        switch(opcion){
        case 1:{
            cout<<"Introduce el anio: "<<endl;
            cin>>infoFecha.anio;

            if(checkBisiesto(infoFecha.anio)){ //BISIESTO
                cout<<"Introduce el numero del mes(1-12): "<<endl;
                cin>>infoFecha.mes;

                switch(infoFecha.mes){
                case 1:
                    cout<<"Indica el numero de dia(1-31): "<<endl;
                    cin>>infoFecha.dia;

                    if(infoFecha.dia <= 0 || infoFecha.dia >= 32){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                    }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                    }
                break;

                case 2:
                    cout<<"Indica el numero de dia(1-29): "<<endl;
                    cin>>infoFecha.dia;

                    if(infoFecha.dia <= 0 || infoFecha.dia >= 30){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                    }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                    }
                break;

                case 3:
                    cout<<"Indica el numero de dia(1-31): "<<endl;
                    cin>>infoFecha.dia;

                    if(infoFecha.dia <= 0 || infoFecha.dia >= 32){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                    }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                    }
                break;

                case 4:
                    cout<<"Indica el numero de dia(1-30): "<<endl;
                    cin>>infoFecha.dia;

                    if(infoFecha.dia <= 0 || infoFecha.dia >= 31){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                    }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                    }
                break;

                case 5:
                    cout<<"Indica el numero de dia(1-31): "<<endl;
                    cin>>infoFecha.dia;

                    if(infoFecha.dia <= 0 || infoFecha.dia >= 32){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                    }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                    }
                break;

                case 6:
                    cout<<"Indica el numero de dia(1-30): "<<endl;
                    cin>>infoFecha.dia;

                    if(infoFecha.dia <= 0 || infoFecha.dia >= 31){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                    }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                    }
                break;

                case 7:
                    cout<<"Indica el numero de dia(1-31): "<<endl;
                    cin>>infoFecha.dia;

                    if(infoFecha.dia <= 0 || infoFecha.dia >= 32){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                    }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                    }
                break;

                case 8:
                    cout<<"Indica el numero de dia(1-31): "<<endl;
                    cin>>infoFecha.dia;

                    if(infoFecha.dia <= 0 || infoFecha.dia >= 32){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                    }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                    }
                break;

                case 9:
                    cout<<"Indica el numero de dia(1-30): "<<endl;
                    cin>>infoFecha.dia;

                    if(infoFecha.dia <= 0 || infoFecha.dia >= 31){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                    }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                    }
                break;

                case 10:
                    cout<<"Indica el numero de dia(1-31): "<<endl;
                    cin>>infoFecha.dia;

                    if(infoFecha.dia <= 0 || infoFecha.dia >= 32){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                    }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                    }
                break;

                case 11:
                    cout<<"Indica el numero de dia(1-30): "<<endl;
                    cin>>infoFecha.dia;

                    if(infoFecha.dia <= 0 || infoFecha.dia >= 31){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                    }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                    }
                break;

                case 12:
                    cout<<"Indica el numero de dia(1-30): "<<endl;
                    cin>>infoFecha.dia;

                    if(infoFecha.dia <= 0 || infoFecha.dia >= 31){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                    }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                    }
                break;

                default: cout<<"Numero de mes no valido."<<endl;

                }

            }else{ //NO BISIESTO

                cout<<"Introduce el numero del mes(1-12): "<<endl;
                cin>>infoFecha.mes;

                switch(infoFecha.mes){
                case 1:
                cout<<"Indica el numero de dia(1-31): "<<endl;
                cin>>infoFecha.dia;

                if(infoFecha.dia <= 0 || infoFecha.dia >= 32){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                }
                break;

                case 2:
                cout<<"Indica el numero de dia(1-28): "<<endl;
                cin>>infoFecha.dia;

                if(infoFecha.dia <= 0 || infoFecha.dia >= 29){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                }
                break;

                case 3:
                cout<<"Indica el numero de dia(1-31): "<<endl;
                cin>>infoFecha.dia;

                if(infoFecha.dia <= 0 || infoFecha.dia >= 32){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                }
                break;

                case 4:
                cout<<"Indica el numero de dia(1-30): "<<endl;
                cin>>infoFecha.dia;

                if(infoFecha.dia <= 0 || infoFecha.dia >= 31){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                }
                break;

                case 5:
                cout<<"Indica el numero de dia(1-31): "<<endl;
                cin>>infoFecha.dia;

                if(infoFecha.dia <= 0 || infoFecha.dia >= 32){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                }
                break;

                case 6:
                cout<<"Indica el numero de dia(1-30): "<<endl;
                cin>>infoFecha.dia;

                if(infoFecha.dia <= 0 || infoFecha.dia >= 31){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                }
                break;

                case 7:
                cout<<"Indica el numero de dia(1-31): "<<endl;
                cin>>infoFecha.dia;

                if(infoFecha.dia <= 0 || infoFecha.dia >= 32){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                }
                break;

                case 8:
                cout<<"Indica el numero de dia(1-31): "<<endl;
                cin>>infoFecha.dia;

                if(infoFecha.dia <= 0 || infoFecha.dia >= 32){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                }
                break;

                case 9:
                cout<<"Indica el numero de dia(1-30): "<<endl;
                cin>>infoFecha.dia;

                if(infoFecha.dia <= 0 || infoFecha.dia >= 31){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                }
                break;

                case 10:
                cout<<"Indica el numero de dia(1-31): "<<endl;
                cin>>infoFecha.dia;

                if(infoFecha.dia <= 0 || infoFecha.dia >= 32){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                }
                break;

                case 11:
                cout<<"Indica el numero de dia(1-30): "<<endl;
                cin>>infoFecha.dia;

                if(infoFecha.dia <= 0 || infoFecha.dia >= 31){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                }
                break;

                case 12:
                cout<<"Indica el numero de dia(1-30): "<<endl;
                cin>>infoFecha.dia;

                if(infoFecha.dia <= 0 || infoFecha.dia >= 31){
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha INCORRECTA."<<endl;
                }else{
                        cout<<"La fecha "<<infoFecha.dia<<"/"<<infoFecha.mes<<"/"<<infoFecha.anio<<" es una fecha CORRECTA."<<endl;
                }
                break;

                default: cout<<"Numero de mes no valido."<<endl;

                }

            }

            cout<<"---------------------------------"<<endl;

            break;
        }

        case 2:{
            vector<int> cifras;
            infoCifras.nCifrasImpares = 0;
            infoCifras.nCifrasPares = 0;
            infoCifras.nCifrasTotales = 0;

            cout<<"Introduce un numero entero positivo: "<<endl;
            cin>>numero;

            int temp = numero;

            while(temp > 0){
                int digito = temp % 10;
                cifras.push_back(digito);
                temp/=10;
            }

            infoCifras.nCifrasPares = contadorPares(cifras);
            infoCifras.nCifrasImpares = contadorImpares(cifras);
            infoCifras.nCifrasTotales = cifras.size();

            //Mostrar datos
            cout<<"El numero "<<numero<<" tiene "<<infoCifras.nCifrasPares<<" cifras pares."<<endl;
            cout<<"El numero "<<numero<<" tiene "<<infoCifras.nCifrasImpares<<" cifras impares."<<endl;
            cout<<"El numero "<<numero<<" tiene "<<infoCifras.nCifrasTotales<<" cifras en total."<<endl;

            cout<<"---------------------------------"<<endl;

            break;
        }

        case 3:{
            cin.ignore();
            cout<<"Introduce un texto: "<<endl;
            getline(cin,texto);

            infoTexto.totalVocales = contadorVocales(texto);
            infoTexto.totalPalabras = contadorPalabras(texto);
            infoTexto.totalCaracteres = contadorCaracteres(texto);

            //Mostrar datos
            cout<<"El texto tiene un total de "<<infoTexto.totalVocales<<" vocales."<<endl;
            cout<<"El texto tiene un total de "<<infoTexto.totalPalabras<<" palabras."<<endl;
            cout<<"El texto tiene un total de "<<infoTexto.totalCaracteres<<" caracteres."<<endl;

            cout<<"---------------------------------"<<endl;

            break;
        }

        case 4:{
            cout<<"Gracias y hasta pronto."<<endl;
            break;
        }
            default: cout<<"La opcion no es valida. Por favor, vuelva a seleccionar otra opcion."<<endl;

        }

    }while(opcion != 4);

    return 0;
}
