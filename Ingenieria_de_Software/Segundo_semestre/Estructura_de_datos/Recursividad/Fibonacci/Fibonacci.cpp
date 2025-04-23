/******************************************************************************
Cada nC:mero es la suma de sus dos predecesores, comenzando con 0 y 1.
- 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
*******************************************************************************/

#include <iostream>
using namespace std;

int fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void fibonacciIterativo(int n) {
    int n1 = 0, n2 = 1, suma = 0;
    cout << n1 << " " << n2 << " ";
    for (int i = 0; i < n-2; i++) {
        suma = n1 + n2;
        cout <<  suma << " ";
        n1 = n2;
        n2 = suma;
    }
}

int main()
{
	int n = 5;
	cout << fibonacci(n);

	return 0;
}