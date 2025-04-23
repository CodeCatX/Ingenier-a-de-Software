#include <iostream>
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
    // 1. Crear el nuevo nodo
    Nodo *nuevo = new Nodo;
    nuevo->valor = dato;
    nuevo->sig = NULL;  // Inicialmente, no apunta a ningún nodo

    // 2. Si la lista está vacía, el nuevo nodo se convierte en la cabeza
    if (head == NULL) {
        head = nuevo;
    } 
    // 3. Si el nuevo dato es menor o igual al dato del primer nodo, inserta al inicio
    else if (dato <= head->valor) {
        nuevo->sig = head;
        head = nuevo;
    } 
    // 4. Si el nuevo dato debe insertarse en medio o al final:
    else {
        Nodo *anterior = head;        // Empieza en la cabeza
        Nodo *actual = head->sig;       // El nodo siguiente a la cabeza
        // Recorre la lista hasta encontrar el primer nodo cuyo valor sea mayor o igual a 'dato'
        while (actual != NULL && actual->valor < dato) {
            anterior = actual;
            actual = actual->sig;
        }
        // Inserta 'nuevo' entre 'anterior' y 'actual'
        nuevo->sig = actual;
        anterior->sig = nuevo;
    }
}


void insertarOrdenadoRecursivo(Nodo *&head, int dato) {
    if (head == NULL || head -> valor >= dato) {
        Nodo *nuevo = new Nodo;
        nuevo -> valor = dato;
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
    if (nodo != NULL)
    {
        if (nodo->valor == dato)
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
        if (actual -> valor == dato) {
            Nodo *aux = actual;
            actual = actual -> sig;

            if (anterior == NULL) {
                head = actual;
            } else {
                anterior -> sig = actual;
            }

            cout << "Se elimino el nodo con el valor " << aux -> valor << endl;
            delete aux;
        } else {
            anterior = actual;
            actual = actual -> sig;
        }
    }
}

void eliminarNodoRecursivo(Nodo *&head, int dato)
{
    if(head != NULL) {
        if(head->valor == dato){
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

int main()
{
    // Se inicializa la cabeza de la lista y el primer nodo como NULL
    Nodo *head = NULL;

    // Se crea el primer nodo
    int n, valor;
    cout << "Ingrese el numero de valores a ingresar en la lista: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Ingrese un numero para ingresar en la lista: ";
        cin >> valor;
        insertarRecursivo(head, valor);
    }

    int valorOrdenado;
    cout << "Ingrese un valor para insertar en la lista de manera ordenada: ";
    cin >> valorOrdenado;
    insertarOrdenadoRecursivo(head, valorOrdenado);

    int x;
    cout << "Inserta un numero para buscar en la lista: ";
    cin >> x;
    if (existeRecursivo(head, x) == true)
        cout << "Si existe" << endl;
    else
        cout << "No existe" << endl;

    int xEliminar;
    cout << "Ingrese un valor para eliminar de la lista: ";
    cin >> xEliminar;
    eliminarNodo(head, xEliminar);

    cout << "Los valores de los nodos son: ";
    imprimirRecursivo(head);

    return 0;
}