#include <iostream>
using namespace std;

void imprimirArreglo(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void swap(int arr[], int pos1, int pos2) {
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(int arr[], int low, int hight, int pivot) {
    int i = low; int j = low;
    while (i <= hight) {
        if (arr[i] > pivot) {
            i++;
        }
        else {
            swap(arr, i, j);
            i++;
            j++;
        }
    }
    return j-1;
}

void quickSort(int arr[], int low, int hight) {
    if (low < hight) {
        int pivot = arr[hight];
        int pos = partition(arr, low, hight, pivot);
        quickSort(arr, low, pos-1);
        quickSort(arr, pos+1, hight);
    }
}

int main() {
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size-1);
    imprimirArreglo(arr, size);
    return 0;
}