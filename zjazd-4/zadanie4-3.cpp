#include <iostream>
#include <iomanip> 

int main()
{

	int array[10][10] = { 0 };
	for (int i = 0; i < 10; i++) array[i][0] = i;
	for (int i = 0; i < 10; i++) array[i][1] = i + i;
	for (int i = 0; i < 10; i++) array[i][2] = i * i;
	for (int i = 0; i < 10; i++) array[i][3] = i+1 + 3+1;
	for (int i = 0; i < 10; i++) array[i][4] = i+1 - (4+1);


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			std::cout << std::setw(2);
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
