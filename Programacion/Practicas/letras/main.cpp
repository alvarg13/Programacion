/************************************************************************/
/* PROGRAMA LETRAS                                                      */
/* Autor: Jose Luis Bernier Villamor                                    */
/* Universidad de Granada                                               */
/************************************************************************/
/* Este programa implementa el juego de las letras del programa de TV   */
/* Cifras y Letras. Para ello usa un diccionario (un fichero con        */
/* palabras.                                                            */
/*                                                                      */
/* Dado un conjunto de vocales y consonantes, el programa va leyendo    */
/* las palabras almacenadas en el fichero, y va comprobando si          */
/* cada una de ellas puede formarse con las letras seleccionadas.       */
/*                                                                      */
/* Sólo se van comprobando las palabras cuya longitud es mayor o igual  */
/* que la mejor palabra encontrada hasta ese momento. Por ello, en la   */
/* pantalla se van mostrando las palabras cada vez mayores, siendo las  */
/* últimas las óptimas.                                                 */
/************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define MAXLETRAS 20
using namespace std;

/* Prototipos de las funciones que se usan */
string EscogerVocales (int numvocales);
string EscogerConsonantes (int numconsonantes);
void Busca_en_diccionario (string letras);

int main(void)
{
    int numvocales, numconsonantes;
    string vocales, consonantes;

    // Se dibuja la interfaz del programa
    system("cls");
    cout << "      ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿" << endl;
    cout << "      ³                                                     ³" << endl;
    cout << "      ³                                                     ³" << endl;
	cout << "      ³   LETRAS. PROGRAMACION - Autor: Jose Luis Bernier   ³" << endl;
	cout << "      ³                                                     ³" << endl;
    cout << "      ³                                                     ³" << endl;
	cout << "      ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ" << endl;
    cout << endl <<endl << endl;

    // Se pide el número total de vocales y consonantes
    cout << "Introduzca el numero de vocales y consonantes a utilizar en el juego" << endl;
    cout << "(como maximo 10 vocales y 10 consonantes)" << endl << endl;

    do {
        cout << "Numero de vocales: ";
        cin >> numvocales;
    } while ((numvocales<1) || (numvocales>10));

    cout << endl;

    do {
        cout << "Numero de consonantes: ";
        cin >> numconsonantes;
    } while ((numconsonantes<0) || (numconsonantes>10));

    // Se generan las letras al azar
	vocales=EscogerVocales(numvocales);
	consonantes=EscogerConsonantes(numconsonantes);
	cout << endl;
	cout << "Letras a utilizar: "  << vocales << " " << consonantes << endl << endl;

    // Se buscan palabras en el diccionario
    Busca_en_diccionario(vocales+consonantes);

    system("pause");

    return 0;
}

/******************************************************
   Función que genera aleatoriamente las vocales
   Recibe:
   - numvocales: número de vocales a generar
   Devuelve: un string que contiene las letras generadas
*******************************************************/
string EscogerVocales(int numvocales)
{
    string vocales, letras;
    int i,n;

    vocales="AEIOU";

	srand(time(0));
    for(i=0; i<numvocales; i++)
    {
    	n=rand()%5;
        letras=letras+vocales[n];
    }

    return letras;
}

/******************************************************
   Función que genera aleatoriamente las consonantes
   Recibe:
   - numconsonantes: número de vocales a generar
   Devuelve: un string que contiene las letras generadas
*******************************************************/
string EscogerConsonantes(int numconsonantes)
{
    string consonantes, letras;
    int i,n;

    consonantes="BCDFGHJKLMNPQRSTVWXYZ¥";

	srand(time(0));

    for(i=0; i<numconsonantes; i++)
    {
    	n=rand()%22;
        letras=letras+consonantes[n];
    }

    return letras;
}

/******************************************************
   Función que busca palabras en el diccionario
   Va leyendo palabra a palabra y comprueba si
   dicha palabra se puede formar con las letras
   escogidas.
   Se van mostrando las palabras que van mejorando
   la solución (las más largas que se pueden formar con
   los caracteres seleccionados).
   Recibe:
   - letras: string que contiene las letras a considerar
   Devuelve: nada, escribe en pantalla las palabras que
     va encontrando conforme busca en el diccionario
*******************************************************/
void Busca_en_diccionario(string letras)
{
    ifstream fich;
    int i,pos,lactual,lmax, numletras;
    bool sigo;
    string palabra, letrasaux;

    cout <<"        ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿" << endl;
    cout <<"        ³  PALABRA ENCONTRADA  ³  N  ³" << endl;
    cout <<"        ³ -------------------- ³ --- ³" << endl;
    cout <<"        ³                      ³     ³" << endl;

    numletras=letras.length();
	fich.open("palabras.txt");
    lmax=0;
    while(!fich.eof())
    {
    	getline(fich,palabra);
    	lactual=palabra.length();

        //Si la longitud de la palabra leida es mayor que el número de letras
        //no la comprobamos porque obviamente es imposible formarla
        //Tampoco compruebo las palabras leidas que sean más cortas que la mejor
        //que haya encontrado hasta el momento, ya que quiero mejorar.
        if((lactual<=numletras) && (lactual>=lmax))
        {
            i=0;
            sigo=true;
            letrasaux=letras;

            //Este bloque comprueba si la palabra leida puede formarse
            //con las letras consideradas en el juego
        	while((i<lactual) && sigo)
        	{
        		pos=letrasaux.find(palabra[i]);
        		if(pos==-1) sigo=false;
        		else
        		{
                    letrasaux.erase(pos,1);
                    i++;
                }
            }

        	//Si la palabra se pudo formar y es igual o mejor la muestro en pantalla
        	if(sigo)
        	{
                lmax=lactual;
            	cout << "        ³ " << setw(20) << palabra << " ³" << setw(4) << lactual << " ³" << endl;
            }
        }
    }

    cout <<"        ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ" << endl;
    fich.close();
    return;
}
