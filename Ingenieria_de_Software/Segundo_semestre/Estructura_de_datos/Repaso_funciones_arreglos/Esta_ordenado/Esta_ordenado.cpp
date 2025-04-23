/*Una función que regrese un 1 si el arreglo está ordenado de
 menor a mayor y un 0 en cualquier otro caso.
 Recuerda que al encontrar una pareja desordenada, todo el
 arreglo estará desordenado.
 int estaOrdenado(int a[], int n)
*/
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

int estaOrdenado(int arreglo[], int n)
{
    int band = 0;
    int i = 0;
    while (band != 1 && i < n) {
        if (arreglo[i] > arreglo[i-1]) {
            band = 1;
        }
        i++;
    }
    return band;
}

int main()
{
    int n;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;
    int arreglo[n];
    insertarElementos(arreglo, n);

    cout << estaOrdenado(arreglo, n);
    return 0;
}