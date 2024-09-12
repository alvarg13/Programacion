#ifndef POLINOMIOS_HPP_INCLUDED
#define POLINOMIOS_HPP_INCLUDED
#define MAX 101

//Prototipos de las funciones de polinomios.cpp

#include <iostream>
using namespace std;

void introduce_polinomio (int Vector[],int grado);
void muestra_polinomio (int Vector[],int grado);
double calcula_polinomio (int Vector[],int grado, double x);
void suma_polinomios (int Vector1[], int Vector2[], int VResultado[], int grado1, int grado2);
void multiplica_polinomios (int Vector1[], int Vector2[], int VResultado[], int grado1, int grado2);
void potencia_polinomios (int Vector[], int grado, int potencia, int Matriz[][MAX]);
void muestra_polinomio_matriz(int matriz[][MAX], int fila, int grado);

#endif // POLINOMIOS_HPP_INCLUDED
