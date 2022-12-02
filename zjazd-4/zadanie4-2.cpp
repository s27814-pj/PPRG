#include <iostream>


void ZeroThis(int results[], int max) {
    for (int i = 0; i < max; i++)results[i] = 0;
}

int CheckForValueInArray(int arra[], int value, int sizeARRAY) {
    for (int k = 0; k < (sizeARRAY + 1); k++) {
        if (arra[k] == value) return 1;
    }
    return 0;
}

int main()
{
    int size = 0;
    std::cout << "Podaj rozmiar tablicy, nastepnie po spacji wartosci(liczby calkowite) wszystkich elementow oddzielone spacja" << std::endl;
    std::cin >> size;
    if (size < 0) size = 0;
    int* array = new int[size];
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
    int HighestCountRepeatedValue = 0;
    int next = 0;
    int HighestValue = array[0];
    int* results = new int[size];
    ZeroThis(results, size);
    //results = { 0 };
    //for (int i = 0; i < size; i++) std::cout << results[i];
    for (int j = 0; j < size; j++)
    {
        int countRepeatedValue = 0;

        for (int i = 0; i < size; i++)
        {
            if (array[j] == array[i]) countRepeatedValue++;
            if (countRepeatedValue > HighestCountRepeatedValue)
            {
                HighestCountRepeatedValue = countRepeatedValue;
                HighestValue = array[j];
                ZeroThis(results, size);
                results[0] = HighestValue;
                next = 0;
            }
            else if (countRepeatedValue == HighestCountRepeatedValue) {
                if (CheckForValueInArray(results, array[j], next) != 1) {
                    next++;
                    results[next] = array[i];
                }
            }
        }
    }

    if (size != 0) if (next == 0) std::cout << "liczba wystapien naczestszego elementu = " << HighestCountRepeatedValue << "  / wartosc najczesciej wystepujacego elementu = " << HighestValue << std::endl;
    if (size != 0) if (next > 0) std::cout << "jest kilka roznych elementow ktore sa najczesciej podane:";
    if (size != 0) if (next > 0) for (int i = 0; i < (next + 1); i++) std::cout << results[i] << " ";
    delete[] array;
    delete[] results;
}
