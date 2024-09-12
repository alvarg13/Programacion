#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    int i=0,n;
    double x[100],s[100];
    double a,b,c;
    double r[2];
    ifstream fiche;

    fiche.open("datos.txt");

    while(!fiche.eof())
    {
        fiche >> x[i];
        fiche >> s[i];
        i++;
    }

    fiche.close();


    n=i;
    a=b=c=0;

    for (i=0;i<=n;i++)
    {
        a+= 1/(s[i]*s[i]);
        b+= x[i]/(s[i]*s[i]);
        c+= (x[i]*x[i])/(s[i]*s[i]);
    }

    r[0] = c/(a*c-b*b);
    r[0] = a/(a*c-b*b);

    cout << "El valor de a es : " << r[0] << endl;
    cout << "El valor de b es : " << r[1] << endl;

}
