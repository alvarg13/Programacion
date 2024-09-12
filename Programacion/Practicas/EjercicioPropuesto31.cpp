// Programa que genera tres números enteros aleatorios entre -12 y 7 y los muestra en pantalla

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main (void)
{
    int numero1, numero2, numero3, Nmayor, Nmedio, Nmenor;
    double resultado1, resultado2, resultado3;

    //Explicacion
    cout << "Este programa genera tres numeros enteros aleatorio entre -12 y 7 y los muestra ordenados en pantalla" << endl ;
    system("pause");

    //Doy inicio a rand
    srand( time(NULL) );

    //Genero tres números enteros con rand
    numero1 = rand();
    numero2 = rand();
    numero3 = rand();

    //Calculos
    resultado1 = ceil(numero1 * 19.99 / RAND_MAX ) - 12;
    resultado2 = ceil(numero2 * 19.99 / RAND_MAX ) - 12;
    resultado3 = ceil(numero3 * 19.99 / RAND_MAX ) - 12;

    //Ordenos los números
    if ((resultado1 >= resultado2) && (resultado1 >= resultado3))
    {
        Nmayor = resultado1;
        if (resultado2 >= resultado3) {Nmedio = resultado2; Nmenor = resultado3;}
        else {Nmedio = resultado3; Nmenor = resultado2;}
    }



     if ((resultado2 >= resultado1) && (resultado2 >= resultado3))
    {
        Nmayor = resultado2;
        if (resultado1 >= resultado3) {Nmedio = resultado1; Nmenor = resultado3;}
        else {Nmedio = resultado3; Nmenor = resultado1;}
    }



    else
    {
        Nmayor = resultado3;
        if (resultado1 >= resultado2) {Nmedio = resultado1; Nmenor = resultado2;}
        else {Nmedio = resultado2; Nmenor = resultado1;}
    }

    //Muestro los números ordenados
    cout << endl << "El primer numero es: " << Nmayor << endl;
    cout << "El segundo numero es: " << Nmedio << endl;
    cout << "El tercer numero es: " << Nmenor << endl;
    system("pause");
    return 0;
}
