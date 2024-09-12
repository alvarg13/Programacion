/*  Programa para calcular per�metro, apotema y �rea de un pentagono
    regular dada la longitud de sus lados.
    Entradas: la longitud de los lados (lado).
    Salida: la longitud de su per�metro, apotema y su �rea (perimetro, apotema y area)
*/

#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

#define PI 3.14159265358979323846

int main(void)
{
    //Declaraci�n de variables
    double lado, apotema, perimetro, area;

    //Explicaci�n programa.
    cout << "Este programa puede utilizarse para calcular apotema, area y perimetro de un pentagono " << endl;
    cout << "regular dada la longitud de sus lados." << endl << endl;

    //Pedir la longitud de los lados del pent�gono regular.
    cout << "Introduzca la longitud de sus lados: ";
    cin >> lado;

    //Calculos.
    apotema = lado /( 2 * tan(0.2 * PI));
    perimetro = 5 * lado;
    area = lado * apotema * 2.5;

    //Mostrar el resultado
    cout << endl << "La apotema mide: " << apotema << endl;
    cout << "El area mide: " << area << endl;
    cout << "Su perimetro es: " << perimetro << endl << endl;

    system("pause");
    return 0;
}
