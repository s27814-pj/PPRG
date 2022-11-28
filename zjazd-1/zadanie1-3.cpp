#include <iostream>

// Komentarz: program nie dziala prawidlowo dla liczb ujemnych 

// Co zmienilem: liczby ujemne sa zamieniane na przeciwne

int main()
{
    int n;
    std::cin >> n;
    if (n < 0) n = n * (-1); // nowa linia dodana przy poprawianiu
    if (n == 0) std::cout << "Liczba nie jest parzysta i nie jest nieparzysta";
    else
    {
        if (((n + 1) / 2) == (n / 2)) std::cout << "Liczba jest parzysta";
        if (((n + 1) / 2) != (n / 2)) std::cout << "Liczba jest nieparzysta";
    }

}