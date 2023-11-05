//Ejercicio 1: Calculadora geométrica y más.
#include <iostream>
#include<math.h>

using namespace std;

struct figura{
    double radio;
    double diametro;
    double area;
    double perimetro;
    double lado1, lado2, lado3;
    int nLados;
    int altura;

};


int main(){
    int num;
    int opcion1;
    double pi{3.14};
    figura circulo;
    figura triangulo;
    figura cuadrado;
    figura rectangulo;
    figura poligonoReg;
    bool salida = false;


while(salida == false){
    cout<<"Menu: "<<endl;
    cout<<"Seleccione 1 para usar circulo: "<<endl;
    cout<<"Seleccione 2 para usar triangulo: "<<endl;
    cout<<"Seleccione 3 para usar cuadrado: "<<endl;
    cout<<"Seleccione 4 para usar rectangulo: "<<endl;
    cout<<"Seleccione 5 para usar poligono regular: "<<endl;
    cout<<"Seleccione 6 para salir."<<endl;

    cin>>num;
    switch(num){
        //CIRCULO
        case 1:
        cout<<"Seleccione 1 para introducir radio o 2 para introducir diametro: "<<endl;
        cin>>opcion1;
            switch(opcion1){
                case 1:
                cout<<"Radio: "<<endl;
                cin>>circulo.radio;
                circulo.diametro = circulo.radio * 2;
                break;

                case 2:
                cout<<"Diametro: "<<endl;
                cin>>circulo.diametro;
                circulo.radio = circulo.diametro/2;
                break;

                default:
                cout<<"Error, ni 1 ni 2."<<endl;
            }

        //Operaciones
        circulo.area = pi * pow(circulo.radio, 2);

        cout<<"EL area del circulo es: "<<circulo.area<<endl;


        circulo.perimetro =  2 * pi * circulo.radio;

        cout<<"EL perimetro del circulo es: "<<circulo.perimetro<<endl;

        break;

        //TRIANGULO
        case 2:
        cout<<"Introduzca lado 1 del triangulo: "<<endl;
        cin>>triangulo.lado1;
        cout<<"Introduzca lado 2 del triangulo: "<<endl;
        cin>>triangulo.lado2;
        cout<<"Introduzca lado 3 del triangulo: "<<endl;
        cin>>triangulo.lado3;

        while(triangulo.lado1 + triangulo.lado2 <= triangulo.lado3 or triangulo.lado1 + triangulo.lado3 <= triangulo.lado2 or triangulo.lado2 + triangulo.lado3 <= triangulo.lado1){
            cout<<"Error, el triangulo no existe."<<endl;
            cout<<"Introduzca lado 1 del triangulo: "<<endl;
            cin>>triangulo.lado1;
            cout<<"Introduzca lado 2 del triangulo: "<<endl;
            cin>>triangulo.lado2;
            cout<<"Introduzca lado 3 del triangulo: "<<endl;
            cin>>triangulo.lado3;
        }

        cout<<"El traingulo existe."<<endl;
        //Area
        if((triangulo.lado1 > triangulo.lado2) and (triangulo.lado1 > triangulo.lado3)){
            triangulo.altura = sqrt(pow((triangulo.lado1/2),2)+pow(triangulo.lado2,2));
            triangulo.area = (triangulo.lado1 * triangulo.altura)/2;
        }else if((triangulo.lado2 > triangulo.lado1) and (triangulo.lado2 > triangulo.lado3)){
            triangulo.altura = sqrt(pow((triangulo.lado2/2),2)+pow(triangulo.lado2,1));
            triangulo.area = (triangulo.lado1 * triangulo.altura)/2;
        }else{
            triangulo.altura = sqrt(pow((triangulo.lado3/2),2)+pow(triangulo.lado1,1));
            triangulo.area = (triangulo.lado1 * triangulo.altura)/2;
        }

        cout<<"El area del triangulo es: "<<triangulo.area<<endl;

        //Perimetro
        triangulo.perimetro = triangulo.lado1 + triangulo.lado2 + triangulo.lado3;

        cout<<"El perimetro del traingulo es: "<<triangulo.perimetro<<endl;
        //Tipo de Triangulo
        if(triangulo.lado1 == triangulo.lado2 ==triangulo.lado3){
            cout<<"EL traingulo es equilatero"<<endl;
        }else if((triangulo.lado1 == triangulo.lado2 and triangulo.lado1 != triangulo.lado3) or (triangulo.lado2 == triangulo.lado3 and triangulo.lado2 != triangulo.lado1) or (triangulo.lado1 == triangulo.lado3 and triangulo.lado1 != triangulo.lado2)){
            cout<<"El triangulo es isosceles"<<endl;
        }else{
            cout<<"El triangulo es escaleno"<<endl;
        }

        break;

        //CUADRADO
        case 3:
        cout<<"Introducir el lado de un cuadrado: "<<endl;
        cin>>cuadrado.lado1;

        cuadrado.area = pow(cuadrado.lado1,2);
        cout<<"El area del cuadrado es: "<<cuadrado.area<<endl;

        cuadrado.perimetro = 4* cuadrado.lado1;
        cout<<"El perimetro del cuadrado es: "<<cuadrado.perimetro<<endl;

        break;

        //RECTANGULO
        case 4:
        cout<<"Introduzca la longitud: "<<endl;
        cin>>rectangulo.lado1;

        cout<<"Introduce el ancho: "<<endl;
        cin>>rectangulo.lado2;

        while(rectangulo.lado1 == rectangulo.lado2){
            cout<<"Error, es un cuadrado."<<endl;

            cout<<"Introduzca la longitud: "<<endl;
            cin>>rectangulo.lado1;

            cout<<"Introduce el ancho: "<<endl;
            cin>>rectangulo.lado2;
        }

        cout<<"Es un rectangulo."<<endl;

        rectangulo.area = rectangulo.lado1 * rectangulo.lado2;
        cout<<"El area del rectangulo es: "<<rectangulo.area<<endl;

        rectangulo.perimetro = (2 * rectangulo.lado1) + (2 * rectangulo.lado2);
        cout<<"El perimetro del rectangulo "<<rectangulo.perimetro<<endl;

        break;

        //POLIGONO REGULAR
        case 5:
        cout<<"Introduce el numero de lados del poligono regular: "<<endl;
        cin>>poligonoReg.nLados;

        cout<<"Introduce la longitud del lado: "<<endl;
        cin>>poligonoReg.lado1;

        switch(poligonoReg.nLados){
            case 1: cout<<"Poligono no valido."<<endl;
            break;
            case 2: cout<<"Poligono no valido."<<endl;
            break;
            case 3: cout<<"El poligono es un triangulo."<<endl;
                //Area
                poligonoReg.altura = sqrt(pow((poligonoReg.lado1/2),2)+pow(poligonoReg.lado1,2));
                poligonoReg.area = (poligonoReg.lado1 * poligonoReg.altura)/2;
                cout<<"El area es: "<<poligonoReg.area<<endl;
                //Perimetro
                poligonoReg.perimetro = poligonoReg.lado1 * 3;
                cout<<"El perimetro es: "<<poligonoReg.perimetro<<endl;
            break;
            case 4: cout<<"El poligono es un cuadrado."<<endl;
                //Area
                poligonoReg.area = pow(poligonoReg.lado1,2);
                cout<<"El area del cuadrado es: "<<endl;
                //Perimetro
                poligonoReg.perimetro = poligonoReg.lado1 * 4;
                cout<<"EL perimetro es: "<<poligonoReg.perimetro<<endl;
            break;
            case 5: cout<<"El poligono es un pentagono."<<endl;
                //Area
                //Perimetro
                poligonoReg.perimetro = poligonoReg.lado1 * 5;
                cout<<"EL perimetro es: "<<poligonoReg.perimetro<<endl;
            break;
            case 6: cout<<"El poligono es un hexagono."<<endl;
                //Area
                //Perimetro
                poligonoReg.perimetro = poligonoReg.lado1 * 6;
                cout<<"EL perimetro es: "<<poligonoReg.perimetro<<endl;
            break;
            case 7: cout<<"El poligono es un heptagono."<<endl;
                //Area
                //Perimetro
                poligonoReg.perimetro = poligonoReg.lado1 * 7;
                cout<<"EL perimetro es: "<<poligonoReg.perimetro<<endl;
            break;
            case 8: cout<<"El poligono es un octogono."<<endl;
                //Area
                //Perimetro
                poligonoReg.perimetro = poligonoReg.lado1 * 8;
                cout<<"EL perimetro es: "<<poligonoReg.perimetro<<endl;
            break;
            case 9: cout<<"El poligono es un nonagono."<<endl;
                //Area
                //Perimetro
                poligonoReg.perimetro = poligonoReg.lado1 * 9;
                cout<<"EL perimetro es: "<<poligonoReg.perimetro<<endl;
            break;
            default: cout<<"Limite alcanzado"<<endl;
        }
        break;

        //SALIR
        case 6:
        cout<<"Muchas Gracias."<<endl;
        salida = true;
	      break;

        default:
        cout<<"Error, introducce un numero valido, entre 1-6."<<endl;

    }
}

    return 0;
}
