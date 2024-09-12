//Clase para trabajar con números complejos

#include <cmath>
#include <iostream>

using namespace std;

class cComplejo
{
private:
    double re,im;

public:
    cComplejo();

    void setValores (double re, double im);

    double getReal();
    double getIm();

    double modulo();
    double argumento();

    cComplejo conjugado();

    cComplejo operator + (cComplejo op);
    cComplejo operator * (cComplejo op);
    cComplejo operator / (cComplejo op);
    bool operator == (cComplejo op);
};

//Constructor
cComplejo :: cComplejo()
{
    re = 1;
    im = 0;
}


//Introduce valores de un complejo
void cComplejo :: setValores (double real, double imaginario)
{
    re = real;
    im = imaginario;

    return;
}


//Parte real
double cComplejo :: getReal()
{
    return re;
}


//Parte imaginaria
double cComplejo :: getIm()
{
    return im;
}


//Calcula el módulo de un complejo
double cComplejo :: modulo()
{
    return sqrt(re*re+im*im);
}


//Calcula el argumento de un complejo
double cComplejo :: argumento()
{
    return atan(im/re);
}


//Calcula el conjugado de un compejo
cComplejo cComplejo :: conjugado()
{
    cComplejo aux;

    aux.re = re;
    aux.im = im;

    return aux;
}

//Suma de complejos
cComplejo cComplejo :: operator + (cComplejo op)
{
    cComplejo aux;

    aux.re = re + op.re;
    aux.im = im + op.im;

    return aux;
}

//Producto de complejos
cComplejo cComplejo :: operator * (cComplejo op)
{
    cComplejo aux;

    aux.re = re*op.re - im*op.im;
    aux.im = re*op.im + im*op.re;

    return aux;
}

//Cociente de complejos
cComplejo cComplejo :: operator / (cComplejo op)
{
    cComplejo aux;

    aux.re = ( re*op.re + im*op.im ) / ( op.re*op.re + op.im*op.im );
    aux.im = ( im*op.re - re*op.im ) / ( op.re*op.re + op.im*op.im );

    return aux;
}

//Comparación de complejos
bool cComplejo :: operator == (cComplejo op)
{
    return ((re==op.re) && (im==op.im));
}


//Potencia de complejos

double cPow (cComplejo z, int n)
{
    int i;
    cComplejo aux=z;

    for (i=2; i<=n; i++)
    {
        aux = aux * z;
    }

    return aux;
}



