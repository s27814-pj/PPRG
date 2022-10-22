#include <iostream>

using namespace std;

int main(){

	int a = 0, b = 0;
	cout << "podaj dodatnie a i b oddzielone spacja: ";
	cin >> a >> b;
	cout << "podane liczba a =" << a << " podana liczba b = " << b << endl;
	cout << endl << "w nastepnej lini wiersz gwiazdek od dlugosci a" << endl;
	for (int i = 0; i < a; i++)
		cout << "*";
	cout << endl << endl << "ponizej kolumna gwiazdek od dlugosci b" << endl;
	for (int i = 0; i < b; i++)
		cout << "*" <<endl;

	cout << endl << endl << "ponizej wypelniony prostokat gwiazdek o a i b" << endl;
	for (int i = 0; i < b; i++) {
		for (int k = 0; k < a; k++) cout << "*";
		cout << endl;
	}

	cout << endl << endl << "ponizej obwod prostokata gwiazdek o a i b" << endl;
	for (int i = 0; i < b; i++) {
		for (int k = 0; k < a; k++) {
			if (((k == 0) || (k == (a - 1))) || (i==0) || (i==(b-1))) cout << "*";
			else {
				cout << " ";
			}

		}
		cout << endl;
	}


}
