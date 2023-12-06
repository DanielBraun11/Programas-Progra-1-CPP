//Práctica 2 Grupo A
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DatosCifra{
    int cifraMenor;
    int cifraMayor;
    int totalDeCifras{0};
};

struct DatosVocales{
    int totalA;
    int totalE;
    int totalI;
    int totalO;
    int totalU;
};

int buscarMayor(const vector<int>& ordenNum){
    int numMayor = ordenNum.at(0);
    for(int i{1}; i<ordenNum.size() ; i++){
        if(ordenNum.at(i) > numMayor){
            numMayor = ordenNum.at(i);
        }
    }
    return numMayor;
}

int buscarMenor(const vector<int>& ordenNum){
    int numMenor = ordenNum.at(0);
    for(int i{1}; i<ordenNum.size() ; i++){
        if(ordenNum.at(i) < numMenor){
            numMenor = ordenNum.at(i);
        }
    }
    return numMenor;
}

bool vocalCheck(char num){
    if(num == 'a' || num == 'e' || num == 'i' || num == 'o' || num == 'u'){
        return true;
    }
    return false;
}

string generarRomanos(int num){
    if(num <=-1 || num >=100){
        return "Numero fuera de rango.";
    }

    string resultado {" "}; //Inicializo en 0

    vector<string> unidades {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    vector<string> decenas {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};

    int decenasDigito = num/10;
    int unidadesDigito = num%10;

    resultado = decenas.at(decenasDigito) + unidades.at(unidadesDigito);

    return resultado;

}

int main(){
    int opcion, numero1, numero2;
    string numRomano;
    DatosCifra datosCifra;
    DatosVocales datosVocales;

    do{
        cout<<"Seleccione una opcion: "<<endl;

        cout<<"1. Conversor de numeros arabigos a numeros romanos."<<endl;
        cout<<"2. Determinar las cifras de un numero."<<endl;
        cout<<"3. Determiar numero de vocales."<<endl;
        cout<<"4. Salir del programa."<<endl;
        cin>>opcion;


        switch(opcion){
        case 1:{
            int decenas;
            cout<<"Introduce un numero entero positivo (entre 0-99): "<<endl;
            cin>>numero1;

            numRomano = generarRomanos(numero1);

            if(numRomano != "Numero fuera de rango."){
                cout<<"El numero en numero romanos es "<<numRomano<<endl;
            }else{
                cout<<"Numero fuera de rango."<<endl;
            }
            cout<<"---------------------------"<<endl;

            break;
        }
        case 2:{
            vector<int> ordenNum;
            cout<<"Introduce un numero entero positivo: "<<endl;
            cin>>numero2;

            int temp = numero2;
            while (temp > 0) {
                int digito = temp % 10;
                ordenNum.push_back(digito);
                temp /= 10;
            }

            datosCifra.cifraMayor = buscarMayor(ordenNum);
            datosCifra.cifraMenor = buscarMenor(ordenNum);
            datosCifra.totalDeCifras = ordenNum.size();

            //Mostrar resultados
            cout<<"El numero mas grande del digito introducido es el "<<datosCifra.cifraMayor<<endl;
            cout<<"El numero mas pequeño del digito introducido es el "<<datosCifra.cifraMenor<<endl;
            cout<<"El numero introducido tiene "<<datosCifra.totalDeCifras<<" digitos"<<endl;

            cout<<"---------------------------"<<endl;

            break;
        }
        case 3:{
            //Inicializo contadores
            datosVocales.totalA = 0;
            datosVocales.totalE = 0;
            datosVocales.totalI = 0;
            datosVocales.totalO = 0;
            datosVocales.totalU = 0;

            char n;
            cout<<"Introduce las vocales en minusculas que quieras: "<<endl;

            while (cin >> n && vocalCheck(n)) {
                if (n == 'a') {
                    datosVocales.totalA++;
                } else if (n == 'e') {
                    datosVocales.totalE++;
                } else if (n == 'i') {
                    datosVocales.totalI++;
                } else if (n == 'o') {
                    datosVocales.totalO++;
                } else if (n == 'u') {
                    datosVocales.totalU++;
                }
            }


            //Mostrar datos
            cout<<"La vocal (a) aparece "<<datosVocales.totalA<<endl;
            cout<<"La vocal (e) aparece "<<datosVocales.totalE<<endl;
            cout<<"La vocal (i) aparece "<<datosVocales.totalI<<endl;
            cout<<"La vocal (o) aparece "<<datosVocales.totalO<<endl;
            cout<<"La vocal (u) aparece "<<datosVocales.totalU<<endl;

            cout<<"---------------------------"<<endl;

            break;
        }
        case 4:{
            cout<<"Gracias y hasta pronto."<<endl;
            break;
        }
        default:
            cout<<"La opcion no es valida. Por favor, vuelva a seleccionar otra opcion."<<endl;
        }

    }while(opcion != 4);

    return 0;
}
