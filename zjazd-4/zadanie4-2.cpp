#include <iostream>

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
    int HighestValue = array[0];
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
            }
        }
    }

    if (size != 0) std::cout << "liczba wystapien naczestszego elementu = " << HighestCountRepeatedValue << "  / wartosc najczesciej wystepujacego elementu = " << HighestValue << std::endl;
    delete[] array;
}
