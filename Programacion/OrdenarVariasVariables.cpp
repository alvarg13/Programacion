#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void intercambia (double & a, double & b);
void intercambia (string & a, string & b);

int main()
{
    //Declaracion de variables
    ifstream ifich;
    ofstream ofich;

    int i,j,n,posmin,c=0,p,c2=0;
    double inicio,incrementos;
    double v[500], w[500];

    cout << "Elige la variable: ";
    cin >> p;

    //Leer fichero
    ifich.open("datos.txt");
    i=0;

    ifich >> inicio;
    ifich >> incrementos;

    if(p==1)
    {
        while(!ifich.eof())
        {
            ifich >> v[i];
            ifich >> w[i];
            i++;
        }
    }

    cout << i << endl;

    if(p==2)
    {
        while(!ifich.eof())
        {
            ifich >> w[i];
            ifich >> v[i];
            i++;
        }
    }



    n=i;
    ifich.close();

    //Ordenar
    for(i=0;i<n;i++)
    {
        posmin=i;
        for(j=i;j<n-1;j++)
            if(v[posmin]>v[j]) posmin=j;
        intercambia(v[posmin],v[i]);
        intercambia(w[posmin],w[i]);

         cout << v[i] << "  " << w[i] << endl;
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
        ofich << setw(4) << left << v[i] << " --- " << setw(4) << right << w[i] << endl;
        c++;
    }

    ofich << endl << inicio << " -------------------------- ";
    inicio+=incrementos;
    ofich << inicio;
    c2+=c;
    ofich << " :" << c << " -- "<< c2 << endl << endl;

    ofich.close();

    system("pause");

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
