#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *izq;
    Nodo *der;
};

Nodo *crearNodo(int x) {
    Nodo *ap = new Nodo;
    ap -> dato = x;
    ap -> izq = nullptr;
    ap -> der = nullptr;
    return ap;
}

void inicializar(Nodo *&root) {
    root = nullptr;
}

bool buscar(Nodo *root, int x) {
    if (root != nullptr) {
        if (x == root -> dato) {
            return true;
        }
        if (x < root -> dato) {
            return buscar(root -> izq, x);
        } else {
            return buscar(root -> der, x);
        }
    } else {
        return false;
    }
}

void insertar(Nodo *&root, int x) {
    if (root != nullptr) {
        if (x < root -> dato) {
            insertar(root -> izq, x);
        } else {
            insertar(root -> der, x);
        }
    } else {
        Nodo *nuevoNodo = crearNodo(x);
        root = nuevoNodo;
    }
}

void eliminar(Nodo *&root, int x) {
}

void inorder(Nodo *root) {
    if (root != nullptr) {
        inorder(root -> izq);
        cout << root -> dato << " ";
        inorder(root -> der);
    }
}

void preorder(Nodo *root) {
    if (root != nullptr) {
        cout << root -> dato << " ";
        preorder(root -> izq);
        preorder(root -> der);
    }
}

int altura(Nodo* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int alturaIzq = altura(root->izq);
        int alturaDer = altura(root->der);

        if (alturaIzq > alturaDer) {
            return alturaIzq + 1;
        } else {
            return alturaDer + 1;
        }
    }
}

int peso(Nodo *raiz) {
    if (raiz == nullptr) {
        return 0;
    } else {
        if (raiz -> izq == nullptr && raiz -> der == nullptr) {
            return 1;
        }
        int pesoTotalIzq  = peso(raiz -> izq);
        int pesoTotalDer = peso(raiz -> der);
        
        return pesoTotalIzq + pesoTotalDer;
    }
}

int numeroRamas(Nodo *root) {
    return 0;
}

void imprimirHijos(Nodo *raiz, int x) {
    if (raiz == nullptr ) {
        cout << "No se encontro el nodo con el valor " << x << endl;
    } else {
        if (raiz -> dato == x) {
            preorder(raiz);
        }  else {
            if (x < raiz -> dato) {
                imprimirHijos(raiz -> izq, x);
            } else {
                imprimirHijos(raiz -> der, x);
            }
        }
    }
}

int main() {
    Nodo *root;
    inicializar(root);
    insertar(root, 50);
    insertar(root, 30);
    insertar(root, 70);
    insertar(root, 20);
    insertar(root, 40);
    
    preorder(root);
    cout << "\nAltura: " << altura(root);
    cout << "\nPeso: " << peso(root) << endl;

    imprimirHijos(root, 30);
    return 0;
}

/*insertar(root, 50);
    insertar(root, 30);
    insertar(root, 70);
    insertar(root, 20);
    insertar(root, 40);
    insertar(root, 60);
    insertar(root, 80);
    insertar(root, 10);
    insertar(root, 25);
    insertar(root, 35);
    insertar(root, 45);
    insertar(root, 55);
    insertar(root, 65);
    insertar(root, 75);
    insertar(root, 85);*/