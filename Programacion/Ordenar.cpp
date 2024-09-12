#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void intercambia (double & a, double & b);
void intercambia (string & a, string & b);

int main()
{
    //Declaracion de variables
    ifstream ifich;
    ofstream ofich;
    bool condicion;

    int i,j,n,posmin,c=0, c2=0;
    double inicio,incrementos;
    double v[500];

    //Leer fichero
    ifich.open("datos.txt");
    i=0;

    ifich >> inicio;
    ifich >> incrementos;

    while(!ifich.eof())
    {
        ifich >> v[i];
        i++;
    }
    n=i;
    ifich.close();


    //Ordenar
    for(i=0;i<n;i++)
    {
        posmin=i;
        for(j=i;j<n;j++)
            if(v[posmin]>v[j]) posmin=j;
        intercambia(v[posmin],v[i]);
    }


    //Mostrar

    ofich.open("resultado.txt");

    for(i=0; i<n; i++)
    {
        while(v[i]>(inicio+incrementos))
        {
            ofich << endl << inicio << " -------------------------- ";
            inicio+=incrementos;
            ofich << inicio;
            c2+=c;
            ofich << " :" << c << " -- "<< c2 << endl << endl;
            c=0;
        }
        ofich << v[i] << endl;
        c++;
    }

    ofich << endl << inicio << " -------------------------- ";
    inicio+=incrementos;
    ofich << inicio;
    c2+=c;
    ofich << " :" << c << " -- "<< c2 << endl << endl;

    ofich.close();

    return 0;
}


void intercambia (double & a, double & b)
{
    double aux;
    aux=a;
    a=b;
    b=aux;

    return;
}

void intercambia (string & a, string & b)
{
    string aux;
    aux=a;
    a=b;
    b=aux;

    return;
}
