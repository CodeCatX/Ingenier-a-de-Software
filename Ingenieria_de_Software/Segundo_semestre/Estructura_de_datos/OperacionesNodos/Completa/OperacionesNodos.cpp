#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *sig;
};

Nodo *crearNodo(int dato)
{
    Nodo *ap = new Nodo;
    ap->dato = dato;
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

void insertarOrdenado(Nodo *&head, int value){
    if (estaVacia(head) || head -> dato > value){
        Nodo *nuevo = crearNodo(value);
        nuevo -> sig = head;
        head = nuevo;
    } else {
        Nodo *actual = head;
        while (!estaVacia(actual) && !estaVacia(actual -> sig) && actual -> sig -> dato <= value){
            actual = actual -> sig;
        }
        Nodo *nuevo = crearNodo(value);
        nuevo -> sig = actual -> sig;
        actual -> sig = nuevo;
    }
}


void insertarOrdenadoRecursivo(Nodo *&head, int dato) {
    if (head == NULL || head -> dato >= dato) {
        Nodo *nuevo = new Nodo;
        nuevo -> dato = dato;
        nuevo -> sig = head;
        head = nuevo;
    } else {
        insertarOrdenadoRecursivo(head -> sig, dato);
    }
}

void imprimirRecursivo(Nodo *nodo)
{
    if (nodo != NULL)
    {
        cout << nodo->dato;
        if (nodo->sig != NULL)
        {
            cout << ", ";
        }
        imprimirRecursivo(nodo->sig);
    }
}

bool existeRecursivo(Nodo *nodo, int dato)
{
    if (nodo != NULL)
    {
        if (nodo->dato == dato)
        {
            return true;
        }
        else
        {
            return existeRecursivo(nodo->sig, dato);
        }
    }
    return false;
}

void eliminarNodo(Nodo *&head, int dato) {
    Nodo *actual = head;
    Nodo *anterior = NULL;
    while (actual != NULL) {
        if (actual -> dato == dato) {
            Nodo *aux = actual;
            actual = actual -> sig;

            if (anterior == NULL) {
                head = actual;
            } else {
                anterior -> sig = actual;
            }

            cout << "Se elimino el nodo con el valor " << aux -> dato << endl;
            delete aux;
            eliminarNodo(head -> sig, dato);
        } else {
            anterior = actual;
            actual = actual -> sig;
        }
    }
}

void eliminarNodoRecursivo(Nodo *&head, int dato)
{
    if(head != NULL) {
        if(head->dato == dato){
            Nodo *aux = head;
            head = head ->sig;
            delete aux;
            cout << "Se elimino " << dato << " del nodo." << endl;
            eliminarNodoRecursivo(head, dato);    
        } else {
            eliminarNodoRecursivo(head -> sig, dato);
        }
    }
}

/* 3. int posicion(Nodo *head, int dato): encontrar y mostrar la posición 
del dato proporcionado. Con recursión.*/
int posicion(Nodo *head, int dato) {
    if (head == NULL) {
        return -1;
    }
    if (head -> dato == dato) {
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
    if (head -> dato == dato) {
        head -> dato = nuevoDato;
    } else {
        return modificar(head -> sig, dato, nuevoDato);
    }
}

/*5. void eliminaDuplicados(Nodo *lista1, Nodo *&lista2): realice un 
procedimiento que copie una lista a otra, eliminando los duplicados, 
primero sin recursión y después utilizando recursión.*/
void eliminarDuplicadosRecursivo(Nodo *lista1, Nodo *&lista2) {
    if (lista1 != NULL) {
        insertarOrdenado(lista2, lista1 -> dato);
        eliminarDuplicadosRecursivo(lista1, lista2);
    }
}

int main()
{
    Nodo *head = NULL;

    int n, valor;
    cout << "Ingrese el numero de valores a ingresar en la lista: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Ingrese un numero para ingresar en la lista: ";
        cin >> valor;
        insertarOrdenado(head, valor);
    }

    int valorOrdenado;
    cout << "Ingrese un valor para insertar en la lista de manera ordenada: ";
    cin >> valorOrdenado;
    insertarOrdenado(head, valorOrdenado);

    int x;
    cout << "Inserta un numero para buscar en la lista: ";
    cin >> x;
    if (existeRecursivo(head, x) == true)
        cout << "Si existe" << endl;
    else
        cout << "No existe" << endl;

    int xPos;
    cout << "Ingrese un valor para obtener su posicion en la lista: ";
    cin >> xPos;
    cout << "El valor ingresado esta en la posicion " << posicion(head, xPos) << endl;  
    
    int xModificar, xNuevo;
    cout << "Ingrese un valor para modificar: ";
    cin >> xModificar;
    cout << "Ingrese el nuevo valor para reemplazar al anterior: ";
    cin >> xNuevo;
    modificar(head, xModificar, xNuevo);

    int xEliminar;
    cout << "Ingrese un valor para eliminar de la lista: ";
    cin >> xEliminar;
    eliminarNodo(head, xEliminar);

    Nodo *head2 = NULL;
    eliminarDuplicadosRecursivo(head, head2);

    cout << "Los valores de los nodos son: " << endl;
    cout << "La primera lista es: ";
    imprimirRecursivo(head);
    cout << "\nLa segunda lista es: ";
    imprimirRecursivo(head2);

    return 0;
}