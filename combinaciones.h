#ifndef COMBINACIONES_H_INCLUDED
#define COMBINACIONES_H_INCLUDED

int escalera (int dados[]) {
    bool esEscalera = true;
    int ant = dados[0];
    int a = 0;

    if(ant==1) a = 1;
    else if(ant == 2) a = 2;
    else esEscalera = false;
    int des = 0;

    for(int i = 0; i < 5; i++) {
        if(dados[i] == i+a) des = 0;
        else esEscalera = false;
    }

    if(esEscalera) return 25;
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
