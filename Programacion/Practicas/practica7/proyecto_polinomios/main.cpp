// Programa para comprobar que las funciones de la librería funcionan correctamente.

#include <iostream>
#include <iomanip>


#define MAX 101

#include "polinomios.hpp"

using namespace std;

int main()
{
    //Declaración de variables
    int V[MAX],W[MAX],X[MAX],Y[MAX];
    int A[MAX][MAX];
    int n1,n2,p,x;

    //Introduce dos polinomios para realizar las pruebas y los muestra por pantalla
    cout << "Introduce el grado del primer polinomio: ";
    cin >> n1;
    cout << endl;

    introduce_polinomio(V,n1);
    muestra_polinomio(V,n1);

    cout << "Introduce el grado del segundo polinomio: ";
    cin >> n2;
    cout << endl;

    introduce_polinomio(W,n2);
    muestra_polinomio(W,n2);

    //Calcula la suma de los dos polinomios en un tercer vector
    suma_polinomios(V,W,X,n1,n2);
    cout << "La suma es:" << endl;
    muestra_polinomio(X,max(n1,n2));

    //Calcula el resultado de sustituir un x en la suma de los dos polinomios
    cout << "Introduce el valor a sustituir en el polinomio suma: ";
    cin >> x;

    cout << "El resultado es: " << calcula_polinomio(X,max(n1,n2),x) << endl; //------------------------------

    //Calcula la suma de los polinomios de forma independiente para ver si el resultado es el mismo
    cout << "El resultado alternativo es: " << calcula_polinomio(V,n1,x) + calcula_polinomio(W,n2,x) << endl << endl;

    //Calcula el producto de los dos polinomios y muestra el polinomio resultado
    multiplica_polinomios(V,X,Y,n1,n2);
    cout << "El producto de los polinomios es:" << endl;
    muestra_polinomio(Y,n1+n2);

    //Calcula la potencia p-ésima de el primer polinomio y lo muestra por pantalla
    cout << "Introduce la potencia a la que elevar el primer polinomio: ";
    cin >> p;

    potencia_polinomios(V,n1,p,A);
    cout << "El resultado de elevar el primer polinomio a " << p << " es:" << endl;
    muestra_polinomio_matriz(A,p,p*n1);
    return 0;
}
