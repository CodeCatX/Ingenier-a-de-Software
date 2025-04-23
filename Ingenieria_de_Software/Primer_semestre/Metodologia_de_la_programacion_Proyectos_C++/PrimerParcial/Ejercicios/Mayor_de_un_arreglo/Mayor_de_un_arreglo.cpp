/*Una función que regrese el número mayor de un arreglo de
 enteros de tamaño N.
 int mayor(int a[], int n)*/
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
 
 int mayor(int arreglo[], int n)
 {
     int x = arreglo[0];
     for (int i = 1; i < n; i++)
     {
         if (arreglo[i] > x) {
             x = arreglo[i];
         }
     } 
     return x;
 }
 
 int main()
 {
     int n;
     cout << "Ingrese el tamaño del arreglo: ";
     cin >> n;
     int arreglo[n];
     insertarElementos(arreglo, n);
 
     cout << mayor(arreglo, n);
     return 0;
 }