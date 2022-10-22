#include <iostream>

using namespace std;

int main()
{
    int n = 0, wynik=0;
    cout << "podaj n: ";
    cin >> n;
    if (n < 0) {
        cout << "wynik ponizej zera = " << n;
    }
    else {
        
        for (int i = 0; i <= n; i++) {
            for (int k=0; k<=i; k++) wynik += k;
        }
        cout << "suma szeregu = "<< wynik;

    }
}
