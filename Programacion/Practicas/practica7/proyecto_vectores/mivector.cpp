//Funciones para trabajar con vectores enteros.
#include "mivector.hpp"

/* **********************************************/
/*      Funciones para c�lculo estad�stico      */
/* **********************************************/

//Calcula la media arigm�ica de un vector de enteros
//Recibe el vector y el n�mero de elementos

double CalcularMedia (int v[], int n)
{
    int i;
    double suma;
    suma = 0.0;
    for (i=0; i<n ; i++)
        suma = suma + v[i];

    return suma/n;
}

//Calcula la varianza de un vector de enteros
//Recibe el vector, el n�mero de elementos
//y la media ya calculada

double CalcularVarianza (int v[], int n, double media)
{
    int i;
    double suma;
    suma = 0.0;
    for (i=0 ; i<n ; i++)
        suma = suma + (media - v[i])*(media - v[i]);

    return suma/n;
}

//Calcula la desviaci�n t�pica
//Recibe el valor de la varianza
//Devuelve su ra�z cuadrada

double CalcularDesviacion (double varianza)
{
    return sqrt(varianza);
}

//Rellena un vector desde teclado
//Recibe el vector y el n�mero de elementos

void RellenaVector (int v[], int n)
{
    int i;
    for (i=0 ; i<n ; i++)
    {
        cout << "Elemento v[" << i << "] :" ;
        cin >> v[i];
    }
    return;
}

//Muestra vector en pantalla
//Recibe el vector y el n�mero de elementos

void MostrarVector (int v[], int n)
{
    int i;
    for (i=0 ; i<n ; i++)
    {
        cout << "Elemento v[" << i << "] :" << v[i] << endl ;
        //Cada 22 l�neas hago una parada
        if ((i+1)%22==0) system("pause");
    }
    return;
}

//Calcula la media geom�trica de un vector
//Recibe un vector de enteros y su n�mero de elementos
//Devuelve su media geom�trica

double CalcularMediaGeometrica (int v[],int n)
{
    int i;
    double productorio = 1;
    for (i=0; i<n ; i++)
        productorio = productorio * v[i];

    return pow(productorio,1.0/n);
}
