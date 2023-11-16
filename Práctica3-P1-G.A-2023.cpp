#include <iostream>
#include <array>
#include <string>
using namespace std;


int main() {
    int opcion;
    array<array<string, 2>, 10> matriz;  // 10 filas x 2 columnas
    string frase;


    // Variables para la matriz de letras
    array<array<string, 2>, 5> matrizLetras; // 5 filas x 2 columnas


    // Menu de selección
    do{
        cout<<"Seleccione una opcion (1-4): "<<endl;
        cout<<"1. Matriz de frases"<<endl;
        cout<<"2. Informacion de letra"<<endl;
        cout<<"3. Informacion de palabras"<<endl;
        cout<<"4. Salir del programa"<<endl;
        cin>>opcion;

        if(opcion < 1 || opcion > 4){
            cout<<"La opcion no es valida. Por favor, vuelva a seleccionar otra opcion."<<endl;
        }

        switch(opcion){
        // Matriz de frases
        case 1:
            cout<<"Introduce 10 frases:"<<endl;
            cin.ignore();

            // Rellenar matriz
            for(int fila{0}; fila < matriz.size(); fila++){
                cout << "Frase " << fila + 1 << ": " << endl;
                getline(cin, matriz.at(fila).at(0));
                matriz.at(fila).at(1) = to_string(matriz.at(fila).at(0).size());
            }

            // Mostrar matriz
            cout<<"---------------------------"<<endl;
            for(int i{0}; i < matriz.size(); i++){
                cout << matriz.at(i).at(0)<<" ------TAMANO----->>"<<matriz.at(i).at(1)<<endl;
            }
            cout<<"---------------------------"<<endl;
            cout<<endl;
            break;

            // Informacion de letra
        case 2:
            if(matriz.at(0).at(0).empty()){
                cout << "La matriz de frases no se ha rellenado."<<endl;
            }else{
                cout<<"Introduce 5 letras (en minusculas):"<<endl;
                cin.ignore();

            //Relleno las letras de la matriz
            for(int z{0} ; z<5 ; z++){
                getline(cin,matrizLetras.at(z).at(0));
            }







            }
            break;


        }
    }while(opcion != 4);

    return 0;
}

