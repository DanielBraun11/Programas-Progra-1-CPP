//Práctica 4 Grupo 4 - Juego Conecta 4
#include <iostream>
#include <array>

using namespace std;

struct Jugador {
    string nombre;
    char ficha;
};

void inicializarTablero(array<array<char, 10>, 10>& tablero) {
    for (int i{0}; i < tablero.size(); i++) {
        for (int j{0}; j < tablero.at(i).size(); j++) {
            tablero.at(i).at(j) = ' ';
        }
    }
}

void mostrarTablero(const array<array<char, 10>, 10>& tablero) {
    for (int i = 0; i < tablero.size(); ++i) {
        for (int j = 0; j < tablero.at(i).size(); ++j) {
            cout << " | " << tablero.at(i).at(j);
        }
        cout << " |" << endl;
    }

    // Imprimir números de columna
    cout << "------------------------------------------" << endl;
    cout << "  0   1   2   3   4   5   6   7   8   9" << endl;
}

bool winCheck(const array<array<char, 10>,10>& tablero, int columna, char ficha, int fila){
    // Check horizontal
    if (columna + 3 < 10 && (tablero.at(fila).at(columna) == ficha && tablero.at(fila).at(columna + 1) == ficha && tablero.at(fila).at(columna + 2) == ficha && tablero.at(fila).at(columna + 3) == ficha)){
        return true;
    }

    // Check vertical
    if (fila + 3 < 10 && (tablero.at(fila).at(columna) == ficha && tablero.at(fila + 1).at(columna) == ficha && tablero.at(fila + 2).at(columna) == ficha && tablero.at(fila + 3).at(columna) == ficha)) {
        return true;
    }

    // Check diagonal (abajo-arriba)
    if (fila - 3 >= 0 && columna - 3 >= 0 && (tablero.at(fila).at(columna) == ficha && tablero.at(fila - 1).at(columna - 1) == ficha && tablero.at(fila - 2).at(columna - 2) == ficha && tablero.at(fila - 3).at(columna - 3) == ficha)){
        return true;
    }

    // Check diagonal (arriba-abajo)
    if (fila + 3 < 10 && columna + 3 < 10 && (tablero.at(fila).at(columna) == ficha && tablero.at(fila + 1).at(columna + 1) == ficha && tablero.at(fila + 2).at(columna + 2) == ficha && tablero.at(fila + 3).at(columna + 3) == ficha)){
        return true;
    }

    return false;
}

int colocarFicha(array<array<char, 10>, 10>& tablero, int columna, char ficha) {
    int filaElegida = -1;
    for (int fila = tablero.size() - 1; fila >= 0; --fila) {
        if (tablero.at(fila).at(columna) == ' ') {
            filaElegida = fila;
            tablero.at(fila).at(columna) = ficha;
            break;
        }
    }
    return filaElegida;
}

int main() {
    Jugador j1, j2;
    int opcion;
    array<array<char, 10>, 10> tablero;
    int c;

    bool estadoPartida;

    cout << "Introduzca su nombre jugador 1: ";
    getline(cin, j1.nombre);
    j1.ficha = 'O';

    cout << "Introduzca su nombre jugador 2: ";
    getline(cin, j2.nombre);
    j2.ficha = 'X';

    cout << endl;

    do {
        cout << "Menu de seleccion, seleccione una opcion: " << endl;
        cout << "1. Jugar partida. " << endl;
        cout << "2. Salir." << endl;
        cin >> opcion;

        switch (opcion) {
        case 1: {
            // Jugar
            inicializarTablero(tablero);
            mostrarTablero(tablero);

            estadoPartida = true;
            do {
                // Coloca jugador 1
                cin.ignore();
                cout << j1.nombre << " selecciona una columna(0-9): " << endl;
                cin >> c;
                int f1 = colocarFicha(tablero, c, j1.ficha);

                mostrarTablero(tablero);

                if (winCheck(tablero, c, j1.ficha, f1) == true) {
                    cout << j1.nombre << " has ganado!!" << endl;
                    estadoPartida = false;  // Actualiza el estado para salir del bucle

                    cout<<"--------------------------------"<<endl;
                    cout<<endl;
                    break;
                }

                // Coloca jugador 2
                cin.ignore();
                cout << j2.nombre << " selecciona una columna(0-9): " << endl;
                cin >> c;
                int f2 = colocarFicha(tablero, c, j2.ficha);

                mostrarTablero(tablero);

                if (winCheck(tablero, c, j2.ficha, f2) == true) {
                    cout << j2.nombre << " has ganado!!" << endl;
                    estadoPartida = false;  // Actualiza el estado para salir del bucle

                    cout<<"--------------------------------"<<endl;
                    cout<<endl;
                    break;
                }

                // Aquí puedes agregar más condiciones de empate si lo deseas.

            } while (estadoPartida);


            break;
        }

        case 2: {
            // Salir
            cout << "Gracias y hasta pronto." << endl;
            break;
        }

        default: {
            cout << " La opcion no es valida. Por favor, vuelva a seleccionar otra opcion. " << endl;
        }
        }
    } while (opcion != 2);

    return 0;
}
