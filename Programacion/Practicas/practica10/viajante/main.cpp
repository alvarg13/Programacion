//Programa que trata de resolver el problema
//del viajante de comercio.
//Se prueban varios algoritmos.

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <cmath>

#define MAX 100
#define MAX_TIME 3600

using namespace std;

//La clase tMapa se utiliza prara almacenar en memoria
//el nombre de las ciudades y las distancias entre las mismas

class tMapa
{
    public:
        int num_ciudades;
        string nombre_ciudad[MAX];
        int distancia[MAX][MAX];

        void LeerMapa(void);
};

//M�todo LeerMapa(): extrae los datos del fichero y los copia
//sobre la matriz de distancias del objeto

void tMapa::LeerMapa(void)
{
    ifstream fichero;
    int i, j;

    fichero.open("distancias.txt");

    //Leer n�mero de ciudades
    fichero >> num_ciudades;

    //Leer nombre de las ciudades
    for (i=0; i< num_ciudades; i++)
            fichero >> nombre_ciudad[i];

    //Leer la matriz de distancias
    for(i=0; i< num_ciudades; i++)
        for (j=0; j< num_ciudades; j++)
            fichero >> distancia[i][j];

    fichero.close();

    return;
}

//La clase tRuta almacena un posible recorrido, es decir,
//el orden en que se pueden recorrer las ciudades.
//Al final se le �ade la ciudad de origen como un elemento m�s.
//Tambi�n guarda la distancia que supone dicho recorrido.

class tRuta
{
    public:
        int num_ciudades;
        int recorrido[MAX+1];
        int distancia;

        void CalculaDistancia(tMapa mapa);
        void MuestraRuta (tMapa mapa);
};

//M�todo CalculaDistancia(): calcula la distancia total de un recorrido.

void tRuta::CalculaDistancia(tMapa mapa)
{
    int i;

    distancia = 0;

    //Sumar la distancia entre cada dos ciudades del recorrido
    for (i=0; i<=num_ciudades; i++)
        distancia = distancia + mapa.distancia[recorrido[i-1]][recorrido[i]];

    return;
}

//M�todo MuestraResultado(): muestra en la pantalla la distancia
//de un recorrido y el orden en que hay que recorrer las
//ciudades, mostando sus nombres.

void tRuta::MuestraRuta(tMapa mapa)
{
    int i;

    cout << "Distancia: " << distancia << "Kms" << endl;
    cout << "Recorrido propuesto: " << endl;

    //Ciudades intermedias, cada 5 hago un salto de l�nea
    for (i=0; i<=num_ciudades; i++)
    {
        cout << mapa.nombre_ciudad[recorrido[i]] << " > ";
        if(i%5==0) cout << endl;
    }

    cout << endl;
    return;
}

tRuta Algoritmo1(tMapa mapa);
tRuta Algoritmo2(tMapa mapa);
tRuta Algoritmo3(tMapa mapa);
tRuta Algoritmo4(tMapa mapa);
tRuta Algoritmo5(tMapa mapa);
tRuta Algoritmo6(tMapa mapa);
tRuta IntercambiaCiudades(tRuta ruta,tMapa mapa);
char EscogeAlgoritmo(void);
int PedirTiempoMaximo (void);


//Algoritmo 1: calcula la ruta por defecto. Se coge como
//recorrido el orden en que aparecen en el fichero original

tRuta Algoritmo1(tMapa mapa)
{
    tRuta ruta;
    int i;

    ruta.num_ciudades = mapa.num_ciudades;
    for (i=0; i < ruta.num_ciudades; i++)
        ruta.recorrido[i] = i;

    //Se le a�ade la ciudad de partida al final del recorrido
    ruta.recorrido[ruta.num_ciudades] = 0;

    ruta.CalculaDistancia(mapa);

    return ruta;
}


//Algoritmo 2 (Greedy): se establece un recorrido consistente en
//escoger en primer lugar la ciudad m�s cercana a la ciudad de partida,
//despu�s la m�s cercana a la escogida, y asi sucesivamente.
//Este algoritmo es en el fondo un problema de encontrar N m�nimos, teniendo
//en cuenta que las ciudades que ya se hayan escogido no hay que volver
//a considerarlas

tRuta Algoritmo2(tMapa mapa)
{
    tRuta ruta;
    int distanciamin;
    int i,j;
    int ciudad_mascercana, contador;
    bool ciudad_escogida[MAX];

    ruta.num_ciudades = mapa.num_ciudades;

    //Usamos un array que indique si una ciudad ya se ha inclu�do o no
    for(i=0; i<=ruta.num_ciudades; i++)
        ciudad_escogida[i] = false;

    //La primera ciudad es la de partida y la �ltima es la misma
    ruta.recorrido[0] = ruta.recorrido[ruta.num_ciudades] = 0;
    ciudad_escogida[0] = ciudad_escogida[ruta.num_ciudades]= true;

    //i indica el numero de ciudad a la que hay que buscar la m�s cercana
    i=0;
    //contador indica el n�mero de m�nimos que hay que buscar, uno por cada
    //ciudad a recorrer, menos la �ltima intermedia, que retorna siempre a la de
    //partida
    contador=0;
    while(contador<(ruta.num_ciudades-1))
    {
        //Para cada ciudad del recorrido busco la ciudad m�s cercana
        distanciamin = 100000;
        for(j=0;j<ruta.num_ciudades; j++)
        {
            //Las ciudades que ya se han incluido en el recorrido no se cuentan
            //para evitar las repeticiones
            if(ciudad_escogida[j]==false)
                if(mapa.distancia[i][j] < distanciamin)
                {
                    distanciamin = mapa.distancia[i][j];
                    ciudad_mascercana = j;
                }
        }
        //Escogemos la ciudad m�s cercana como siguiente en el recorrido
        //y la descartamos para las pr�ximas b�squedas de m�nimos
        i = ciudad_mascercana;
        ciudad_escogida[ciudad_mascercana] = true;
        contador++;
        ruta.recorrido[contador]=ciudad_mascercana;
    }

    ruta.CalculaDistancia(mapa);

    return ruta;
}



//Algoritmo 3: se genera una ruta al azar
tRuta Algoritmo3(tMapa mapa)
{
    tRuta ruta;
    bool ciudad_escogida[MAX];
    int i, azar;

    ruta.num_ciudades = mapa.num_ciudades;
    //La ciudad de origen y llegada es fija
    ruta.recorrido[0] = ruta.recorrido[ruta.num_ciudades] = 0;

    //Para controlar las ciudades ya escogidas previamente
    for(i=1; i<ruta.num_ciudades; i++)
        ciudad_escogida[i] = false;

    //Las ciudades intermedias se escogen al azar
    for(i=1; i<ruta.num_ciudades; i++)
    {
        //Genero n�mero de ciudad intermedia al azar
        azar = rand()%(ruta.num_ciudades-1)+1;
        //Si ya est� escogido reviso la siguiente no escogida a�n
        while(ciudad_escogida[azar]==true)
        {
            //Si llego a la �ltima intermedio, reviso desde la primera
            if(azar==(ruta.num_ciudades-1)) azar = 1;
            else azar++;
        }
        ruta.recorrido[i]=azar;
        ciudad_escogida[azar] = true;
    }
    ruta.CalculaDistancia(mapa);
    return ruta;
}


tRuta Algoritmo4(tMapa mapa, int tiempo_maximo)
{
    tRuta RutaAleatoria, RutaMejor;
    clock_t tini, tfin;
    int numsecs;

    tini = clock();

    RutaMejor = Algoritmo3(mapa);
    do
    {
        RutaAleatoria = Algoritmo3(mapa);

        if(RutaAleatoria.distancia < RutaMejor.distancia)
            RutaMejor = RutaAleatoria;

        tfin = clock();
        numsecs = (int)(tfin-tini)/CLOCKS_PER_SEC;
    }while(numsecs<=tiempo_maximo);

    return RutaMejor;
}

tRuta Algoritmo5(tMapa mapa, int tiempo_maximo)
{
    tRuta RutaNueva, RutaMejor;
    clock_t tini, tfin;
    int numsecs;

    tini = clock();

    RutaMejor = Algoritmo3(mapa);
    do
    {
        RutaNueva = IntercambiaCiudades(RutaMejor, mapa);

        if(RutaNueva.distancia < RutaMejor.distancia)
            RutaMejor = RutaNueva;

        tfin = clock();
        numsecs = (int)(tfin-tini)/CLOCKS_PER_SEC;
    }while (numsecs<=tiempo_maximo);

    return RutaMejor;
}

tRuta IntercambiaCiudades(tRuta RutaOriginal,tMapa mapa)
{
    int p1,p2;
    tRuta ruta;

    ruta = RutaOriginal;

    p1 = rand()%(ruta.num_ciudades-1) +1;
    p2 = rand()%(ruta.num_ciudades-1) +1;

    ruta.recorrido[p1] = RutaOriginal.recorrido[p2];
    ruta.recorrido[p2] = RutaOriginal.recorrido[p1];

    ruta.CalculaDistancia(mapa);

    return ruta;
}

tRuta Algoritmo6(tMapa mapa, int tiempo_maximo)
{
    tRuta RutaNueva, RutaMejor;
    clock_t tini, tfin;
    int numsecs, i;
    double azar, probabilidad, T;

    tini = clock();

    RutaMejor = Algoritmo3(mapa);

    T = pow(tiempo_maximo, 2);

    do
    {
        for (i=0; i<100; i++)
        {
            RutaNueva = IntercambiaCiudades(RutaMejor, mapa);

            if(RutaNueva.distancia<= RutaMejor.distancia) RutaMejor = RutaNueva;
            else
            {
                probabilidad = exp ((double)(RutaMejor.distancia - RutaNueva.distancia)/(T*RutaMejor.distancia));
                azar = (double)rand()/RAND_MAX;
                if(probabilidad > azar) RutaMejor = RutaNueva;
            }
        }
        T = 0.995*T;
        tfin = clock();
        numsecs = (int)(tfin - tini)/CLOCKS_PER_SEC;
    }while(numsecs<=tiempo_maximo);

    return RutaMejor;
}

//EscogerAlgoritmo:  peque�o men� para seleccionar el algoritmo a probar
char EscogeAlgoritmo(void)
{
    char eleccion;
    cout << " PROBLEMA DEL VIAJANTE DEL COMERCIO " << endl << endl;
    cout << "1. Ruta por defecto" << endl;
    cout << "2. Algoritmo greedy de la ciudad mas cercana" << endl;
    cout << "3. Ruta aleatoria" << endl;
    cout << "4. Busqueda completamente aleatoria" << endl;
    cout << "5. Busqueda aleatoria dirigida" << endl;
    cout << "6. Busqueda aleatoria dirigida con simulated annealing" << endl;


    do
    {
        cout << "Escoja algotitmo: ";
        cin >> eleccion;
    }while((eleccion<'1')||(eleccion>'6'));
    cout << endl;

    return eleccion;
}

int PedirTiempoMaximo(void)
{
    int t;

    do{
        cout << "Introduzca numero maximo de segundos para la busqueda: ";
        cin >> t;

    }while ((t<=0) || (t>=MAX_TIME));

    return t;
}

//Funci�n principal
int main (void)
{
    tMapa mapa;
    tRuta ruta, rutamejor[3];
    int tiempo, i, repeticiones;
    double media[3];

    srand(time(NULL));
    mapa.LeerMapa();


    //Pedimos la repeticiones y el tiempo a emplear
    cout << "Introduce el numero de veces a repetir las 3 pruebas: ";
    cin >> repeticiones;

    cout << endl << "Introduce el tiempo para cada prueba: ";
    cin >> tiempo;
    cout << endl;


    //Inicializamos el vector a 0
    media[0] = 0;
    media[1] = 0;
    media[2] = 0;




    //Algoritmo 4
    rutamejor[0] = Algoritmo3(mapa);
    for(i=0; i<repeticiones; i++)
    {
        ruta = Algoritmo4(mapa, tiempo);
        if (ruta.distancia< rutamejor[0].distancia) rutamejor[0] = ruta;
        media[0] += ruta.distancia;
    }
    media[0] /= repeticiones;




    //Algoritmo 5
    rutamejor[1]=rutamejor[0];
    for(i=0; i<repeticiones; i++)
    {
        ruta = Algoritmo5(mapa, tiempo);
        if (ruta.distancia< rutamejor[1].distancia) rutamejor[1] = ruta;
        media[1] += ruta.distancia;
    }
    media[1] /= repeticiones;




    //Algoritmo 6
    rutamejor[2]=rutamejor[0];
    for(i=0; i<repeticiones; i++)
    {
        ruta = Algoritmo6(mapa, tiempo);
        if (ruta.distancia< rutamejor[2].distancia) rutamejor[2] = ruta;
        media[2] += ruta.distancia;
    }
    media[2] /= repeticiones;





    //Algoritmo 4
    cout << "El mejor resultado del cuarto algoritmo es:" << endl;
    rutamejor[0].MuestraRuta(mapa);
    cout << endl << "Y la distancia media: " << media[0] << "kms" << endl << endl;


    //Algoritmo 5
    cout << "El mejor resultado del quinto algoritmo es:" << endl;
    rutamejor[1].MuestraRuta(mapa);
    cout << endl << "Y la distancia media: " << media[1] << "kms" << endl << endl;


    //Algoritmo 6
    cout << "El mejor resultado del sexto algoritmo es:" << endl;
    rutamejor[2].MuestraRuta(mapa);
    cout << endl << "Y la distancia media: " << media[2] << "kms" << endl << endl;


    system("pause");

    return 0;
}
