/*  Programa para calcular las funciones trigonométricas del ángulo triple de forma directa y alternativa
    Entradas: ángulo, (angulo)
    Salida: la transformación del ángulo a frracciones de PI (anguloPI) y el valor de las funciones de forma directa e indirecta:
    seno (senx, senD, senA), coseno (cosx, cosD, cosA) y tangente (tanx, tanD, tanA)
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#define PI 3.14159265358979323846
using namespace std;

int main(void)
{
    //Declaración de variables
    double angulo, anguloPI, senx, senA, senD, cosx, cosD, cosA, tanx, tanD, tanA;

    //Explicación
    cout << " Este programa calcula el valor de las funciones trigonometricas de" << endl ;
    cout << "forma directa e indirecta para un angulo dado, para mayor precision" << endl ;
    cout << "el angulo se introducira en fracciones de PI (Ejemplo: o.5 = o.5*PI)" << endl ;
    cout << "Pd: Angulo en radianes." << endl << endl ;

    //Recopilacion de datos.
    cout << "Introduzca el angulo: ";
    cin >> angulo;


    //Calculos
    anguloPI = angulo*PI;

    senx = sin (anguloPI);
    cosx = cos (anguloPI);
    tanx = tan (anguloPI);

    senD = sin (3*anguloPI);
    cosD = cos (3*anguloPI);
    tanD = tan (3*anguloPI);

    senA = 3*senx - 4*(senx*senx*senx);
    cosA = 4*(cosx*cosx*cosx) - 3*cosx;
    tanA = ( 3*tanx - (tanx*tanx*tanx) ) / ( 1 - 3*(tanx*tanx) );



    //Mostrar el resultado
    cout << endl << setw(25) << left << "Funcion" ;
    cout << setw(25) << left << "Forma Directa" ;
    cout << "Forma Alternativa" << endl;

    cout << setw(25) << left << "Seno" ;
    cout << setw(25) << left << senD ;
    cout << senA << endl;

    cout << setw(25) << left << "Coseno" ;
    cout << setw(25) << left << cosD ;
    cout << cosA << endl;

    cout << setw(25) << left << "Tangente" ;
    cout << setw(25) << left << tanD ;
    cout << tanA << endl;


    system("pause");
    return 0;
}
