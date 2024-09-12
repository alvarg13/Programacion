//Programa que calcula el valor de PI de forma aproximada utilizando una función llamada calculaPI
//Como variables empleamos n, como número de itiraciones a realizar por la funcion y PI, que recibe el resultado


#include <iostream>
#include <iomanip>

double calculaPI (int n);

using namespace std;

int main ()
{
    //Declaración de variables
    int n;
    double PI;

    //Recopilación de datos
    cout << "Introduce el valor de n: ";
    cin >> n ;

    //Calculos
    PI = calculaPI(n);

    //Mostrar resultados
    cout << endl << fixed << setprecision(15) << "El valor aproximado de PI es: " << PI << endl ;

    return 0;
}

/* ************************************************************/
/* Función calculaPI: calcula el valor de PI aproximadamente  */
/* Parámetros: n                                              */
/* Devuelve: el valor de PI                                   */
/* ************************************************************/

double calculaPI(int n)
{
    int i;
    double prod;
    prod = 1;


    for (i=1; i<=n ; i=i+2)
    {
        prod = prod * (i+1) * (i+1) / (i * (i + 2));
    }

    return 2*prod;
}

