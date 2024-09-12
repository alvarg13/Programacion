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

//Método LeerMapa(): extrae los datos del fichero y los copia
//sobre la matriz de distancias del objeto

void tMapa::LeerMapa(void)
{
    ifstream fichero;
    int i, j;

    fichero.open("distancias.txt");

    //Leer número de ciudades
    fichero >> num_ciudades;

    //Leer nombre de las ciudades
    for (i=0; i< num_ciudades; i++)
        for (j=0; j< num_ciudades; j++)
        fichero >> distancia[i][j];

    fichero.close();

    return;
}

//La clase tRuta almacena un posible recorrido, es decir,
//el orden en que se pueden recorrer las ciudades.
//Al final se le ñade la ciudad de origen como un elemento más.
//También guarda la distancia que supone dicho recorrido.

class tRuta
{
    public:
        int num_ciudades;
        int recorrido[MAX+1];
        int distancia;

        void CalculaDistancia(tMapa mapa);
        void MuestraRuta (tMapa mapa);
};

//Método CalculaDistancia(): calcula la distancia total de un recorrido.

void tRuta::CalculaDistancia(tMapa mapa)
{
    int i;

    distancia = 0;

    //Sumar la distancia entre cada dos ciudades del recorrido
    for (i=0; i<=num_ciudades; i++)
        distancia = distancia + maoa.distancia[recorrido[i-1]][recorrido[i]];

    return;
}

//Método MuestraResultado(): muestra en la pantalla la distancia
//de un recorrido y el orden en que hay que recorrer las
//ciudades, mostando sus nombres.

void tRuta::MuestraRuta(tMapa mapa)
{
    int i;

    cout << "Distancia: " << distancia << "Kms" << endl;
    cout << "Recorrido propuesto: " << endl;

    //Ciudades intermedias, cada 5 hago un salto de línea
    for (i=0; i<=num_ciudades; i++)
    {
        cout << mapa.nombre_ciudad[recorrido[i]] << " > ";
        if(i%5==0) cout << endl;
    }

    cout << endl;
    return;
}


//Algoritmo 1: calcula la ruta por defecto. Se coge como
//recorrido el orden en que aparecen en el fichero original

tRuta Algoritmo1(tMapa mapa)
{
    tRuta ruta;
    int i;

    ruta.num_ciudades = mapa.num_ciudades;
    for (i=0; i < ruta.num_ciudades; i++)
        ruta.recorrido[i] = i;

    //Se le añade la ciudad de partida al final del recorrido
    ruta.recorrido[ruta.num_ciudades] = 0;
    ruta.CalculaDistancia(mapa);

    return ruta;
}
