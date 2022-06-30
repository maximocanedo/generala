#ifndef COMBINACIONES_H_INCLUDED
#define COMBINACIONES_H_INCLUDED

int escalera (int rep[]) {
    bool esEscalera = true;
    int g[6];
    for(int i = 0; i < 6; i++) g[i] = cuentaRepetidos(rep, 6, 1);
    int h = getHigher(g, 6);
    if(h == 5) esEscalera = true;
    else esEscalera = false;

    if(esEscalera) return 25;
    else return 0;

}

int full (int *contador) {
    int mayor = getHigher(contador, 6)
      , segundoMayor = getSecondHigher(contador, 6);
    if((mayor==3)&&(segundoMayor==2)) return 30;
    else return 0;

}

int poker (int rep[]) {
    int mayor = getHigher(rep, 6);
    if(mayor==4) return 40;
    return 0;
}

int generala (int rep[]) {
    int mayor = getHigher(rep, 6);
    if(mayor==5) return 50;
    return 0;

}





#endif // COMBINACIONES_H_INCLUDED
