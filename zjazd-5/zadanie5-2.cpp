#include <iostream>
#include <vector>
#include <array>

using namespace std;


int main() {


    int size = 0;
    int moreSize = 1;
    cout << "Podaj 2 wymiary tablicy(oddzielone spacja), nastepnie po spacji wartosci(liczby calkowite) wszystkich elementow oddzielone spacja" << std::endl;
    cin >> size;
    cin >> moreSize;
    size = size * moreSize;
    if (size < 0) size = 0;
    //array<int, size>;
    int* somearray = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> somearray[i];
    }

    for (int i = 0; i < size; i++)
    {
        //for (int k = 0; k < moreSize; k++) {
            if (i % moreSize == 0) cout << endl;
            else cout << " ";
            cout << *(somearray + i);
        //}
        
    }
}
