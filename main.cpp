#include <iostream>
#include <cstdlib>
#include <locale.h>

using namespace std;

#include "rlutil.h"
#include "calculos.h"
#include "combinaciones.h"
#include "funciones.h"

void opcM(const char* text, int x, int y, bool s) {
    if(s) {
        rlutil::setBackgroundColor(rlutil::YELLOW);
        rlutil::setColor(rlutil::BLACK);
    }
    else  {
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
    }
    rlutil::locate(x,y);
    cout<<text<<endl;

}

int main()
{
    setlocale(LC_ALL, "");

    // Menú principal
    int opcion;
    rlutil::cls();
    int y = 0;
    rlutil::hidecursor();
while(true) {
   // rlutil::cls();

    rlutil::locate(10, 8);
    cout<<"GENERALA"<<endl;
    rlutil::locate(10, 11);
    cout<<"Seleccioná el modo de juego: "<<endl;
    opcM(" UN SÓLO JUGADOR ", 10, 13, (y==0));
    opcM(" DOS JUGADORES ", 10, 14, (y==1));
    opcM(" TRES JUGADORES ", 10, 15, (y==2));
    opcM(" CUATRO JUGADORES ", 10, 16, (y==3));
    rlutil::locate(8, 13 + y);
    cout<<"»"<<endl;

    int tecla = rlutil::getkey();
    switch(tecla) {
    case 14: //UP
        rlutil::locate(8, 13 + y);
        cout<<" "<<endl;
        y--;
        if(y < 0) y = 0;
        break;
    case 15: //DOWN
        rlutil::locate(8, 13 + y);
        cout<<" "<<endl;
        y++;
        if(y > 3) y = 3;
        break;
    case 1: //ENTER

        switch(y) {
        case 0:
            comenzarJuego(1);
            break;
        case 1:
            comenzarJuego(2);
            break;
        case 2:
            comenzarJuego(3);
            break;
        case 3:
            comenzarJuego(4);
            break;
        default:
            break;

        }

        break;
    }


}


    cin>>opcion;

    switch(opcion) {
    case 1:
       // comenzarJuego(1);
       rlutil::locate(10, 15);

        break;
    case 2:
        comenzarJuego(2);
        break;
    case 3:
        comenzarJuego(3);
    default:
        cout<<"La opción ingresada no es válida. "<<endl;
    }

    cout<<endl;
    system("pause");
    return 0;
}
