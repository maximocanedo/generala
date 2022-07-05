#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <time.h>

using namespace std;


#include "rlutil.h"
#include "calculos.h"
#include "combinaciones.h"
#include "funciones.h"


void opcM(const char* text, int x, int y, bool s) { // Función que dibuja las opciones del menú principal.
    if(s) { // Si el elemento en cuestión está seleccionado..
        rlutil::setBackgroundColor(rlutil::YELLOW); // Se pinta el fondo de amarillo,
        rlutil::setColor(rlutil::BLACK); // Y se escribe en negro.
    } else  { // Si el elemento en cuestión no está seleccionado...
        rlutil::setBackgroundColor(rlutil::BLACK); // Pintamos el fondo de negro,
        rlutil::setColor(rlutil::WHITE); // Y escribimos en blanco.
    }
    rlutil::locate(x,y); // Nos ubicamos en la posición correspondiente...
    cout<<text<<endl; // Y escribimos finalmente el texto de la opción.

}

int main() {

    setlocale(LC_ALL, "");

    // Menú principal
    // Declaramos algunas variables...
    int opcion, y = 0;
    // Borramos la pantalla y ocultamos el cursor.
    rlutil::cls();
    rlutil::hidecursor();

    while(true) {
        // Borramos la pantalla
        rlutil::cls();
        // Ubicamos el cursor y escribimos en pantalla el título, el menú y sus opciones.
        rlutil::locate(10, 8);
        cout<<"¡GENERALA!"<<endl;
        rlutil::locate(10, 11);
        cout<<"Elegí una opción: "<<endl;
        opcM(" UN SÓLO JUGADOR ", 10, 13, (y==0));
        opcM(" DOS JUGADORES ", 10, 14, (y==1));
        opcM(" MOSTRAR PUNTAJE MÁS ALTO", 10, 15, (y==2));
        opcM(" SALIR ", 10, 16, (y==3));
        rlutil::locate(8, 13 + y);
        cout<<"»"<<endl;
        // Esperamos a que el usuario presione una tecla.
        int tecla = rlutil::getkey();
        // Una vez que presione una tecla, se analizará acá:
        switch(tecla) {
        case 14: // Si presionó la tecla de arriba,
            rlutil::locate(8, 13 + y); // El cursor se mueve hacia arriba.
            cout<<" "<<endl;
            y--;
            if(y < 0) y = 0; // Si al movernos hacia arriba no hay opciones, volvemos a cero.
            break;
        case 15: // Si presionó la tecla de abajo,
            rlutil::locate(8, 13 + y); // El cursor se mueve hacia abajo.
            cout<<" "<<endl;
            y++;
            if(y > 3) y = 3; // Si al movernos hacia abajo no hay más opciones, volvemos a la opción tres.
            break;
        case 1: // Si el usuario presionó [ENTER],

            switch(y) { // Analizamos cuál fue la opción que seleccionó el usuario:
            case 0: // Si fue la primera, comenzamos el juego con un jugador.
                comenzarJuego(1);
                break;
            case 1: // Si fue la segunda, comenzamos el juego con dos jugadores.
                comenzarJuego(2);
                break;
            case 2: // Si fue la tercera, mostramos el puntaje más alto.
               // mostrarPuntajeMasAlto(); // Descomentar una vez exista la función.
                break;
            case 3: // Si fue la cuarta, salimos del programa.
                exit(0);
                break;
            default:
                break;

            }

            break;
        }


}


    cout<<endl;
    system("pause");
    return 0;
}
