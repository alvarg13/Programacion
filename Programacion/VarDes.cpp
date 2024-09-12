#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    ifstream fich;
    int i=0;
    double aux=1,sum=0,med=0;

    fich.open("datos.txt");

    while(aux!=0)
    {
        fich >> aux;
        med+= aux;
        i++;
    }

    med/=i-1;

    fich.close();

    aux=1;

    fich.open("datos.txt");

    while(aux!=0)
    {
        fich >> aux;
        sum+= (aux-med)*(aux-med);
    }

    fich.close();

    cout << i-1 << endl;

    sum /= i-2;

    cout << "La varianza es: " << sum << endl;
    cout << "La desviacion tipica es: " << sqrt(sum) << endl;

    system("pause");

    return 0;
}

