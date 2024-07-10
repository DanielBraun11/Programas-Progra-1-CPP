//Daniel Braun Sandino
//Extraordinaria 2023 - Turno 1
//Ejercicio 3

#include<iostream>
#include<vector>

using namespace std;

//FUNCION PARA MOSTRAR EL CONTENIDO
void mostrarDatos(vector<char> &almacen){
    for(char i : almacen){
        cout<<i;
    }
    cout<<endl;
}

//FUNCION MAXIMO NUMERO DE VALORES
int maxConsecutivos(vector<char> &almacen, int entero){
    int maxConsec;
    int contador;
    char aux = entero + '0';

    if(entero != 1 && entero !=0){
        return -1;
    }

    for(int i{0} ; i<almacen.size() ; i++){
        if(almacen.at(i) == aux ){
            contador++;
        }else{
            if(contador > maxConsec){
                maxConsec = contador;
            }
            contador = 0;
        }
    }

    return maxConsec;
}

//FUNCION PARA ROTAR LA SECUENCIA
void rotar(vector<char> &almacen, bool rotacion){
    string cadena(almacen.begin(), almacen.end());

    //derecha - true
    if(rotacion){
        cout<<cadena.back();
        cadena.pop_back();
        cout<<cadena<<endl;
    }else{ //izquierda - false
        char dato = cadena.front();
        cadena.erase(0,1);

        cout<<cadena<<dato<<endl;
    }
}

int main(){
    vector<char> almacen;
    char dato;
    bool seguir = true;
    int maxEntero;
    int op;

    //Obtener datos
    cout<<"Introduce 0s y 1s y un . para finalizar: "<<endl;
    do{
        cin>>dato;
        if(dato == '1' || dato =='0'){
            almacen.push_back(dato);
        }
        if(dato == '.'){
            seguir = false;
        }
    }while(seguir);

    //LLamada a la funcion mostrar
    mostrarDatos(almacen);

   //Llamada a la funcion que devuelve el maximo numero consecutivos
    cout<<"Introduce de que dato quieres conocer los maximos consecutivos(0/1): "<<endl;
    cin>>maxEntero;

    int consecutivos = maxConsecutivos(almacen, maxEntero);

    cout<<"La cadena maxima de "<<maxEntero<<" consecutivos es: "<<consecutivos<<endl;

    //Llamar a la funcion que devuelve la sucesion rotada hacia un lado
    cout<<"Introducza la direccion de rotacion(izq(0) / derch(1)): "<<endl;
    cin>>op;

    if(op == 0){
        rotar(almacen,false);
    }else if(op == 1){
        rotar(almacen,true);
    }else{
        cout<<"Opcion no valida"<<endl;
    }


    return 0;
}
