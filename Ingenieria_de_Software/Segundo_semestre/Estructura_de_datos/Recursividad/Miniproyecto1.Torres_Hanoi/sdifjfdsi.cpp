#include <iostream>
#include <conio.h>
using namespace std;

const int numTorres = 3;
const int discosMaximos = 20;

void inicializarTorre(int torre[discosMaximos]) {
    for (int i = 0; i < discosMaximos; i++) {
        torre[i] = 0;
    }
}

void agregarDisco(int torre[discosMaximos], int disco) {
    for (int i = 0; i < discosMaximos; i++) {
        if (torre[i] == 0) {
            torre[i] = disco;
            i = discosMaximos;
        }
    }
}

int quitarDisco(int torre[discosMaximos]) {
    for (int i = discosMaximos - 1; i >= 0; i--) {
        if (torre[i] != 0) {
            int disco = torre[i];
            torre[i] = 0;
            return disco;
        }
    }
    return 0;
}

void mostrarTorres(int torreA[discosMaximos], int torreB[discosMaximos], int torreC[discosMaximos], int numDiscos) {
    for (int nivel = numDiscos - 1; nivel >= 0; nivel--) {
        if (torreA[nivel] != 0 || torreB[nivel] != 0 || torreC[nivel] != 0){
            if (torreA[nivel] != 0) {
                cout << " " << torreA[nivel] << " ";
            } else {
                cout << " | ";
            }

            if (torreB[nivel] != 0) {
                cout << " " << torreB[nivel] << " ";
            } else {
                cout << " | ";
            }
    
            if (torreC[nivel] != 0) {
                cout << " " << torreC[nivel] << " ";
            } else {
                cout << " | ";
            }
            cout << endl;
        }
    }
    cout << "--------------------" << endl;
}

void moverDisco(int origen[discosMaximos], int destino[discosMaximos]) {
    int disco = quitarDisco(origen);
    agregarDisco(destino, disco);
}

void torresHanoi(int numDiscos, int torreA[discosMaximos], int torreB[discosMaximos], int torreC[discosMaximos], int origen, int destino, int auxiliar, int &paso) {
    if (numDiscos == 1) {
        // Mover el disco más pequeño de la torre de origen a la de destino
        if (origen == 0) {
            if (destino == 1) {
                moverDisco(torreA, torreB);
            } else {
                moverDisco(torreA, torreC);
            }
        }
        else if (origen == 1) {
            if (destino == 0) {
                moverDisco(torreB, torreA);
            } else {
                moverDisco(torreB, torreC);
            }
        }
        else {
            if (destino == 0) {
                moverDisco(torreC, torreA);
            } else {
                moverDisco(torreC, torreB);
            }
        }

        cout << "Paso " << paso++ + 1<<":"<<endl;
        mostrarTorres(torreA, torreB, torreC, discosMaximos);
        return;
    }

    // Mover de la torre de origen a la torre auxiliar
    torresHanoi(numDiscos - 1, torreA, torreB, torreC, origen, auxiliar, destino, paso);

    // Mover el disco más grande de la torre de origen a la torre de destino
    torresHanoi(1, torreA, torreB, torreC, origen, destino, auxiliar, paso);

    //Mover de la torre auxiliar a la torre de destino
    torresHanoi(numDiscos - 1, torreA, torreB, torreC, auxiliar, destino, origen, paso);
}

int main() {
    int numDiscos;
    cout << "Digite el numero de discos (maximo " << discosMaximos << "): ";
    cin >> numDiscos;

    if (numDiscos < 1 || numDiscos > discosMaximos) {
        cout << "Numero de discos no valido." << endl;
        return 1;
    }

    
    int torreA[discosMaximos], torreB[discosMaximos], torreC[discosMaximos];
    inicializarTorre(torreA);
    inicializarTorre(torreB);
    inicializarTorre(torreC);

    // Llenarlas
    for (int i = numDiscos; i >= 1; i--) {
        agregarDisco(torreA, i);
    }

    cout << "Estado actual de las torres:" << endl;
    mostrarTorres(torreA, torreB, torreC, numDiscos);

    int paso = 0;
    torresHanoi(numDiscos, torreA, torreB, torreC, 0, 2, 1, paso);

    cout<<"\033[93mPresiona cualquier tecla para continuar ...\033[0m";
    getch();
    return 0;
}