#ifndef CALCULOS_H_INCLUDED
#define CALCULOS_H_INCLUDED


int lanzar() {
    return rand()%6+1;
}

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
