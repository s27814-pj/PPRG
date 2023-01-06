#include <iostream>
#include <vector>
#include <array>

using namespace std;


void swapp(int anotherarray[], int a, int b) {
    int i = anotherarray[b];
    anotherarray[b] = anotherarray[a];
    anotherarray[a] = i;
}

int main() {


    int size = 0;
    int moreSize = 1;
    cout << "Podaj 2 wymiary tablicy(oddzielone spacja), nastepnie po spacji wartosci(liczby calkowite) wszystkich elementow oddzielone spacja" << std::endl;
    cin >> size;
    cin >> moreSize;
    //size = size * moreSize;
    if (size < 0) size = 0;
    //array<int, size>;
    int* somearray = new int[(size*moreSize)];

    for (int i = 0; i < (size*moreSize); i++)
    {
        cin >> somearray[i];
    }
    //swapp(somearray,1, 2);
    for (int i = 0; i < (size*moreSize); i++)
    {
        //for (int k = 0; k < moreSize; k++) {
        if (i % moreSize == 0) cout << endl;
        else cout << "\t";
        cout << *(somearray + i);
        //}

    }
    int n = 0;
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < moreSize; k++) {
            if (k == (moreSize / 2)) break;
            n = k % moreSize;
            swapp(somearray, (n + (i * moreSize)), ((moreSize - (n + 1)) + (i * moreSize)));
            //if (k % moreSize == 0) swapp(somearray, (k+(i*size)), ((moreSize - 1)+(i*size)));
            //if (k == (moreSize / 2)) break;
        }
    }
   
    cout << endl;

    for (int i = 0; i < (size*moreSize); i++)
    {
        //for (int k = 0; k < moreSize; k++) {
        if (i % moreSize == 0) cout << endl;
        else cout << "\t";
        cout << *(somearray + i);
        //}

    }

    cout << endl;
}
