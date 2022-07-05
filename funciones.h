#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int comenzarJuego(int jugadoresCantidad) {

    setlocale(LC_ALL, "");

    // Declaramos algunas variables...
    const char hr[56] = "-------------------------------------------------------"; // El separador
    const int limite_jugadores = jugadoresCantidad;

    int puntaje[jugadoresCantidad] = {0} // Este vector acumulará el puntaje de cada jugador.
      , rondas[jugadoresCantidad] = {0} // Este vector acumulará la cantidad de rondas de cada jugador.
      , tiradas[jugadoresCantidad] = {0} // Este vector acumulará la cantidad de tiradas que hizo cada jugador.
      , combinacionesDisponibles[jugadoresCantidad][10] // Esta matriz guardará los puntajes de las combinaciones disponibles en cada partida por cada jugador.
      , combinaciones[jugadoresCantidad][10] // Esta matriz guardará los puntajes por cada combinación por cada jugador.
      , dados[5] // El indispensable vector de los dados.
      , cuentaIs[5] // Este vector cuenta los números repetidos de los dados. Por ejemplo, si en un lanzamiento uno obtiene {1, 2, 3, 3, 3} cuentaIs se verá algo así como {1, 1, 3, 0, 0}
      , jugadorAnterior = -1 // Esta variable guardará el índice del jugador anterior.
      , rondasEnTotal = 0 // Esta variable guardará la cantidad de rondas en total.
      , jugadorActual // Esta variable guardará el índice del jugador actual.
      , jugadorProximo; // Esta variable guardará el índice del jugador que sigue.

    bool tillGameEnds = true; // El valor en falso de este booleano detiene el juego. Al menos eso se supone.

    char nombre[jugadoresCantidad][31]; // Esta matriz guarda los nombres de los jugadores.
    rlutil::cls(); // Limpiamos la pantalla.


    // Vamos a pedir los nombres de nuestros jugadores:
    for(int i = 0; i < jugadoresCantidad; i++) {

        cout<<"Jugador "<<i<<", ingresá tu nombre (Max. 30 caracteres): ";
        cin>>nombre[i];
        cout<<endl;
        // Aprovechando el for, establecemos cada uno de los valores de combinaciones[][] en -1.
        for(int y = 0; y < 10; y++) combinaciones[i][y] = -1;

    } // Fin for de nombres de jugadores.

    // Pedimos al usuario que elija entre jugar normal o si quiere funciones avanzadas para poder probar el juego.
    cout<<endl<<endl<<"Elija la modalidad de juego: "<<endl<<endl;
    cout<<"[1] Juego normal (Dados aleatorios y tres rondas como máximo)"<<endl;
    cout<<"[9] Tester mode (Elegirás los dados y las rondas)"<<endl;
    int modoDeJuego;
    cout<<"Ingrese opción: "; cin>>modoDeJuego;
    // Este booleano indica si el modo de prueba está activado.
    bool testerMode = (modoDeJuego == 9);

    // Declaramos el límite de rondas, en tres por defecto.
    int LIM_RONDAS = 3;

    if(testerMode) { // Si el modo de prueba está activado,
        system("cls"); // Limpiamos la pantalla, y le pedimos al usuario que ingrese la cantidad máxima de rondas a jugar.
        cout<<"Ingrese la cantidad máxima de rondas que habrá en esta partida: "; cin>>LIM_RONDAS;
    }

    // ¡Que comience el juego!
    while(tillGameEnds) {

        // Establecemos quién jugará esta ronda.
        jugadorActual = jugadorAnterior + 1; // El siguiente jugador
        if(jugadorActual >= limite_jugadores) jugadorActual = 0; // Si el jugador anterior era el último
        else jugadorActual = jugadorAnterior + 1;


        // Sumamos una ronda a RondasEnTotal, y una para el jugador.
        rondasEnTotal++;
        rondas[jugadorActual]++;

        //Borramos la pantalla...
        system("cls");

        //En la cabecera mostramos el nombre de quién está jugando, su puntaje, y las rondas que lleva.
        cout<<endl<<"   Turno de: "<<nombre[jugadorActual]<<"       Puntaje: "<<puntaje[jugadorActual]<<" pts       Ronda: "<<rondas[jugadorActual]<<"/"<<LIM_RONDAS<<endl;
        cout<<hr;

        // Inicializamos los tiros en 1, dadosATirar en 5 (Porque en la primera tirada son cinco dados)
        int tiros = 1
          , dadosATirar = 5;
        tiradas[jugadorActual]++;

        //¡Lanzamos los dados!
        if(testerMode) { // Si el modo de prueba está activado, se le pide al usuario que ingrese los valores de los dados manualmente.
            cout<<endl;
            cout<<"TesterMode activado. Ingrese los valores de los dados manualmente: "<<endl;
            for(int i = 0; i < dadosATirar; i++) {
                cout<<"\t";
                cin>>dados[i];
            }
        } else { // Si no, los dados tendrán valores aleatorios.
            srand(time(NULL));
            for(int i = 0; i < dadosATirar; i++) dados[i] = rand()%6+1;
        }


        //Ordenamos los dados de menor a mayor valor.
        for(int xo = 0; xo < dadosATirar; xo++) {
            for(int i = 0; i < (dadosATirar - 1); i++) {
                if(dados[i] >dados[i+1]) {
                    int temp = dados[i];
                    dados[i] = dados[i+1];
                    dados[i+1] = temp;
                }
            }
        }


        cout<<endl;

        // Mostramos los lanzamientos de la ronda, y el total de lanzamientos que realizó el jugador.
        cout<<"   Lanzamiento "<<tiros<<"/3\tTotal de lanzamientos: "<<tiradas[jugadorActual]<<endl;
        cout<<hr<<endl;

        //Ahora mostramos por pantalla los dados lanzados y ya ordenados.
        for(int i = 0; i < dadosATirar; i++) cout<<"\t"<<dados[i];



        bool continuar = true;

        // Mientras el jugador quiera seguir tirando, o hasta que se le acaben los tiros, se ejecutará el siguiente código:
        while(continuar) {
            char decision;
            cout<<endl<<endl<<endl<<endl;

    ///

            cout<<"¿Continuar lanzando? S/N: ";
            cin>>decision; // Leemos la decisión del jugador.
            bool dijoQueSI = (decision == 'S' || decision == 's');

            if(dijoQueSI) { // Si el usuario decide lanzar de nuevo,

                cout<<endl<<"¿Cuántos dados? ";
                cin>>dadosATirar; // Le pedimos cuántos dados piensa tirar.
                for(int i = 0; i < dadosATirar; i++) { // Por cada dado que va a tirar, le pedimos la posición y lo lanzamos.
                    cout<<endl<<i+1<<"/"<<dadosATirar<<". ¿Qué dado vas a tirar? ";
                    int da; cin>>da; cout<<endl; // El usuario ingresa la posición natural del dado que desea tirar.
                    dados[da-1] = lanzar(); // A ese dado le damos otro valor aleatorio.
                    cout<<"Nuevo valor del dado "<<da<<": "<<dados[da-1]<<endl; // Lo notificamos por pantalla.

                }
                tiros++; // Contamos el lanzamiento de la ronda.
                tiradas[jugadorActual]++; // Contamos el lanzamiento del jugador.
                cout<<"   Lanzamiento "<<tiros<<"/3\tTotal de lanzamientos: "<<tiradas[jugadorActual]<<endl; // Mostramos la 'sub-cabecera' de los lanzmaientos.
                cout<<hr<<endl;
                for(int i = 0; i < 5; i++) cout<<"\t"<<dados[i]; // Y mostramos los dados de nuevo, con el valor cambiado.

            }
            else continuar = false; // Si el usuario escribe un valor distinto de 'S' o 's' terminamos acá.
            cout<<endl;

            if(tiros==3) continuar = false; // También se detiene al alcanzar el límite de los tres lanzamientos por ronda.

        }


        // Calculamos los puntajes de los primeros seis juegos.

        for(int i = 0; i < 6; i++) combinacionesDisponibles[jugadorActual][i] = puntuacion(dados, (i+1));

        // Calculamos las demás combinaciones (Escalera, Full, Póker y Generala).

        for(int i = 0; i < 6; i++) cuentaIs[i] = cuentaRepetidos(dados, 4, (i+1)); // Creamos el cuentaIs, que contendrá cuántas veces se repitió cada valor de los dados.

        combinacionesDisponibles[jugadorActual][6] = escalera(cuentaIs); // Si hay escalera, se suman 25pts. Si no, acá da cero.
        combinacionesDisponibles[jugadorActual][7] = full(cuentaIs); // Lo mismo, con full.
        combinacionesDisponibles[jugadorActual][8] = poker(cuentaIs); // Lo mismo, con póker.
        combinacionesDisponibles[jugadorActual][9] = generala(cuentaIs); // Lo mismo, con generala.
        bool esGeneralaServida = (rondas[jugadorActual] == 1) && (combinacionesDisponibles[jugadorActual][9] == 50); // Calculamos si hubo generala servida.

        if(esGeneralaServida) {
            tillGameEnds = false; // Por ahora, ante una generala servida, sólo detiene el while.
            // Esto queda por terminar.
            /*
                Cuando en la primera ronda del primer jugador saca generala servida, se le debe dar un turno al otro jugador para que empate.
                Si el jugador en cuestión sacó generala servida no en la primera ronda, gana automáticamente.
            */
        }

        cout<<endl<<endl<<"Combinaciones posibles: "<<endl;
        int cpp = 0; // Esta variable contará las combinaciones disponibles de los dados.

        for(int i = 0; i < 10; i++) {
            bool combinacionEncontrada = (combinacionesDisponibles[jugadorActual][i] != 0); // Si la combinación en cuestión tiene puntaje distinto de cero...
            if(combinacionEncontrada) cpp++; // Contamos uno.
        }

        int combinacionesPosibles[cpp] = {0}; // Este vector guardará los puntajes de las combinaciones que se pueden formar.
        int menujuegos[cpp] = {0}; // Este vector guardará los índices de las combinaciones que se pueden formar.
        int cp = 0;



        for(int i = 0; i < 10; i++) {
            bool hayCombinacion = (combinacionesDisponibles[jugadorActual][i] != 0) // Si la combinación en cuestión tiene puntaje distinto de cero...
               , noFueAnotado = (combinaciones[jugadorActual][i] == -1); // Y si no fue anotado previamente...

            if(hayCombinacion && noFueAnotado) {
                combinacionesPosibles[cp] = combinacionesDisponibles[jugadorActual][i]; // ... Se agrega al vector de combinaciones posibles.

                menujuegos[cp] = i; // Y se agrega al vector que guarda los índices que se pueden formar.

                cout<<"["<<cp<<"] "; combinacion(menujuegos[cp]); cout<<" : "<<combinacionesPosibles[cp]<<" pts. "<<endl; // Mostramos cada una de estas combinaciones

                cp++;
            }
        }
        int opc;
        cout<<"¿Qué juego elegís? ";
        cin>>opc; // Luego pedimos al jugador que elija el juego que prefiere anotar.



        // Una vez que el usuario elige, le confirmamos el puntaje que va a recibir.

        int puntajeGanador = combinacionesPosibles[opc]; // Devuelve el número de puntaje mayor. Por ejemplo: 50.
        int combinacionGanadora = menujuegos[opc]; // Devuelve el nombre de la combinación ganadora. Por ejemplo: "Generala"

        cout<<endl<<"Elegiste anotar '"; combinacion(combinacionGanadora); cout<<"' y obtendrás "<<puntajeGanador<<" puntos. ¿Continuar? "<<endl;
        cout<<"[1] Anotar y continuar. "<<endl;
        cout<<"[9] Anular ésta combinación. No podrás volver a anotarla durante el juego. "<<endl;
        int decision;
        cout<<"Ingrese opción: "; cin>>decision;

        if(decision!=9) { // Si el usuario elige anotar la combinación...
            // Le sumamos el puntaje obtenido en la ronda, al puntaje del jugador.
            puntaje[jugadorActual] += puntajeGanador;
            // "Tachamos" de alguna forma la combinación elegida, de forma que luego no podrá volver a elegirla en futuras rondas.
            combinaciones[jugadorActual][combinacionGanadora] = puntajeGanador;

        } else { // Si el usuario elige anular la combinación elegida...
            // "Tachamos" la combinación elegida, con cero, así no se puede volver a elegir.
            combinaciones[jugadorActual][combinacionGanadora] = 0;
        }


        system("pause");

        //Borramos la pantalla y mostramos el puntaje y a quién le tocará ahora.
        system("cls");

        //Antes, calculamos quién será el próximo jugador.
        if(jugadorActual >= (limite_jugadores - 1)) jugadorProximo = 0;
        else jugadorProximo = jugadorActual + 1;


        // Pantalla de entreo turnos.
        cout<<hr<<endl;
        cout<<"\t Jugador: "<<nombre[jugadorActual]<<". "<<endl;
        cout<<"\t Lanzamientos: "<<tiradas[jugadorActual]<<" ("<<tiros<<" en esta ronda). "<<endl;
        cout<<"\t Rondas: "<<rondas[jugadorActual]<<"/"<<LIM_RONDAS<<". "<<endl;
        cout<<"\t Puntaje total: "<<puntaje[jugadorActual]<<" pts. (+"<<puntajeGanador<<" pts)"<<endl;
        cout<<endl<<"\t Próximo turno: "<<nombre[jugadorProximo]<<endl;
        cout<<endl<<hr<<endl;

        system("pause");

        jugadorAnterior = jugadorActual;

        if(rondasEnTotal==(limite_jugadores*LIM_RONDAS)) tillGameEnds = false;








    }

    int mayorPuntaje = getHigher(puntaje, limite_jugadores - 1);
    int ganador = indiceMayor(puntaje, limite_jugadores - 1);

    system("cls");
    cout<<hr<<endl;
    cout<<"\t Ganador: "<<nombre[ganador]<<". "<<endl;
    cout<<"\t Puntaje total: "<<puntaje[ganador]<<" pts. "<<endl;
    cout<<"\t Tiradas hechas: "<<tiradas[ganador]<<". "<<endl;
    cout<<endl<<"\t Puntajes: "<<endl;
    for(int j = 0; j < jugadoresCantidad; j++) cout<<"\t "<<nombre[j]<<": "<<puntaje[j]<<" pts. "<<endl;
    cout<<endl<<hr<<endl;
    system("pause");




    return 0;

}




#endif // FUNCIONES_H_INCLUDED
