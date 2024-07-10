//Daniel Braun Sandino
//Extraordinaria 2023 - Turno 1
//Ejercicio 2

#include<iostream>
#include<set>
#include<vector>

using namespace std;

struct parejasPrimos{
    int num1;
    int num2;
};

bool esPrimo(int num){
    for(int i{2} ; i*i <=num ; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

bool sonGemelos(int p, int q){
    if((p < q) && (q - p == 2)){
        return true;
    }

    return false;
}

parejasPrimos crearPareja(int p, int q){
    parejasPrimos pP;
    pP.num1 = p;
    pP.num2 = q;

    return pP;
}

ostream &operator <<(ostream &out, parejasPrimos pP){
    out<<"["<<pP.num1<<","<<pP.num2<<"]";
}

int main(){
    set<parejasPrimos> almacen;
    vector<int> numerosPrimos;

    //Almacenar solo los primos
    for(int i{100} ; i<201 ; i++){
        if(esPrimo(i)){
            numerosPrimos.push_back(i);
        }
    }

    //Mostrar los primos
    for(int i : numerosPrimos){
        cout<<i<<", ";
    }
    cout<<endl;


    //Son gemelos? + incluir
    for(int i{0} ; i<numerosPrimos.size() - 1 ; i++){
        int p = numerosPrimos.at(i);
        int q = numerosPrimos.at(i+1);

        if(sonGemelos(p,q)){
            almacen.insert(crearPareja(p,q));  //ERROR
        }
    }

    //Mostrar los gemelos primos - con sobrecarga (NO PROBADA)
    for(parejasPrimos pareja : almacen){
        cout<<pareja<<endl;
    }


    return 0;
}



