#ifndef MIVECTOR_HPP_INCLUDED
#define MIVECTOR_HPP_INCLUDED

//Prototipos de las funciones de mivector.cpp

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

double CalcularMedia (int v[], int n);
double CalcularVarianza (int v[], int n, double media);
double CalcularDesviacion (double varianza);
void RellenaVector (int v[], int n);
void MostrarVector (int v[], int n);
double CalcularMediaGeometrica (int v[],int n);

#endif // MIVECTOR_HPP_INCLUDED
