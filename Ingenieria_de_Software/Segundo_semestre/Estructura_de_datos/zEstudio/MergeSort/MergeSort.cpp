#include <iostream>
using namespace std;

void imprimirArreglo(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void merge(int arr[], int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1 ;
    int n2 = fin - medio;
    int L[n1], M[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[inicio + i];
    }
    for (int j = 0; j < n2; j++) {
        M[j] = arr[medio + j + 1];
    }
    int i = 0, j = 0, k = inicio;
    while(i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
    cout << endl << "Arreglo k: ";
    imprimirArreglo(arr, fin);
}

void mergeSort(int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int mitad = inicio + (fin-inicio)/2;
        cout << endl <<"Size:" << mitad << endl;

        mergeSort(arr, inicio, mitad);
        mergeSort(arr, mitad + 1, fin);

        merge(arr, inicio, mitad, fin);
    }
}

int main() {
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0,size-1);
    cout << endl << "Arreglo ordenado: ";
    imprimirArreglo(arr, size);
    return 0;
}