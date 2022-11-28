#include <iostream>

int main()
{
    int size = 0;
    std::cout << "Podaj rozmiar tablicy, nastepnie po spacji wartosci(liczby calkowite) wszystkich elementow oddzielone spacja" << std::endl;
    std::cin >> size;
    if (size > 0)
    {
        int* array = new int[size];
        for (int i = 0; i < size; i++)
        {
            std::cin >> array[i];
        }
        int maxValue = array[0];
        for (int i = 0; i < size; i++)
        {
            if (maxValue < array[i]) maxValue = array[i];
        }
        std::cout << maxValue;
        delete[] array;
    }
}
