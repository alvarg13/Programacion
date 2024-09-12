/*  Programa para calcular el logaritmo de un número dado, siendo
    la base introducida por teclado de la misma forma.
    Entradas: base (base), número (numero).
    Salida: el valor del logaritmo (logaritmo).
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(void)
{
    //Declaración de variables.
    double numero, base, logaritmo;

    //Explicación.
    cout << "Este programa calcula el logaritmo para cierta base de un numero dado." << endl << endl ;

    //Recopilacion de datos.
    cout << "Introduzca la base: ";
    cin >> base;
    cout << "Introduzca el numero al que calcular el logaritmo: ";
    cin >> numero;

    //Calcular el logaritmo.
    logaritmo = log (numero) / log (base);

    //Mostrar el resultado.
    cout << endl << "Es valor del logaritmo es " << setfill('.') << setw(43) << setprecision(5) << scientific << logaritmo << endl;

    system("pause");
    return 0;
}
