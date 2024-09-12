#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fich;
    int i,p,n=-1;
    double media,var,aux,v[100],w[100];

    media=var=aux=0;

    fich.open("datos.txt");

    cout << "Indica la variable: ";
    cin >> p;

    if(p==1)
    {
        while(v[n]!=0)
        {
            n++;
            fich >> v[n];
            fich >> w[n];
            media+=v[n];

        }
    }


    if(p==2)
    {
        while(v[n]!=0)
        {
            fich >> w[n];
            fich >> v[n];
            media+=v[n];
            n++;
        }
    }

    fich.close();

    media/=n;

    cout << n << endl;

    cout << "La media es: " << setprecision(8) << media << endl;


    for(i=0; i<n; i++)
    {
        aux = v[i] - media;
        var += aux*aux;
    }

    var/= (n-1);

    cout << "La varianza es: " << setprecision(8) << var << endl;
    cout << "La desviacion tipica es: " << setprecision(8) << sqrt(var) << endl;;

    system("pause");

    return 0;
}
