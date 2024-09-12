/*
    Recopilación de funciones que incluyen lectura, generación y muestra por pantalla de
    vectores y matrices, además de los ejercicios 35, 37, 38 y 39 de la relación de problemas.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

#define Mcolum 100
#define Mvector 1000
#define MAX 101

using namespace std;

void introduce_vector (int V[],int n);
void introduce_matriz (double m[][Mcolum], int n, int j);

void genera_vector (int V[],int n);
void genera_matriz (double m[][Mcolum], int nfil, int ncol);

void muestra_vector (int V[],int n);
void muestra_matriz (int m[][Mcolum], int nfil, int ncol);

void Ejercicio35 (double V[], int n, double & varianza, double & media);
double Ejercicio39 (double V[], double W[],int n);
void Ejercicio37 (double m1[][Mcolum], double m2[][Mcolum], double m3[][Mcolum], int nfil, int ncol);
void Ejercicio38 (double m1[][Mcolum], double m2[][Mcolum], double m3[][Mcolum], int nfil1, int ncol1, int ncol2);

void potencia_polinomios (int Vector[], int grado, int potencia, int Matriz[][MAX-1]);



int main ()
{
    int V[MAX-1],A[MAX-1][MAX-1];
    introduce_vector(V,5);
    potencia_polinomios(V,4,3,A);
    muestra_matriz(A,4,13);
    return 0;
}





/* ******************************************************************************************************* */
// Función que calcula la media y la varianza de n valores y devuelve los resultados por referencia.
// Toma: los valores en un vector, el número de valores y dos variables para almacenar los resultados.
// Devuelve: la media y la varianza.
/* ******************************************************************************************************* */

void Ejercicio35 (double V[], int n, double & varianza, double & media)
{
    //Declaración de variables
    int i;

    //Cálculo media
    media = 0;
    for (i=0; i<n ; i++)
        media = media + V[i];
    media = media/n;

    //Cálculo varianza
    varianza = 0;
    for (i=0; i<n ; i++)
        varianza = (V[i]-media)*(V[i]-media);
    varianza = varianza/n;

    return ;
}




/* ******************************************************************************************************* */
// Función que calcula el producto escalar de dos vectores.
// Toma: los dos vectores y el número de elementos de los dos.
// Devuelve: su producto escalar.
/* ******************************************************************************************************* */

double Ejercicio39 (double V[], double W[],int n)
{
    //Declarción de variables
    int i;
    double resultado = 0;

    //Cálculos
    for (i=0; i<n; i++)
        resultado = resultado + V[i]*W[i];
    return resultado;

}




/* ******************************************************************************************************* */
// Función que calcula la suma de dos matrices.
// Toma: las dos matrices a las que calcular la suma y sus dimensiones.
// Devuelve: el resultado en otra matriz.
/* ******************************************************************************************************* */

void Ejercicio37 (double m1[][Mcolum], double m2[][Mcolum], double m3[][Mcolum], int nfil, int ncol)
{
    //Declaración de variables
    int i, j;

    //Cálculos
    for(i=0; i<nfil ; i++)
        for(j=0; j<ncol ;j++)
            m3[i][j] = m1[i][j] + m2[i][j];
    return;
}




/* ******************************************************************************************************* */
// Función que calcula el producto de dos matrices.
// Toma: dos matrices, el número de filas y columnas de la primera y las columnas de la segunda.
// Devuelve: su producto en una tercera matriz.
/* ******************************************************************************************************* */

void Ejercicio38 (double m1[][Mcolum], double m2[][Mcolum], double m3[][Mcolum], int nfil1, int ncol1, int ncol2)
{
    //Declaración de variables
    int i, j, k;
    double suma;

    //Recorre las filas de la primera matriz
    for(i=0; i<nfil1 ; i++)
        {
            //Recorre las columnas de la segunda matriz
            for(j=0; j<ncol2 ; j++)
            {
                //Recorre los elementos de la fila y coumna correspondiente
                suma = 0;
                for (k=0; k<ncol1 ; k++)
                    suma = suma + m1[i][k]*m2[k][j];
                m3[i][j] = suma;
            }
        }
    return;
}




/* ******************************************************************************************************* */
// Función que permite introducir por teclado un vector de n téminos de forma cómoda
// Toma: el vector y su númerp de terminos.
// Devuelve: -
/* ******************************************************************************************************* */

void introduce_vector (int V[],int n)
{
    //Declaración de variables.
    int i;

    //Ciclo para introducir cada término
    for(i=0; i<n ; i++)
    {
        cout << "Introduce el termino " << i << ": ";
        cin >> V[i] ;
    }
    cout << endl;
    return;
}




/* ******************************************************************************************************* */
// Función que permite introducir por teclado una matriz de forma cómoda.
// Toma: la matriz, su número de filas y columnas y cada término.
// Devuelve: -
/* ******************************************************************************************************* */

void introduce_matriz (double m[][Mcolum], int nfil, int ncol)
{
    //Declaración de variables
    int i, j;

    //Ciclo para introducir cada término
    for(i=0; i<nfil ; i++)
    {
        cout << endl;
        for(j=0; j<ncol ;j++)
        {
            cout << "Introduce el termino " << i << ", " << j << ": ";
            cin >> m[i][j] ;
        }
    }
    cout << endl;
    return;
}




/* ******************************************************************************************************* */
// Función que rellena un vector de n términos con valores aleatorios a partir de la función rand.
// Toma: el vector y el número de términos.
// Devuelve: el vector con valores aleatorios.
/* ******************************************************************************************************* */

void genera_vector (int V[],int n)
{
    //Declaración de variables
    int i;

    //Inicialización de rand
    srand(time(NULL));

    //Ciclo para rellenar el vector
    for(i=0; i<n ; i++)
        V[i] = rand()%10;
    return;
}




/* ******************************************************************************************************* */
// Función que rellena una mariz con valores aleatorios a partir de la función rand
// Toma: la matriz, su número de filas y de columnas
// Devuelve: la matriz rellena de valores aleatorios
/* ******************************************************************************************************* */

void genera_matriz (int m[][Mcolum], int nfil, int ncol)
{
    //Declaración de variables
    int i, j;

    //Inicialización de rand
    srand(time(NULL));

    //Ciclo para mostrar la matriz
    for(i=0; i<nfil ; i++)
        for(j=0; j<ncol ;j++)
            m[i][j] = rand()%10;
    return;
}




/* ******************************************************************************************************* */
// Función que muestra por pantalla un vector dado.
// Toma: el vector y su número de términos.
// Devuelve: -
/* ******************************************************************************************************* */

void muestra_vector (int V[],int n)
{
    //Declaración de variables
    int i;

    //Ciclo para mostrar el vector
    for(i=0; i<n ; i++){
        cout << V[i] << " ";
        if (i%5==0) cout << endl;
        }
    return;
}




/* ******************************************************************************************************* */
// Función que muestra por pantalla una matriz dada
// Toma: la matriz, su número de filas y de columnas
// Devuelve: -
/* ******************************************************************************************************* */

void muestra_matriz (int m[][Mcolum], int nfil, int ncol)
{
    //Declaración de variables
    int i, j;

    //Ciclo para mostrar la matriz
    for(i=0; i<nfil ; i++)
        {
            cout << left << setw(3) << "(";
            for(j=0; j<ncol ;j++)
                cout << setw(8) << left << m[i][j];
            cout << ")" << endl;
        }
    cout << endl << endl;
    return;
}

void potencia_polinomios (int Vector[], int grado, int potencia, int Matriz[][100])
{
    //Declaración de variables
    int i,j,k,N=0;

    //Inicializamos la matriz como un 1 en 1,1 y el resto de esa fila 0
    Matriz[0][0] = 1;
    for (i=1; i<MAX; i++)
        Matriz[0][i] = 0;


    //Ciclo para calcular la potencia
    for (k=0; k<=potencia; k++)
        {
            for (j=0; j<=grado ; j++)
                for (i=0; i<=N; i++)
                    Matriz[k+1][i+j] = Matriz[k+1][i+j] + Matriz[k][i] * Vector[j];
            N = N + grado;
        }
}
