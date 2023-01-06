#include <iostream>


using namespace std;

int main() {
	int n = 0, a = 0;
	cout << "podaj liczbe naturalna" << endl;
	cin >> n;
	for (; n > 0;) {
		if ((n % 5 == 0) && (n % 3 != 0)) {
			a++;
			n = n - 5;
			continue;
		}
		if (n % 5 == 0) {
			n = n - 5;
			continue;
		}
		n--;
	}
	cout << "liczba podzielnych przez 5 ale nie przez 3 i nie wiekszych od podanej jest: " << a;
}