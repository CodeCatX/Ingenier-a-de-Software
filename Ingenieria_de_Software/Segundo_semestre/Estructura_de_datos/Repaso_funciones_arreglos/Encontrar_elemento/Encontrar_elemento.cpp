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
    for (int i = 0; i < n; i++)
    {

        cout << arreglo[i] << endl;
    }
}

int encontrarElemento(int arreglo[], int n, int x)
{
    int seEncuentra = 0;
    for (int i = 0; i < n; i++)
    {
        if (arreglo[i] == x)
        {
            seEncuentra = 1;
        }
    }
    return seEncuentra;
}

int main()
{
    int n;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;
    int arreglo[n];
    insertarElementos(arreglo, n);

    int x;
    cout << "Ingrese el numero a buscar en el arreglo: ";
    cin >> x;
    cout << encontrarElemento(arreglo, n, x);
    return 0;
}