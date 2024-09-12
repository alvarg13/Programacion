//Programa que calcula el valor de la raiz cuadrada de un n�mero de forma aproximada
//utilizando una funci�n llamada calculaRaiz. Como variables empleamos n, como n�mero
//de itiraciones a realizar por la funcion, x el n�mero al que se le calcula la raiz
//y resultado, para mostrar el valor por pantalla


#include <iostream>
#include <iomanip>
#include <cmath>

double calculaRaiz (double x, int n);

using namespace std;

int main ()
{
    //Declaraci�n de variables
    int n, i;
    double x, resultado;

    //Recopilaci�n de datos
    cout << "Introduce el valor de n: ";
    cin >> n ;
    cout << "Introduce el valor del numero al que calcular la raiz cuadrada: ";
    cin >> x ;


    //Calculos
    i = 2;
    while (i<n)
    {
        resultado = calculaRaiz(x,i);
        cout << endl << "El valor aproximado de la raiz de " << i << " es: " << fixed << setprecision(10) << resultado << endl ;
        i = i + 2;
    }

    //Mostrar resultados
    cout << endl << "El valor aproximado de la raiz de " << x << " es: " << fixed << setprecision(15) << resultado << endl ;

    return 0;
}

/* ****************************************************************************/
/* Funci�n calculaRaiz: calcula el valor de la raiz cuadrada aproximadamente  */
/* Par�metros: n, x                                                           */
/* Devuelve: el valor de la raiz cuadrada de x                                */
/* ****************************************************************************/

double calculaRaiz(double x, int n)
{
    int i;
    double sum, termino, prod;
    sum = 1;
    termino = 0.5 * log(x);
    prod = 1;

    for (i=1; i<=n ; i++)
    {
        prod = prod * termino / i;
        sum = sum + prod;
    }

    return sum;
}
