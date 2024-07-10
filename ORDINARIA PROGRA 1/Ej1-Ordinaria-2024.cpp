//Daniel Braun Sandino
//Ejercicio 1

#include <iostream>
#include <vector>

using namespace std;

struct Elemento{
    string descripcion;
    int numRef;
};

void colocarObjeto(vector<Elemento> &almacen, const string &desc, int numRef, int cantidad){
    int nCajas{0} ;

    nCajas = cantidad/5;

    for(int i{0} ; i<nCajas ; i++){
        almacen.push_back({desc,numRef});
    }

    if(cantidad%5 != 0){
        almacen.push_back({desc,numRef});
    }

}

void mostrarAlmacen(const vector<Elemento> &almacen){
    for(int i{0} ; i<almacen.size() ; i++){
        cout<<"Caja "<<i<<": "<<endl;
        cout<<"Descripcion: "<<almacen.at(i).descripcion<<endl;
        cout<<"Numero de referencia: "<<almacen.at(i).numRef<<endl;
        cout<<endl;
    }
}

bool filtro(const string &desc, int numRef, int cantidad){
    if(desc.find("Fin captura") != -1){
        return true;
    }

    if(numRef <= 0){
        return true;
    }

    if(cantidad <= 0){
        return true;
    }

    return false;
}

int main(){
    vector<Elemento> almacen;
    bool stop{false};
    int cantidad;
    Elemento elem;

    do{
        cout<<"Introduce la descripcion del objeto: "<<endl;
        getline(cin,elem.descripcion);

        cout<<"Introduce el numero de referencia: "<<endl;
        cin>>elem.numRef;

        cout<<"Introduce la cantidad del objeto: "<<endl;
        cin>>cantidad;
        cin.ignore();

        if(filtro(elem.descripcion, elem.numRef, cantidad)){
            stop = true;
        }else{
            colocarObjeto(almacen,elem.descripcion,elem.numRef, cantidad);

            mostrarAlmacen(almacen);
        }


    }while(stop != true);



    return 0;
}
