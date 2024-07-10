//Daniel Braun Sandino
//Extraordinaria - Ejercicio 2

#include <iostream>
#include <vector>

using namespace std;

struct Menu{
    string menuCadena;
    int menuDigito;
};

struct MenuEstruct{
    string entrante;
    string primerPlato;
    string segundoPlato;
    string postre;
};

vector<MenuEstruct> getDemanda(int nComensales){
    vector<MenuEstruct> demanda;
    Menu menu;


    //Pedir menus
    for(int i{0} ; i<nComensales ; i++){
        cout<<"Introduce el menu comensal "<<i<<": "<<endl;
        cin>>menu.menuDigito;
        cin.ignore();

        menu.menuCadena = to_string(menu.menuDigito);


        //Check menu
        MenuEstruct me;
        if(menu.menuDigito < 0 || menu.menuCadena.size() != 4){
            //MenuEstruct me;
            me.entrante = "-1";
            me.primerPlato = "-1";
            me.segundoPlato = "-1";
            me.postre = "-1";

        }else{
            //MenuEstruct me;
            me.entrante = menu.menuCadena.at(0);
            me.primerPlato = menu.menuCadena.at(1);
            me.segundoPlato = menu.menuCadena.at(2);
            me.postre = menu.menuCadena.at(3);
        }

        demanda.push_back(me);

    }
    return demanda;
}


void mostrarTodosMenus(const vector<vector<MenuEstruct>> &restaurante){
    for(int i{0} ; i<restaurante.size() ; i++){
        for(int j = 0 ; j<restaurante.at(i).size() ; j++){
            cout<<"Menus de la mesa "<<i<<": "<<endl;
            cout<<"Comensal "<<j<<": "<<endl;
            cout<<"Entrante: "<<restaurante.at(i).at(j).entrante<<endl;
            cout<<"Primer plato: "<<restaurante.at(i).at(j).primerPlato<<endl;
            cout<<"Segundo plato: "<<restaurante.at(i).at(j).segundoPlato<<endl;
            cout<<"Postre: "<<restaurante.at(i).at(j).postre<<endl;
            cout<<"-------------------------------------"<<endl;
        }
        cout<<"-------------------------------------"<<endl;
        cout<<"-------------------------------------"<<endl;
    }
}

int main(){
    vector<vector<MenuEstruct>> restaurante;
    int respuesta1;
    int nComensales;

    do{
        cout<<"Desea agregar una nueva mesa(si=1, no=0): "<<endl;
        cin>>respuesta1;

        if(respuesta1 == 1){
            cout<<"Cuantos comensales sois? "<<endl;
            cin>>nComensales;

            vector<MenuEstruct> mesa = getDemanda(nComensales);
            restaurante.push_back(mesa);
        }

    }while(respuesta1 == 1);

    mostrarTodosMenus(restaurante);

    return 0;
}


