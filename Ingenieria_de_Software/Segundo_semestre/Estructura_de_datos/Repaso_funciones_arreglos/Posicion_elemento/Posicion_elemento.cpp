/*Una función que regrese la posición de un dato X. Si no está,
 que regrese-1.
 int obtienePosX(int a[], int n, int x)*/
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
 
 int obtienePosX(int arreglo[], int n, int x)
 {
     int band = -1;
     int i = 0;
     while (i < n && band == -1) {
        if (arreglo[i] == x) {
            band = i;
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
 
     int x;
     cout << "Ingrese el numero a buscar en el arreglo: ";
     cin >> x;
     cout << obtienePosX(arreglo, n, x);
     return 0;
 }