#ifndef COMBINACIONES_H_INCLUDED
#define COMBINACIONES_H_INCLUDED

int escalera (int cuentaIs[]) {
    int mayor = getHigher(cuentaIs, 6);

    if(mayor == 1) return 25;
    else return 0;

}

int full (int contador[]) {
    int mayor = getHigher(contador, 5)
      , segundoMayor = getSecondHigher(contador, 5);
    if((mayor==3)&&(segundoMayor==2)) return 30;
    else return 0;

}

int poker (int contador[]) {
    int mayor = getHigher(contador, 5);
    if(mayor==4) return 40;
    else return 0;
}

int generala (int contador[]) {
    int mayor = getHigher(contador, 5);
    if(mayor==5) return 50;
    else return 0;

}





#endif // COMBINACIONES_H_INCLUDED
