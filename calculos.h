#ifndef CALCULOS_H_INCLUDED
#define CALCULOS_H_INCLUDED


int lanzar() {
    return rand()%6+1;
}



int DibujarDado(int valor, int a, int b) {

    int x, y;
    x=(a*12)+5;
    y=(b*6)+0;

    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);

    for(int i=y+1;i<y+6;i++){
        rlutil::locate(x,i);
        cout<<"         ";
    }

    string dado[3] = {};
    switch(valor) {
    case 1: dado[1] = "    ×    ";
            break;
    case 2: dado[0] = "  ×      ";
            dado[2] = "      ×  ";
            break;
    case 3: dado[0] = "  ×      ";
            dado[1] = "    ×    ";
            dado[2] = "      ×  ";
            break;
    case 4: dado[0] = "  ×   ×  ";
            dado[2] = dado[0];
            break;
    case 5: dado[0] = "  ×   ×  ";
            dado[1] = "    ×    ";
            dado[2] = dado[0];
            break;
    case 6: dado[0] = "  × × ×  ";
            dado[2] = dado[0];
            break;

    }
    rlutil::locate(x,y+2);
    rlutil::setColor(rlutil::BLACK);
    cout<<dado[0];
    rlutil::locate(x,y+3);
    rlutil::setColor(rlutil::BLACK);
    cout<<dado[1];
    rlutil::locate(x,y+4);
    rlutil::setColor(rlutil::BLACK);
    cout<<dado[2];

    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    return 0;



}





/*
*********
*********
*
*
*********



*/









int getHigher(int vec[], int t) {
    int mayor;
    for(int i = 0; i < t; i++) if((i==0) || (vec[i]>mayor)) mayor = vec[i];
    return mayor;
}

int getSecondHigher(int vec[], int t) {
    int smayor, max;
    for(int i = 0; i < t; i++) {
        if(i==0) {
            max = vec[i];
            smayor = vec[i];
        }
        else if(vec[i]>max) {
            smayor = max;
            max = vec[i];
        }
        else if((vec[i] > smayor) || (i==1)) smayor = vec[i];
        else {}

        return smayor;

    }
}

int puntuacion (int dados[], int val) {
    int suma = 0;
    for(int i = 0; i < 5; i++) if(dados[i]==val) suma += dados[i];
    return suma*val;
}

int cuentaRepetidos (int vec[], int t, int num) {
    int cont = 0;
    for(int i = 0; i <= t; i++) if(vec[i] == num) cont++;
    return cont;
}

int indiceMayor (int vec[], int t) {
    int max, indice;
    for(int i = 0; i <= t; i++) {
        if((i==0)||(vec[i]>max)) {
            max = vec[i];
            indice = i;
        }
    }
    return indice;
}

char combinacion(int u) {
    char juego[10][11] = {
        "Juego de 1",
        "Juego de 2",
        "Juego de 3",
        "Juego de 4",
        "Juego de 5",
        "Juego de 6",
        "Escalera",
        "Full",
        "Póker",
        "Generala"
    };

    cout<<juego[u];
}

char cmayor (int vec[10], int t) {
    int f;
    char juego[10][11] = {
        "Juego de 1",
        "Juego de 2",
        "Juego de 3",
        "Juego de 4",
        "Juego de 5",
        "Juego de 6",
        "Escalera",
        "Full",
        "Póker",
        "Generala"
    };

    f = indiceMayor(vec,t);
    cout<<juego[f]<<endl;

    return 0;



}

void ordenarDados (int vec[]) {
    int temp;
    for(int i = 0; i < 5; i++) {
        if(vec[i] > vec[i+1]) {
            temp = vec[i];
            vec[i] = vec[i+1];
            vec[i+1] = temp;
        }
    }

}

#endif // CALCULOS_H_INCLUDED
