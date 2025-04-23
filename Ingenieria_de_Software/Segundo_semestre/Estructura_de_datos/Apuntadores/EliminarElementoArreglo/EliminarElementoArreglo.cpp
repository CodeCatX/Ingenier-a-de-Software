/* 
Realice una función que elimine elementos de un arreglo.
 void vaciaArr(int a[], int n)
*/

#include <iostream>
using namespace std;

void imprimirArreglo(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

void vaciaArr(int a[], int n) {
    int *p;
    p = a;
    for (int i = 0; i < n; i++) {
        *p = '\0';
        p++;
    }
}

int main() {
    int n = 10;
    int a[n] = {1,2,3,4,5,6,7,8,9,10};
    imprimirArreglo(a, n);
    cout << endl;
    vaciaArr(a, n);
    imprimirArreglo(a, n);
    return 0;
}