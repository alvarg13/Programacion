// Programa que genera veinte n�meros reales aleatorios entre -7.5 y 7.5 y los muestra en pantalla adem�s de su m�ximo, m�nimo y valor medio

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main (void)
{
    double resultado, numero, sumatorio = 0, maximo=-7.5, minimo=7.5, Vmedio, a;
    int i;

    //Explicacion
    cout << "Este programa genera veinte numeros reales aleatorios entre -7.5 y 7.5" << endl ;
    cout << "y los muestra en pantalla, ademas de su maximo, minimo y valor medio" << endl ;
    system("pause");

    //Doy inicio a rand
    srand( time(NULL) );

    //Espacio las l�neas
    cout << " " << endl ;

    //Inicio el bucle que calcula el m�ximo, m�nimo y la suma de todos, adem�s de mostrar cada n�mero
    for ( i=1 ; i<=20 ; i++ )
    {
        a = rand(); //NOTA: sin esta variable el program solo muestra -7.5 para todos los n�meros
        numero = (a / RAND_MAX) * 15 - 7.5;
        sumatorio = sumatorio + numero;

        if (numero > maximo) {maximo = numero;}
        if (numero < minimo) {minimo = numero;}

        cout << "El numero " << setw(2) << left << i << " es:" << right << setw(9) << fixed << setprecision(5) << numero << endl ;
    }
    //Calcular media
    Vmedio = sumatorio/20;

    //Mostrar resultado
    cout << endl << "El maximo es: " << right << setw(9) << fixed << setprecision(5) << maximo << endl;
    cout << "El minimo es: " << right << setw(9) << fixed << setprecision(5) << minimo << endl;
    cout << "El valor medio es: " << fixed << setprecision(5) << Vmedio << endl;

    system("pause");
    return 0;
}
