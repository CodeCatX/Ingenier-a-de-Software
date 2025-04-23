#include <iostream>
using namespace std;
int main () {

    int n1 = 1;
    int n2 = 1;
    int n3;

    cout << n1 << ", " << n2 << ", ";
for (int i = 1; i <= 10; i++) {
    n3 = n1+n2;
    cout << n3 << " ";
    n2 = n1;
    n1 = n3;


}

    return 0;
}
