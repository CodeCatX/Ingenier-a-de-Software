#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo {
    int coeficiente;
    int exponente;
    Nodo *sig;
};

void inicializar(Nodo *&frente, Nodo *&final) {
    frente = nullptr;
    final = nullptr;
}

void ingresarTermino(Nodo *&frente, Nodo *&final) {
    int coeficienteAux, exponenteAux;
    cout << "\033[93mIngrese el coeficiente: \033[0m";
    cin >> coeficienteAux;
    cout << "\033[93mIngrese el exponente: \033[0m";
    cin >> exponenteAux;

    Nodo *aux = new Nodo;
    aux -> coeficiente = coeficienteAux;
    aux -> exponente = exponenteAux;
    aux -> sig = nullptr;

    if (final == nullptr) {
        frente = aux;
    } else {
        final -> sig = aux;
    }
    final = aux;
    cout << endl;
}

int potencia(int b, int e) {
    if (e == 0) {
        return 1;
    } else {
        return b * potencia(b, e-1);
    }
}

void insertarPolinomio(Nodo *&frente, Nodo *&final, int nTerminos) {
    if (nTerminos != 0) {
        ingresarTermino(frente, final);
        insertarPolinomio(frente -> sig, final, nTerminos-1);
    }
}

void desplegarPolinomio(Nodo *frente, bool primerTermino) {
    if (frente != nullptr) {
        if (!primerTermino && frente->coeficiente > 0) {
            cout << " + ";
        }
        if (frente->exponente == 0) {
            cout << frente->coeficiente;
        } else {
            cout << frente->coeficiente << "x^" << frente->exponente;
        }
        desplegarPolinomio(frente->sig, false);
    }
}
int evaluarPolinomio(Nodo *frente, int x) {
    if (frente == nullptr) {
        return 0;
    } else {
        return frente->coeficiente * potencia(x, frente->exponente) + 
        evaluarPolinomio(frente->sig, x);
    }
}


int main() {
    Nodo *frente, *final;
    inicializar(frente, final);

    int nTerminos;
    cout << "\033[93mIngrese el numero de terminos del polinomio: \033[0m";
    cin >> nTerminos;
    insertarPolinomio(frente, final, nTerminos);
    desplegarPolinomio(frente, true);
    int x;
    cout << "\n\033[93mIngrese un valor para x: \033[0m";
    cin >> x;
    cout << "\n\033[93mEl resultado es: \033[0m";
    cout << evaluarPolinomio(frente, x);

    cout << endl << "\033[94mPulse una tecla para cerrar el programa...\033[0m";
    getch();
    return 0;
}