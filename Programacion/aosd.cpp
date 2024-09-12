#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fich;
    ofstream fich1;

    string v[100],w[100];
    int i=0,n;

    fich.open("datos.txt");

    while(!fich.eof())
    {
        fich>>v[i];
        fich>>w[i];
        i++;
    }

    n=i;

    fich.close();

    fich1.open("notas.txt");
    for(i=0;i<n;i++)
        fich1 << v[i] << endl;
    fich1.close();

    fich1.open("tiempo.txt");
    for(i=0;i<n;i++)
        fich1 << w[i] << endl;
    fich1.close();

    return  0;


}
