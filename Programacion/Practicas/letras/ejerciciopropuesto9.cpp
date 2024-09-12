//Programa que reordena una serie de cadenas de caracteres almacenadas
//en las líneas de un fichero
//Almacena cada cadena en los términos de un vector y los ordena segun su longitud
//para después almacenarlas en orden en otro fichero

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define MAX 23000

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
    string palabras[MAX], linea;
    ifstream vfich;
    int longitud, i=0, opcion = -1;



    //Se pide la ruta del fichero origen
    cout << "Introduce el nombre del archivo origen: ";
    cin >> forigen;

    //Se pide la ruta del fichero destino
    cout << "Introduce el nombre del archivo en el que almacenar el resultado: ";
    cin >> fdestino;
    cout << endl;



    //Se introducen las líneas del archivo e un vector
    longitud = ficheroAvector (forigen, palabras);

    while ((opcion != 1) && (opcion != 2))
    {
        cout << "Escribe 1 para el algoritomo de seleccion o" << endl;
        cout << "2 para la ordenacion de la burbuja: ";
        cin >> opcion;
        cout << endl;
    }


    //Se ordena el vector por tamaño según la decisión tomada
    if (opcion == 1)
    OrdenaSeleccion(palabras, longitud);

    else
    OrdenaBurbuja(palabras, longitud);



    //Se escribe línea a línea el vector en otro archivo
    vectorAfichero (fdestino, palabras, longitud);

    cout << "Primeras lineas del archivo generado:" << endl << endl;
    vfich.open(fdestino.c_str());
    while ((!vfich.eof()) && (i<10))
    {
        getline(vfich,linea);
        cout << linea << endl;
        i++;
    }
    cout << endl;

    //Pausa
    system("pause");

    return 0;
}




/* ************************************************************************************************/
/* Función que introduce las líneas de un fichero en un vector
/* Toma: la ruta del archivo y el vector para almacenar las líneas
/* Devuelve: la longitud del vector
/* ************************************************************************************************/

int ficheroAvector (string ruta, string palabras[])
{
    //Declaración de variables
    ifstream fichero;
    int i=-1;

    //Abrimos el fichero
    fichero.open(ruta.c_str());

    //Comprobamos que se ha abieto correctamente
    if (fichero.is_open())
        {
            i=0;

            //Rellenamos cada término del vector con una línea del archivo
            while(!fichero.eof())
            {
                getline (fichero, palabras[i]);
                i++;
            }
        }

    else
        cout << "El archivo origen no se ha abierto correctamente" << endl;

    //Cerramos el fichero
    fichero.close();

    return i;
}

/* ************************************************************************************************/
/* Función que rellena un fichero con los strings almacenados en un vector.
/* Toma: la ruta del archivo a rellenar, el vector y tu tamaño.
/* Devuelve: -
/* ************************************************************************************************/

void vectorAfichero (string ruta, string palabras[], int longitud)
{
    //Declaración de variables
    ofstream fichero;
    int i;

    //Abrimos el fichero
    fichero.open(ruta.c_str());

    //Comprobamos que se ha abieto correctamente
    if (fichero.is_open())
        {
            //Introducimos cada string del vector en una linea distinta
            for (i=0; i<longitud; i++)
                fichero << palabras[i] << endl;
        }

    else
        cout << "El archivo resultado no se ha abierto correctamente" << endl;


    //Cerramos el archivo
    fichero.close();

    return;
}


/* ************************************************************************************************/
/* Función que ordena un vector de strings mediante el algoritmo de la burbuja.
/* Toma: el vector y su tamaño.
/* Devuelve: -
/* ************************************************************************************************/

void OrdenaBurbuja (string lista[], int longitud)
{
    //Declaración de variables
    int i,j;

    //Mecanismo de ordenación de la burbuja
    for (i=0; i<longitud; i++)
    {
        for (j=longitud-1; j>=i; j--){
            if (lista[ j ].length() > lista[ j-1 ].length())
                intercambia (lista[j], lista[j-1]);
        }
    }

    return;
}



/* ************************************************************************************************/
/* Función que ordena un vector de strings mediante el algoritmo de selección.
/* Toma: el vector y su tamaño.
/* Devuelve: -
/* ************************************************************************************************/

void OrdenaSeleccion (string lista[], int longitud)
{
    //Declaración de variables
    int i,j,posmax;

    //Mecanismo de ordenación por selección
    for (i=0; i<longitud; i++)
    {
        posmax = i;
        for (j=i+1; j<longitud; j++)
            if (lista[ j ].length() > lista[ posmax ].length())
                posmax = j;
        intercambia (lista[i], lista[posmax]);
    }

    return;
}


/* ************************************************************************************************/
/* Función que intercambia el contenido de dos strings por referencia.
/* Toma: los dos strings.
/* Devuelve: -
/* ************************************************************************************************/

void intercambia (string & a ,string & b)
{
    //Declaración de variables
    string aux;

    //Intercambio
    aux = a;
    a = b;
    b = aux;

    return;
}
