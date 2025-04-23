#include <iostream>
using namespace std;

struct Nodo{
    int valor;
    Nodo *siguiente;
};

Nodo *crearNodo(int valorElemento) {
    Nodo *ap = new Nodo;
    ap -> valor = valorElemento;
    ap -> siguiente = nullptr;
    return ap;
}

void inicializar(Nodo *&frente, Nodo *&final) {
    frente = nullptr;
    final = nullptr;
}

int consultarFrente(Nodo *frente) {
    if (frente != nullptr) {
        cout << "El frente es: ";
        return frente -> valor;
    } else {
        cout << endl << "Cola vacía " << endl;
        return -1;
    }
}

bool vacia(Nodo *frente) {
    if (frente != nullptr) {
        return true;
    } else {
        return false;
    }
}

int sacar(Nodo *&frente, Nodo *& final) {
    Nodo *aux = crearNodo(frente -> valor);
    int elemento = aux -> valor;
    frente = frente -> siguiente;
    if (frente == nullptr) {
        final = nullptr;
    }
    delete aux;
    return elemento;
}

void agregar(Nodo *&frente, Nodo *&final, int elemento) {
    Nodo *aux = crearNodo(elemento);
    if (final == nullptr) {
        frente = aux;
    } else {
        final -> siguiente = aux;
    }
    final = aux;
}

void imprimirLista(Nodo *nodo) {
    if (nodo != nullptr) {
        cout << nodo -> valor << " ";
        imprimirLista(nodo -> siguiente);
    } else {
        cout << "eNulo" << " ";
    }
}

///////////////////////////////
// Ejercicios de la actividad//
///////////////////////////////
int tamanioLista(Nodo *frente) {
    if (frente != nullptr) {
        return 1 + tamanioLista(frente -> siguiente);
    } else {
        return 0;
    }
}

bool estaLlena(Nodo *frente, int tope) {
    if (tamanioLista(frente) >= tope) {
        return true;
    } else {
        return false;
    }
}

void vaciarCola(Nodo *&frente, Nodo *&final) {
    if (frente != nullptr) {
        sacar(frente, final);
        vaciarCola(frente, final);
    }
}

int main() {
    // Creación de los nodos frente y final
    Nodo *frente, *final;
    inicializar(frente, final);

    int n, elemento;
    cout << "\033[33mIngrese el numero de elementos que tendrá la lista: \033[0m";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\033[33mIngrese el elemento " << i+1 << " de la lista: \033[0m";
        cin >> elemento;
        agregar(frente, final, elemento);
    }

    cout << consultarFrente(frente);

    cout << endl << "\033[33mLos elementos de la lista son: \033[0m";
    imprimirLista(frente);
    /*int nSacar;
    cout << endl << "Digite un elemento para sacar de la lista: ";
    cin >> nSacar;*/
    cout << endl << "\033[33mSe saco el elemento \033[0m" << sacar(frente, final);

    cout << endl << "\033[33mEl tamanio de la lista es de \033[0m" << tamanioLista(frente);

    int nAgregar;
    cout << endl << "\033[33mDigite un elemento para agregar a la lista: \033[0m";
    cin >> nAgregar;
    agregar(frente, final, nAgregar);
    
    cout << endl << "\033[33mLos elementos de la lista son: \033[0m";
    imprimirLista(frente);

    int tope = tamanioLista(frente);
    if (estaLlena(frente, tope) == true) {
        cout << endl << "\033[33mLa cola esta llena\033[0m";
    } else {
        cout << endl << "\033[33mLa cola no esta llena\033[0m";
    }

    cout << endl << "\033[33mEl tamanio de la lista es de \033[0m" << tamanioLista(frente);

    vaciarCola(frente, final);
    
    cout << endl << "\033[33mLos elementos de la lista son: \033[0m";
    imprimirLista(frente);

    cout << endl << tamanioLista(frente);
    cout << endl << "\033[33mSe vacio la cola\033[0m";
    return 0;
}