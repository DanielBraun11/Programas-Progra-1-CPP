/* Implementar un programa en C++11 que muestre por terminal el alfabeto castellano.
 * Recuerda que la implementación debe ser algorítmica para no penalizar la calificación
 * al 0% según los criterios generales de evaluación
 */
#include <iostream>
using namespace std;

int main() {
    char letra = 'a'; // Inicializo la letra en 'a'

    while (letra<='z') {
        cout<<letra<<" ";
        letra++;
    }

    return 0;
}
