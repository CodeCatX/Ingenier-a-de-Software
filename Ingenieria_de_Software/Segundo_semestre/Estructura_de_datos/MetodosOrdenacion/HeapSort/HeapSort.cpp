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

void heapify(int array[], int sizeHeap, int parentIndex) {
    int larger = parentIndex;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;
    if (leftChildIndex < sizeHeap && array[leftChildIndex] > array[larger]) {
        larger = leftChildIndex;
    }
    if (rightChildIndex < sizeHeap && array[rightChildIndex] > array[larger]) {
        larger = rightChildIndex;
    }
    if (larger != parentIndex) {
        swap(array, parentIndex, larger);
        heapify(array, sizeHeap, larger);
    }
    
}


void heapSort(int array[], int sizeArray) {
    for(int nonleafNodeIndex = sizeArray / 2 - 1; nonleafNodeIndex >= 0; nonleafNodeIndex--) {
        heapify(array, sizeArray, nonleafNodeIndex);
    }
    for (int lastHeapIndex = sizeArray - 1; lastHeapIndex >= 1; lastHeapIndex--) {
        swap(array, 0, lastHeapIndex);
        heapify(array, lastHeapIndex, 0);
    }    
}

int main() {
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, size);
    imprimirArreglo(arr, size);
    return 0;
}