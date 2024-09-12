#include "polinomios.hpp"
#define MAX 101

//FUNCIONES PARA EL TRABAJO CON POLINOMIOS

/* ******************************************************************************************************* */
// Funci�n que permite introducir por teclado un polinomio de grado n de forma c�moda
// Toma: un vector y su n�mero de terminos.
// Devuelve: -
/* ******************************************************************************************************* */

void introduce_polinomio (int Vector[],int grado)
{
    //Declaraci�n de variables.
    int i;

    //Ciclo para introducir cada t�rmino
    for(i=0; i<=grado ; i++)
    {
        cout << "Introduce el coeficiente de grado " << i << ": ";
        cin >> Vector[i] ;
    }
    cout << endl;
    return;
}


/* ******************************************************************************************************* */
// Funci�n que muestra por pantalla un polinomio dado.
// Toma: el polinomio y su grado.
// Devuelve: -
/* ******************************************************************************************************* */

void muestra_polinomio (int Vector[],int grado)
{
    //Declaraci�n de variables
    int i;

    //Ciclo para mostrar el polinomio
    cout << Vector[grado] << "x^" << grado << " ";
    for(i=grado-1; i > 0 ; i--)
        {
            if (Vector[i]>0) cout << "+" << Vector[i] << "x^" << i << " ";
            else if (Vector[i]==0);
            else cout << Vector[i] << "x^" << i << " ";
        }
    if (Vector[0]>0) cout << "+" << Vector[i] << endl << endl ;
    else if (Vector[i]==0) cout << endl << endl;
    else cout << Vector[i] << endl << endl;

    return;
}


/* ******************************************************************************************************* */
// Funci�n que calcula el valor de un polinomio para un x dado.
// Toma: el polinomio, su grado y un valor x.
// Devuelve: el resultado de sustituir x por el valor.
/* ******************************************************************************************************* */

double calcula_polinomio (int Vector[],int grado, double x)
{
    //Declaraci�n de variables
    int i;
    double suma = 0, producto = 1;

    //Ciclo para calcular el valor del polinomio
    for(i=0; i <= grado ; i++){
        suma = suma + Vector[i] * producto;
        producto = producto * x;
        }

    return suma;
}

/* ******************************************************************************************************* */
// Funci�n que calcula la suma de dos polinomios.
// Toma: los dos polinomios , el n�mero de elementos de cada uno y
// un tercer vector para almacenar el resultado.
// Devuelve: la suma en el tercer vector.
/* ******************************************************************************************************* */

void suma_polinomios (int Vector1[], int Vector2[], int VResultado[], int grado1, int grado2)
{
    //Declarci�n de variables
    int i;

    //Comprobamos que polinomio es de mayor grado
    if (grado1>grado2)
    {
        //Rellenamos los valores de X en los que el grado de un vector es mayor que el del otro
        for (i=grado1; i > grado2; i--)
            VResultado[i] = Vector1[i];

        //Sumamos los coeficientes a partir del �ltimo t�rmino del polinomio de menor grado
        for (i=grado2; i >= 0; i--)
            VResultado[i] = Vector1[i] + Vector2[i];
    }

    else
        {
        //Rellenamos los valores de X en los que el grado de un vector es mayor que el del otro
        for (i=grado2; i > grado1; i--)
            VResultado[i] = Vector2[i];

        //Sumamos los coeficientes a partir del �ltimo t�rmino del polinomio de menor grado
        for (i=grado1; i >= 0; i--)
            VResultado[i] = Vector1[i] + Vector2[i];
        }
    return;
}

/* ******************************************************************************************************* */
// Funci�n que calcula el producto de dos polinomios.
// Toma: los dos polinomios , el n�mero de elementos de cada uno y
// un tercer vector para almacenar el resultado.
// Devuelve: el producto en el tercer vector.
/* ******************************************************************************************************* */

void multiplica_polinomios (int Vector1[], int Vector2[], int VResultado[], int grado1, int grado2)
{
    //Declaraci�n de variables
    int i, j, grado3;

    grado3 = grado1 + grado2;

    //Inicializamos el tercer vector a 0 (Su grado ser� grado3)
    for (i=0; i<=grado3 ; i++)
        VResultado[i] = 0;

    /*
       Calculamos el producto como dos ciclos for anidados, desde el
       t�rmino independiente de grado2 hasta el coeficiente de grado grado2 vamos
       multiplicando por los coeficientes de grado1 y almacenando los
       resultados en el vector VResultado
    */

    for (i=0; i<=grado1; i++)
        for (j=0; j<=grado2; j++)
        {
            VResultado[i+j] = VResultado[i+j] + Vector1[i]*Vector2[j];
        }
    return;
}

/* ******************************************************************************************************* */
// Funci�n que calcula la potencia n-�sima de un polinomio.
// Toma: el polinomio , su grado , la potencia y una matriz auxiliar para almacenar el resultado.
// Devuelve: la potencia del polinomio en el segundo vector.
/* ******************************************************************************************************* */

void potencia_polinomios (int Vector[], int grado, int potencia, int Matriz[][MAX])
{
    //Declaraci�n de variables
    int i,j,k,N=0;

    //Inicializamos la matriz como un 1 en 0,0 y el resto de esa fila 0
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

/* ******************************************************************************************************* */
// Funci�n auxiliar a la funci�n potencia_polinomios que muestra el polinomio almacenado en
// cierta fila de la matriz que rellena potencia_polinomios
// Toma: la matriz, la fila y su grado.
// Devuelve: -
/* ******************************************************************************************************* */

void muestra_polinomio_matriz(int matriz[][MAX], int fila, int grado)
{
    //Declaraci�n de variables
    int i;

    //Muestra la fila por pantalla
    cout << endl << matriz[fila][grado] << "x^" << grado << " ";
    for(i=grado-1; i>0; i--)
    {
        if (matriz[fila][i]>0)
            cout << "+" << matriz[fila][i] << "x^" << i << " ";
        else if (matriz[fila][i]<0)
            cout << matriz[fila][i] << "x^" << i << " ";
    }
    if (matriz[fila][0]>0) cout << "+" << matriz[fila][0];
    else if (matriz[fila][0<0]) cout << matriz[fila][0];
    return;
}

