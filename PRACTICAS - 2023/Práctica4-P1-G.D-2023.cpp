//Práctica 4 - Grupo D
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

using namespace std;

const int filas = 4;
const int columnas = 4;

struct Carta {
    int valorCarta;
    bool descubierta;
};

void mostrarTablero(array<array<Carta, columnas>, filas>& tablero){
    for(int i = 0; i < filas; ++i){
        cout << "|";
        for(int j = 0; j < columnas; ++j){
            if(tablero.at(i).at(j).descubierta){
                cout << " " << tablero.at(i).at(j).valorCarta << " |";
            }else{
                cout << " * |";
            }
        }
        cout<<endl;

        if(i < filas - 1){
            cout<< "-------------------"<<endl;
        }
    }
}

void inicializarTablero(array<array<Carta, columnas>, filas>& tablero) {
    srand(static_cast<unsigned int>(time(nullptr)));

    array<int,(filas * columnas)> numeros;

    // Inicializar el arreglo con parejas de números
    for (int i = 0; i < filas * columnas; ++i) {
        numeros.at(i) = (i / 2) + 1;
    }

    // Barajar los números utilizando el algoritmo de Fisher-Yates
    for (int i = filas * columnas - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(numeros.at(i), numeros.at(j));
    }

    // Asignar los números al tablero
    int contador = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            tablero.at(i).at(j).valorCarta = numeros.at(contador);
            tablero.at(i).at(j).descubierta = false; // Todas las cartas inicialmente no descubiertas
            ++contador;
        }
    }
}

void jugarTurno(array<array<Carta, columnas>, filas>& tablero) {
    int fila1, col1, fila2, col2;

    // Primer carta
    cout<<"Seleccione la primera carta (fila columna): "<<endl;
    cin>>fila1;
    cin>>col1;

    // Verificar si la carta ya ha sido descubierta
    while (tablero.at(fila1).at(col1).descubierta) {
        cout<<"¡Error! La carta seleccionada ya ha sido descubierta. Seleccione otra carta: ";
        cin>>fila1;
        cin>>col1;
    }

    tablero.at(fila1).at(col1).descubierta = true;
    mostrarTablero(tablero);

    // Segunda carta
    cout<<"Seleccione la segunda carta (fila columna): "<<endl;;
    cin>>fila2;
    cin>>col2;

    // Verificar si la carta ya ha sido descubierta
    while(tablero.at(fila2).at(col2).descubierta){
        cout << "Error! La carta seleccionada ya ha sido descubierta. Seleccione otra carta: "<<endl;
        cin>>fila2;
        cin>>col2;
    }

    tablero.at(fila2).at(col2).descubierta = true;
    mostrarTablero(tablero);

    // Verificar si las cartas coinciden
    if(tablero.at(fila1).at(col1).valorCarta == tablero.at(fila2).at(col2).valorCarta){
        cout<<"¡Coincidencia! Las cartas coinciden."<<endl;
    }else{
        cout<<"No hay coincidencia. Volviendo a ocultar las cartas."<<endl;
        tablero.at(fila1).at(col1).descubierta = false;
        tablero.at(fila2).at(col2).descubierta = false;
    }
}


bool tableroCompleto(array<array<Carta, columnas>, filas>& tablero){
    for(int i{0} ; i<filas; i++){
        for(int j{0}; j<columnas ; j++){
            if(tablero.at(i).at(j).descubierta == false){
                return false;
            }
        }
    }
    return true;
}

int main(){
    array<array<Carta, columnas>, filas> tablero;

    inicializarTablero(tablero);
    mostrarTablero(tablero);

    do{
        jugarTurno(tablero);

    }while(tableroCompleto(tablero) == false);

    cout<<"Ganador!! Todas las parejas encontradas."<<endl;

    return 0;
}
