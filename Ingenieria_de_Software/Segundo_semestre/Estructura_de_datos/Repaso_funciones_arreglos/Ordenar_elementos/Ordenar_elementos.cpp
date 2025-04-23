/*Una función que busque un elemento X en un arreglo A de
 tamaño N, y regrese 1 si el elemento se encuentra o 0 si el
 elemento no se encuentra.
 int buscarX(int a[], int n, int x)*/
#include <iostream>
using namespace std;

void insertarElementos(int arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Ingresa el elemento a[" << i << "]" << endl;
        cin >> arreglo[i];
    }
}

void mostrarElementos(int arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arreglo[i] << endl;
    }
}

void ordenar(int arreglo[], int n)
{
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (arreglo[i] < arreglo[j-1]) {
                int aux = arreglo[j-1];
                arreglo[j-1] = arreglo[i];
                arreglo[i] = aux;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;
    int arreglo[n];
    insertarElementos(arreglo, n);

    ordenar(arreglo, n);
    cout << "Elementos ordenados: " << endl;

    mostrarElementos(arreglo, n);
    return 0;
}