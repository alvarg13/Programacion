//Programa que reordena una serie de cadenas de caracteres almacenadas
//en las l�neas de un fichero
//Almacena cada cadena en los t�rminos de un vector y los ordena segun su longitud
//para despu�s almacenarlas en orden en otro fichero

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define MAX 100000

using namespace std;

int ficheroAvector (string ruta, string palabras[]);
void vectorAfichero (string ruta, string palabras[], int longitud);
void OrdenaBurbuja (string lista[], int longitud);
void OrdenaSeleccion (string lista[], int longitud);
void intercambia (string & a ,string & b);

int main(void)
{
    //Declaracion de variables
    string forigen, fdestino;
    string palabras[MAX];
    int longitud;



    //Se pide la ruta del fichero origen
    cout << "Introduce el nombre del archivo: ";
    cin >> forigen;
    cout << endl;

    //Se pide la ruta del fichero destino
    cout << "Introduce el nombre del archivo en el que almacenar el resultado";
    cin >> fdestino;



    //Se introducen las l�neas del archivo e un vector
    longitud = ficheroAvector (forigen, palabras);

    //Se ordena el vector por tama�o
    OrdenaBurbuja (palabras, longitud);

    //Se escribe l�nea a l�nea el vector en otro archivo
    vectorAfichero (fdestino, palabras, longitud);



    //Pausa
    system("pause");

    return 0;
}




/* ************************************************************************************************/
/* Funci�n que introduce las l�neas de un fichero en un vector                                    */
/* Toma: la ruta del archivo y el vector para almacenar las l�neas                                */
/* Devuelve: la longitud del vector                                                               */
/* ************************************************************************************************/

int ficheroAvector (string ruta, string palabras[])
{
    //Declaraci�n de variables
    ifstream fichero;
    int i=0;

    //Abrimos el fichero
    fichero.open(ruta.c_str());

    //Rellenamos cada t�rmino del vector con una l�nea del archivo
    while(!fichero.eof())
    {
        getline (fichero, palabras[i]);
        i++;
    }

    //Cerramos el fichero
    fichero.close();

    return i;
}

/* ************************************************************************************************/
/* Funci�n que rellena un fichero con los strings almacenados en un vector.                       */
/* Toma: la ruta del archivo a rellenar, el vector y tu tama�o.                                   */
/* Devuelve: -                                                                                    */
/* ************************************************************************************************/

void vectorAfichero (string ruta, string palabras[], int longitud)
{
    //Declaraci�n de variables
    ofstream fichero;
    int i;

    //Introducimos cada string del vector en una linea distinta
    for (i=0; i<longitud; i++)
        fichero << palabras[i] << endl;

    //Cerramos el archivo
    fichero.close();

    return;
}


/* ************************************************************************************************/
/* Funci�n que ordena un vector de strings mediante el algoritmo de la burbuja.                   */
/* Toma: el vector y su tama�o.                                                                   */
/* Devuelve: -                                                                                    */
/* ************************************************************************************************/

void OrdenaBurbuja (string lista[], int longitud)
{
    //Declaraci�n de variables
    int i,j;

    //Mecanismo de ordenaci�n de la burbuja
    for (i=0; i<longitud; i++)
    {
        for (j=longitud-1; j>=i; j--)
            if (lista[ j ].length() < lista[ j-1 ].length())
                intercambia (lista[j], lista[j-1]);
    }

    return;
}



/* ************************************************************************************************/
/* Funci�n que ordena un vector de strings mediante el algoritmo de selecci�n.                    */
/* Toma: el vector y su tama�o.                                                                   */
/* Devuelve: -                                                                                    */
/* ************************************************************************************************/

void OrdenaSeleccion (string lista[], int longitud)
{
    //Declaraci�n de variables
    int i,j,posmax;
    string aux;

    //Mecanismo de ordenaci�n por selecci�n
    for (i=0; i<longitud; i++)
    {
        posmax = i;
        for (j=i+1; j<longitud; j++)
            if (lista[ j ].length() > lista[ posmax ].length())
                intercambia (lista[j], lista[posmax]);
    }

    return;
}


/* ************************************************************************************************/
/* Funci�n que intercambia el contenido de dos strings por referencia.                            */
/* Toma: los dos strings.                                                                         */
/* Devuelve: -                                                                                    */
/* ************************************************************************************************/

void intercambia (string & a ,string & b)
{
    //Declaraci�n de variables
    string aux;

    //Intercambio
    aux = a;
    a = b;
    b = aux;

    return;
}
