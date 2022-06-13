#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int comenzarJuego(int jugadoresCantidad) {

    setlocale(LC_ALL, "");


    const char hr[51] = "--------------------------------------------------";
    const int limite_jugadores = jugadoresCantidad;
    const int LIM_RONDAS = 3;
    int puntaje[jugadoresCantidad] = {0}
      , rondas[jugadoresCantidad] = {0}
      , punt[jugadoresCantidad][10]
      , dados[5]
      , cuentaIs[5]
      , jugadorAnterior = -1
      , rondasEnTotal = 0
      , jugadorActual
      , jugadorProximo;

    bool tillGameEnds = true;

    char nombre[jugadoresCantidad][31];
    rlutil::cls();


    // Vamos a pedir los nombres de nuestros jugadores:
    for(int i = 0; i < jugadoresCantidad; i++) {
        cout<<"Jugador "<<i<<", ingresá tu nombre (Max. 30 caracteres): ";
        cin>>nombre[i];
        cout<<endl;
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

        int tiros = 0
          , dadosATirar = 5;

        //¡Lanzamos los dados!
        for(int i = 0; i < dadosATirar; i++) dados[i] = 6; //lanzar();


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


        //Ahora mostramos por pantalla los dados lanzados y ya ordenados.
        //cout<<endl;
       // for(int i = 0; i < dadosATirar; i++) cout<<"\t"<<i;
        cout<<endl;
        for(int i = 0; i < dadosATirar; i++) DibujarDado(dados[i], i, 1);



        bool continuar = true;

        // Mientras el jugador quiera seguir tirando, o hasta que se le acaben los tiros, se ejecutará el siguiente código:
        while(continuar) {
            char decision;
            cout<<endl<<endl<<endl<<endl<<endl;

    ///

            cout<<"¿Continuar lanzando? S/N: ";
            cin>>decision;
            if(decision == 'S') {

                cout<<endl<<"¿Cuántos dados? ";
                cin>>dadosATirar;
                for(int i = 0; i < dadosATirar; i++) {
                    cout<<endl<<i+1<<"/"<<dadosATirar<<". ¿Qué dado vas a tirar? ";
                    int da; cin>>da;
                    dados[da-1] = lanzar();
                    for(int i = 0; i < dadosATirar; i++) DibujarDado(dados[i], i, 1);


                }
            }
            else continuar = false;
            tiros++;
            if(tiros==3) continuar = false;

        }


        // Calcular los juegos

        for(int i = 0; i < 6; i++) punt[jugadorActual][i] = puntuacion(dados, (i+1));

        // Calcular las demás combinaciones

        for(int i = 0; i < 6; i++) cuentaIs[i] = cuentaRepetidos(dados, 4, (i+1));

        punt[jugadorActual][6] = escalera(dados); // Si hay escalera, se suman 25pts. Si no, acá da cero.
        punt[jugadorActual][7] = full(cuentaIs); // Lo mismo, con full.
        punt[jugadorActual][8] = poker(cuentaIs); // Lo mismo, con póker.
        punt[jugadorActual][9] = generala(cuentaIs); // Lo mismo, con generala.
        bool esGeneralaServida = (rondas[jugadorActual] == 1) && (punt[jugadorActual][9] == 50);

        if(esGeneralaServida) {
            tillGameEnds = false;
            // break;
            // Ha ganado. Termina el juego e inmediatamente se convierte en ganador.
            // PENDIENTE.
        }

        cout<<"Combinaciones posibles: "<<endl;
        int cpp = 0;
        for(int i = 0; i < 10; i++) {
            if(punt[jugadorActual][i] != 0) cpp++;
        }

        int combinacionesPosibles[cpp] = {0};
        int menujuegos[cpp] = {0};
        int cp = 0;
        for(int i = 0; i < 10; i++) {

            if(punt[jugadorActual][i] != 0) {

                combinacionesPosibles[cp] = punt[jugadorActual][i];
                menujuegos[cp] = i;

                cout<<"["<<cp<<"] "; combinacion(menujuegos[cp]);cout<<" : "<<combinacionesPosibles[cp]<<" pts. "<<endl;

                cp++;
            }
        }
        int opc;
        cout<<"¿Qué juego elegís? ";
        cin>>opc;



        // Ahora que tenemos todos los puntajes de las combinaciones posibles, buscamos el mayor.
        int puntajeGanador = combinacionesPosibles[opc]; // Devuelve el número de puntaje mayor. Por ejemplo: 50.
        int combinacionGanadora = menujuegos[opc]; // Devuelve el nombre de la combinación ganadora. Por ejemplo: "Generala"

        // Le sumamos el puntaje obtenido en la ronda, al puntaje del jugador.
        puntaje[jugadorActual] += puntajeGanador;

        system("pause");

        //Borramos la pantalla y mostramos el puntaje y a quién le tocará ahora.
        system("cls");

        //Antes, calculamos quién será el próximo jugador.
        if(jugadorActual >= (limite_jugadores - 1)) jugadorProximo = 0;
        else jugadorProximo = jugadorActual + 1;


        cout<<hr<<endl;
        cout<<"\t Jugador: "<<nombre[jugadorActual]<<". "<<endl;
        cout<<"\t Tiros en esta ronda: "<<tiros<<". "<<endl;
        cout<<"\t Rondas: "<<rondas[jugadorActual]<<"/"<<LIM_RONDAS<<". "<<endl;
        cout<<"\t Puntaje total: "<<puntaje[jugadorActual]<<" pts. "<<endl;
        cout<<endl<<"\t Próximo turno: "<<nombre[jugadorProximo]<<endl;
        cout<<endl<<hr<<endl;

        system("pause");

        jugadorAnterior = jugadorActual;

        if(rondasEnTotal==(limite_jugadores*LIM_RONDAS)) tillGameEnds = false;








    }

    int mayorPuntaje = getHigher(puntaje, limite_jugadores - 1);
    int ganador = indiceMayor(puntaje, limite_jugadores - 1);

    cout<<hr<<endl;
    cout<<"\t Ganador: "<<nombre[ganador]<<". "<<endl;
    cout<<endl<<"\t Puntajes: "<<endl;
    for(int j = 0; j < jugadoresCantidad; j++) cout<<"\t "<<nombre[j]<<": "<<puntaje[j]<<" pts. "<<endl;
    cout<<endl<<hr;




    return 0;

}

#endif // FUNCIONES_H_INCLUDED
