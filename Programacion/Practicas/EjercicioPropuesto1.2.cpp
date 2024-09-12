/*  Programa para calcular la suma, resta, producto entero, cociente entero y resto entero dados dos números enteros a,b.
    Entradas: las variables a y b (a,b).
    Salida: la suma, resta, producto entero, cociente entero y resto entero (suma, resta, producto, cociente, resto).
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
    //Declaración de variables.
    int num1, num2;
    int suma, resta, producto, cociente, resto;

    //Explicación.
    cout << "Este programa calcula la suma, la resta, el producto, " << endl ;
    cout << "el cociente entero y su resto de dos numeros dados."    << endl << endl ;

    //Pedir el valor de las variables.
    cout << "Introduzca el valor del primer parametro: ";
    cin >> num1;
    cout << "Introduzca el valor del segundo parametro: ";
    cin >> num2;

    //Calculos.
        suma = num1 + num2;

        resta = num1 - num2;

        producto = num1 * num2;

        cociente = num1 / num2;

        resto = num1 % num2;

    //Mostrar el resultado
    cout << endl << "La suma es: " << suma << endl;
    cout <<"Su diferencia es: " << resta << endl;
    cout <<"Su producto es: " << producto << endl;
    cout <<"El cociente es: " << cociente << endl;
    cout <<"El resto es: " << resto << endl << endl;

    system("pause");
    return 0;
}
