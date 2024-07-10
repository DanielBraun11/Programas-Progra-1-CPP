//Daniel Braun Sandino
//Extraordinaria - Ejercicio 1

#include <iostream>
#include <vector>
#include <array>

using namespace std;

struct getDatosCadenas{
    int nPalabrasLargas;
    int nVecesLetra{0};
};

struct Alumno{
    string nombre;
    array<int,5> notas;
};

struct datosAlumno{
    int notaMasBaja;
    int notaMasAlta;
    float media;
};


//Funcion A
int getTotalPares(const vector<int> &enteros){
    int contador{0};

    for(int a : enteros){
        if(a % 2 == 0){
            contador++;
        }
    }

    return contador;
}

//Funcion B
getDatosCadenas recogerDatos(const vector<string> &cadenas, int numero, char caracter){
    getDatosCadenas datos;

    for(const string &palabra : cadenas){
        if(palabra.size() > numero){
            datos.nPalabrasLargas++;
        }
    }

    for(const string &palabra : cadenas){
        for(char letra : palabra){
            if(letra == caracter){
                datos.nVecesLetra++;
            }
        }
    }

    return datos;
}

//Mostrar datos optenidos de la Funcion B
void mostrarDatos(const getDatosCadenas &datos, int numero, char caracter){
    cout<<"Datos: "<<endl;
    cout<<"Total de palabras con tamanio mayor a "<<numero<<": "<<datos.nPalabrasLargas<<endl;
    cout<<"Total de veces que aparece ("<<caracter<<") en las palabras: "<<datos.nVecesLetra<<endl;
    cout<<"------------------------------"<<endl;
}

//Funcion C
datosAlumno recogerDatosAlumno(const vector<Alumno> &alumnos){
    datosAlumno datos;

        //Nota mas baja
        for(int i{0} ; i<alumnos.size() ; i++){
            datos.notaMasBaja = alumnos.at(i).notas.at(0);
            if(alumnos.at(i).notas.at(i+1) > datos.notaMasBaja){
                datos.notaMasBaja = alumnos.at(i).notas.at(i+1);
            }
        }

        //Nota mas alta
        for(int i{0} ; i<alumnos.size() ; i++){
            datos.notaMasAlta = alumnos.at(i).notas.at(0);
            if(alumnos.at(i).notas.at(i+1) < datos.notaMasAlta){
                datos.notaMasAlta = alumnos.at(i).notas.at(i+1);
            }
        }

        //Nota media
        array<int,5> notas = alumnos.at(0).notas;
        int suma{0};
        for(int i = 0 ; i<notas.size() ; i++){
            suma += notas.at(i);
        }
        datos.media = suma / notas.size();

    return datos;

}

//Mostrar datos optenidos de la Funcion C
void mostrarDatosAlumno(const datosAlumno &datoAlumno){
    cout<<"datos del alumno: "<<endl;
    cout<<"Nota mas baja: "<<datoAlumno.notaMasBaja<<endl;
    cout<<"Nota mas alta: "<<datoAlumno.notaMasAlta<<endl;
    cout<<"Media: "<<datoAlumno.media<<endl;
    cout<<"------------------------------"<<endl;

}

int main(){

    //Funcion A
    vector<int> enteros{1,8,32,33,11,99,45,6}; //pares: 8,32,6 ->Total:3
    int totalPares = getTotalPares(enteros);
    cout<<"El vector tiene "<<totalPares<<" numeros pares."<<endl;
    cout<<"------------------------------"<<endl;

    //Funcion B
    vector<string> cadenas{"playa", "verano", "eurocopa","helados"};
    int numero = 6;
    char caracter{'e'};
    getDatosCadenas datos = recogerDatos(cadenas,numero,caracter);
    mostrarDatos(datos,numero,caracter);

    //Funcion C
    vector<Alumno> alumnos;
    vector<datosAlumno> datosAl;
    Alumno alumno1 = {"Daniel",{5,8,4,7,6}}; //creo un alumno
    Alumno alumno2 = {"Diego",{6,8,10,9,6}}; //creo un alumno
    alumnos.push_back(alumno1); //agrego el alumno al vector
    alumnos.push_back(alumno2); //agrego el alumno al vector
    datosAlumno datoAlumno = recogerDatosAlumno(alumnos);
    mostrarDatosAlumno(datoAlumno);

    //Funcion D



    return 0;
}
