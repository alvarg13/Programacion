#include <iostream>
#include "mivector.hpp"
#define MAX 100

using namespace std;

int main()
{
    int v[MAX];
    int num;
    double media, varianza , desviacion, mediaG;

    do{
        cout << "Numero de elementos del vector: ";
        cin >> num ;
    } while ((num<1)||(num>MAX));

    RellenaVector(v, num);
    media = CalcularMedia (v, num);
    varianza = CalcularVarianza (v, num, media);
    desviacion = CalcularDesviacion (varianza);
    mediaG = CalcularMediaGeometrica(v, num);

    cout << "Resultados" << endl;
    cout << "Introdujo el siguiente vector: " << endl;
    MostrarVector(v, num);

    cout << endl << endl;
    cout << "Media: " << media << endl;
    cout << "Varianza: " << varianza << endl;
    cout << "Desviacion: " << desviacion << endl ;
    cout << "Media geometrica: " << mediaG << endl << endl;

    return 0;
}
