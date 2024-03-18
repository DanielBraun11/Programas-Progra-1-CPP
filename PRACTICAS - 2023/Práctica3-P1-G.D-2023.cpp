//Práctica 3 - Grupo D
//Juego --> Hundir la flota
#include <iostream>
#include <array>

using namespace std;

//Estructura para representar un barco
struct Barco{
    int columnaOrigen;
    int filaOrigen;
    int longitud;
    int vidas;
    char orientacion;
    array<array<int, 2>, 3> posiciones;
};

//Función para inicializar el tablero
void inicializarTablero(array<array<char, 7>, 7>& tablero){
    for(auto& fila : tablero){
        for(char& c : fila){
            c = '-';
        }
    }
}

//Función para mostrar el tablero actual
void mostrarTablero(const array<array<char, 7>, 7>& tablero){
    for(const auto& fila : tablero){
        for(char c : fila){
            cout<< c <<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

//Comprobar si hay colision de barcos al añadir al tablero
bool hayColision(const array<array<char, 7>, 7>& tablero, const Barco& barco){
    for(const auto& posicion : barco.posiciones){
        int fila = posicion[0];
        int columna = posicion[1];

        //Verificar si la posición está dentro del tablero
        if(fila < 0 || fila >= 7 || columna < 0 || columna >= 7){
            return true;  // Fuera del tablero, hay colisión
        }

        //Verificar si la posición está ocupada por otro barco
        if(tablero[fila][columna] == 'B'){
            return true;  //Colisión con otro barco
        }
    }

    return false;  //No hay colisión
}

//Función para colocar un barco en el tablero
void colocarBarco(array<array<char, 7>, 7>& tablero, Barco& barco){
    while(true){
        //Verificar si hay colisión antes de colocar el barco
        if(hayColision(tablero, barco)){
            cout<<"Error, colisin con otro barco. Introduce una posicion valida."<<endl;
            cout<<"Colocar barco nuevamente:"<<endl;

            cout<<"Orientacion (H para horizontal, V para vertical): ";
            cin>>barco.orientacion;

            //Horizontal
            if(barco.orientacion == 'H'){
                //Columna
                cout<<"Columna de origen (0-4): ";
                cin>>barco.columnaOrigen;

                while(barco.columnaOrigen < 0 || barco.columnaOrigen > 4){
                    cout<<"Columna no valida, introduce de nuevo."<<endl;
                    cout<<"Columna de origen (0-4): ";
                    cin>>barco.columnaOrigen;
                }

                //Fila
                cout << "Fila de origen (0-6): ";
                cin >> barco.filaOrigen;

                while(barco.filaOrigen < 0 || barco.filaOrigen > 6){
                    cout<<"Fila no valida, introduce de nuevo."<<endl;
                    cout << "Fila de origen (0-6): ";
                    cin >> barco.filaOrigen;
                }

                barco.vidas = 3;
                barco.longitud = 3;
            }

            //Vertical
            if(barco.orientacion == 'V'){
                //Columna
                cout<<"Columna de origen (0-6): "<<endl;
                cin>>barco.columnaOrigen;

                while(barco.columnaOrigen < 0 || barco.columnaOrigen > 6){
                    cout<<"Columna no valida, introduce de nuevo."<<endl;
                    cout<<"Columna de origen (0-6): ";
                    cin>>barco.columnaOrigen;
                }

                //Fila
                cout<<"Fila de origen (0-4): "<<endl;
                cin>>barco.filaOrigen;

                while(barco.filaOrigen < 0 || barco.filaOrigen > 4){
                    cout<<"Fila no valida, introduce de nuevo."<<endl;
                    cout << "Fila de origen (0-4): ";
                    cin >> barco.filaOrigen;
                }

                barco.vidas = 3;
                barco.longitud = 3;


            }


            for (int j = 0; j < barco.longitud; ++j) {
                if (barco.orientacion == 'H') {
                    barco.posiciones[j] = { barco.filaOrigen, barco.columnaOrigen + j };
                } else {
                    barco.posiciones[j] = { barco.filaOrigen + j, barco.columnaOrigen };
                }
            }
        } else {
            // Iterar sobre las posiciones del barco y actualizar el tablero
            for (const auto& posicion : barco.posiciones) {
                int fila = posicion[0];
                int columna = posicion[1];

                tablero[fila][columna] = 'B';
            }

            // Salir del bucle si no hay colisión
            break;
        }
    }
}


// Función para verificar si un disparo es válido y actualizar el tablero
bool realizarDisparo(array<array<char, 7>, 7>& tableroAdivinar, Barco barcos[], int fila, int columna){
    if(tableroAdivinar[fila][columna] != '-'){  //Disparo invalido porque repite tiro
        // Disparo inválido
        return false;
    }

    for(int i{0} ; i<4 ; ++i){
        for(const auto& posicion : barcos[i].posiciones){
            if(posicion[0] == fila && posicion[1] == columna){
                //Barco tocado
                tableroAdivinar[fila][columna] = 'X';
                barcos[i].vidas--;

                if (barcos[i].vidas == 0) {
                    cout << "¡Barco hundido!" << endl;
                }

                return true;
            }
        }
    }

    //Agua
    tableroAdivinar[fila][columna] = '-';
    cout << "Agua..." << endl;
    return false;
}

int main(){
    array<array<char, 7>, 7> tableroBarcos;
    array<array<char, 7>, 7> tableroAdivinar;
    Barco barcos[4];
    int intentos = 10;

    //Fase de creación del tablero
    inicializarTablero(tableroBarcos);
    inicializarTablero(tableroAdivinar);

    for(int i = 0; i < 4; ++i){
        cout<<"Colocar barco "<<i + 1<<endl;

        cout<<"Orientacion (H para horizontal, V para vertical): ";
        cin>>barcos[i].orientacion;

        while(barcos[i].orientacion != 'H' && barcos[i].orientacion != 'V'){
            cout<<"Orientacion NO valida."<<endl;
            cout<<"Orientacion (H para horizontal, V para vertical): ";
            cin>>barcos[i].orientacion;
        }

        //Horizontal
        if(barcos[i].orientacion == 'H'){
            //Columna
            cout << "Columna de origen (0-4): ";
            cin >> barcos[i].columnaOrigen;
            while(barcos[i].columnaOrigen < 0 || barcos[i].columnaOrigen > 4){
                cout<<"Fuera de rango."<<endl;
                cout << "Columna de origen (0-4): ";
                cin >> barcos[i].columnaOrigen;
            }
            //Fila
            cout << "Fila de origen (0-6): ";
            cin >> barcos[i].filaOrigen;
            while(barcos[i].filaOrigen < 0 || barcos[i].filaOrigen > 6){
                cout<<"Fuera de rango."<<endl;
                cout << "Fila de origen (0-6): ";
                cin >> barcos[i].filaOrigen;
            }
        }

        //Vertial
        if(barcos[i].orientacion == 'V'){
            //Columna
            cout << "Columna de origen (0-6): ";
            cin >> barcos[i].columnaOrigen;
            while(barcos[i].columnaOrigen < 0 || barcos[i].columnaOrigen > 6){
                cout<<"Fuera de rango."<<endl;
                cout << "Columna de origen (0-6): ";
                cin >> barcos[i].columnaOrigen;
            }
            //Fila
            cout << "Fila de origen (0-4): ";
            cin >> barcos[i].filaOrigen;
            while(barcos[i].filaOrigen < 0 || barcos[i].filaOrigen > 4){
                cout<<"Fuera de rango."<<endl;
                cout << "Fila de origen (0-4): ";
                cin >> barcos[i].filaOrigen;
            }
        }

        barcos[i].vidas = 3;
        barcos[i].longitud = 3;

        //Rellenar la matriz posiciones del barco
        for(int j = 0 ; j < barcos[i].longitud ; ++j){
            if(barcos[i].orientacion == 'H'){
                barcos[i].posiciones[j] = {barcos[i].filaOrigen, barcos[i].columnaOrigen + j};
            }else{
                barcos[i].posiciones[j] = {barcos[i].filaOrigen + j, barcos[i].columnaOrigen};
            }
        }

        colocarBarco(tableroBarcos, barcos[i]);
        mostrarTablero(tableroBarcos);
    }

    // Fase de juego
    while(intentos > 0){
        mostrarTablero(tableroAdivinar);


        int fila, columna;
        cout<<"Realizar disparo"<<endl;

        cout<<"Fila (0-6): ";
        cin >> fila;

        cout<<"Columna (0-6): ";
        cin>>columna;

        if(realizarDisparo(tableroAdivinar, barcos, fila, columna) == true){
            if(barcos[0].vidas == 0 && barcos[1].vidas == 0 && barcos[2].vidas == 0 && barcos[3].vidas == 0){
                cout<<" Has ganado! Todos los barcos hundidos."<<endl;
                    break;
            }
        }else{
            cout<<"Disparo fallido." <<endl;
            intentos--;
            cout<<"Te quedan "<<intentos<<" intentos."<<endl;
        }

    }

    if(intentos == 0){
        cout<<"Has perdido! Te quedaste sin intentos."<<endl;
    }

    return 0;
}
