//Programa que calcula el valor de PI de forma aproximada utilizando una funci�n llamada calculaPI
//Como variables empleamos n, como n�mero de itiraciones a realizar por la funcion y PI, que recibe el resultado


#include <iostream>
#include <iomanip>

double calculaPI (int n);

using namespace std;

int main ()
{
    //Declaraci�n de variables
    int n;
    double PI;

    //Recopilaci�n de datos
    cout << "Introduce el valor de n: ";
    cin >> n ;

    //Calculos
    PI = calculaPI(n);

    //Mostrar resultados
    cout << endl << fixed << setprecision(15) << "El valor aproximado de PI es: " << PI << endl ;

    return 0;
}

/* ************************************************************/
/* Funci�n calculaPI: calcula el valor de PI aproximadamente  */
/* Par�metros: n                                              */
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

