#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo
{
    int valor;
    Nodo *sig;
};

Nodo *crearNodo(int dato)
{
    Nodo *ap = new Nodo;
    ap->valor = dato;
    ap->sig = NULL;
    return ap;
}

bool estaVacia(Nodo *head)
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void insertarRecursivo(Nodo *&nodo, int dato)
{
    if (estaVacia(nodo) == true)
    {
        nodo = crearNodo(dato);
    }
    else if (nodo->sig == NULL)
    {
        nodo->sig = crearNodo(dato);
    }
    else
    {
        return insertarRecursivo(nodo->sig, dato);
    }
}

void insertarOrdenado(Nodo *&head, int dato) {
    Nodo *nuevo = new Nodo;
    nuevo->valor = dato;
    nuevo->sig = NULL;

    if (head == NULL) {
        head = nuevo;
    } else if (dato <= head->valor) {
        nuevo->sig = head;
        head = nuevo;
    } else {
        Nodo *anterior = head;
        Nodo *actual = head->sig;

        while (actual != NULL && actual->valor < dato) {
            anterior = actual;
            actual = actual->sig;
        }

        nuevo->sig = actual;
        anterior->sig = nuevo;
    }
}


void imprimirRecursivo(Nodo *nodo)
{
    if (nodo != NULL)
    {
        cout << nodo->valor;
        if (nodo->sig != NULL)
        {
            cout << ", ";
        }
        imprimirRecursivo(nodo->sig);
    }
}

bool existeRecursivo(Nodo *nodo, int dato)
{
    if (nodo == NULL)
    {
        return false;
    }
    if (nodo->valor == dato)
    {
        return true;
    }
    return existeRecursivo(nodo->sig, dato);
}


void eliminarNodo(Nodo *&head, int dato) {
    Nodo *actual = head;
    Nodo *anterior = NULL;
    while (actual != NULL) {
        if (actual -> valor == dato) {
            Nodo *aux = actual;
            actual = actual -> sig;

            if (anterior == NULL) {
                head = actual;
            } else {
                anterior -> sig = actual;
            }
            cout << "\033[33mSe elimino el nodo con el valor " << aux -> valor << "\033[0m" << endl;
            delete aux;
        } else {
            anterior = actual;
            actual = actual -> sig;
        }
    }
}

/* 3. int posicion(Nodo *head, int dato): encontrar y mostrar la posición 
del dato proporcionado. Con recursión.*/
int posicion(Nodo *head, int dato) {
    if (head == NULL) {
        return -1;
    }
    if (head -> valor == dato) {
        return 0;
    } else {
        int result = posicion(head -> sig, dato);
        if (result == -1){
            return -1;
        } else {
            return 1 + result;
        }
    }
}

/*4. modificar(Nodo *head, int dato, int nuevoDato): encuentra el nodo 
que contenga el dato proporcionado y modifica su valor por el 
nuevo dato. Con recursión. */
void modificar(Nodo *&head, int dato, int nuevoDato) {
    if (head != NULL) {
        if (head -> valor == dato) {
            head -> valor = nuevoDato;
        } else {
            modificar(head -> sig, dato, nuevoDato);
        }
    }
}

/*5. void eliminaDuplicados(Nodo *lista1, Nodo *&lista2): realice un 
procedimiento que copie una lista a otra, eliminando los duplicados, 
primero sin recursión y después utilizando recursión.*/

// Iterativo
void eliminarDuplicados(Nodo *lista1, Nodo *&lista2) {
    while (lista1 != NULL) {
        if (existeRecursivo(lista2, lista1 -> valor) == false) {
            insertarOrdenado(lista2, lista1 -> valor);
        }
        lista1 = lista1 -> sig;
    }
}

// Con recursión
void eliminarDuplicadosRecursivo(Nodo *lista1, Nodo *&lista2) {
    if (lista1 != NULL) {
        if (existeRecursivo(lista2, lista1 -> valor) == false) {
            insertarOrdenado(lista2, lista1 -> valor);
        }
        eliminarDuplicadosRecursivo(lista1 -> sig, lista2);
    }
}

int main()
{
    Nodo *head = NULL;

    int n, valor;
    cout << "\033[36mIngrese el numero de valores a ingresar en la lista: \033[0m";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\033[36mIngrese un numero para ingresar en la lista: \033[0m";
        cin >> valor;
        insertarOrdenado(head, valor);
    }
    
    cout << "\033[36mLa lista es: \033[0m";
    imprimirRecursivo(head);

    int xEliminar;
    cout << endl << "\033[36mIngrese un valor para eliminar de la lista: \033[0m";
    cin >> xEliminar;
    eliminarNodo(head, xEliminar);

    cout << "\033[36mLa lista es: \033[0m";
    imprimirRecursivo(head);

    int xPos;
    cout << endl << "\033[36mIngrese un valor para obtener su posicion en la lista: \033[0m";
    cin >> xPos;
    cout << "\033[36mEl valor ingresado esta en la posicion \033[0m" << posicion(head, xPos) << endl;
    
    int xModificar, xNuevo;
    cout << "\033[36mIngrese un valor para modificar: \033[0m";
    cin >> xModificar;
    cout << "\033[36mIngrese el nuevo valor para reemplazar al anterior: \033[0m";
    cin >> xNuevo;
    modificar(head, xModificar, xNuevo);

    cout << "\033[36mLa lista es: \033[0m";
    imprimirRecursivo(head);

    Nodo *head2 = NULL;
    eliminarDuplicadosRecursivo(head, head2);
    cout << endl << "\033[36mSe copiaron los valores de la lista 1 a otra lista. Los valores de las listas son: \033[0m" << endl;
    cout << "\033[36mLa primera lista es: \033[0m";
    imprimirRecursivo(head);
    cout << endl <<  "\033[36mLa segunda lista es: \033[0m";
    imprimirRecursivo(head2);

    cout << endl <<  "\033[33mPulse una tecla para cerrar el programa...\033[0m";
    getch();
    return 0;
}