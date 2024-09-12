//Programa que calcula la suma de los numeros primos menores
//o iguales que cierto natural
//Toma el numero natural límite
//Devuelve la suma de los primos menores o iguales que n y el tiempo empleado en el proceso

#include <iostream>
#include <ctime>
#include <cmath>

bool es_primo(unsigned int n);

using namespace std;
int main ()
{
    unsigned int n,i,r;
    unsigned long int suma;
    clock_t t1, t2;
    double numsecs;

    //Pedir el numero
    cout << "Introduzca el numero: ";
    cin >> n ;

    //Realizar la suma acumulada
    t1 = clock();
    for (r=1; r<=100; r++)
    {
        suma = 0;
        for (i = 2; i<=n ; i++)
            if (es_primo(i)) suma = suma + i;
    }
    t2 = clock();

    //Mostrar el resultado
    cout << "Suma de los primos menores o iguales que ";
    cout << n << ": " << suma << endl ;

    //Muestro el tiempo invertido en el calculo
    numsecs =(double)(t2 - t1)/(CLOCKS_PER_SEC*100);
    cout << "Tiempo: " << numsecs << "segundos" << endl;

    return 0;
}

//Funcion que comprueba si un numero entero es primo
//Devuelve un booleano: TRUE si es primo, FALSE si no lo es
//Divide el numero por todos los enteros menores que el
//Si el  resto de alguna de las divisiones es cero
//entonces no es primo

bool es_primo (unsigned int n)
{
    unsigned int i,p;
    bool EsPrimo;

    if (n==2) EsPrimo==true;
    else if (n%2==0) EsPrimo=false;
    else
    {
        EsPrimo=true;
        p = (unsigned int) sqrt(n);
        i = 3;
        while ((i<=p)&&(EsPrimo==true))
        {
            if (n%i == 0) EsPrimo=false;
            else i = i+2;
        }
    }
    return EsPrimo;
}
