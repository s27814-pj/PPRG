#include <iostream>
#include <string>


using namespace std;


struct stud {
	string imie;
	short int inf;
	short int mat;
	short int che;
	short int pol;
};

int main() {

	struct stud listaStud[6];
	int n = 0, a = 0, b = 0;
	for (int i = 0; i < 6; i++) {
		cout << "Podaj imie nr " << i + 1 << ": " << endl;
		cin >> listaStud[i].imie;
		cout << "Podaj ocene informatyki: " << endl;
		cin >> listaStud[i].inf;
		cout << "Podaj ocene matematyki: " << endl;
		cin >> listaStud[i].mat;
		cout << "Podaj ocene chemii: " << endl;
		cin >> listaStud[i].che;
		cout << "Podaj ocene polskiego: " << endl;
		cin >> listaStud[i].pol;
	}
	cout << "podaj liczbe zapytan: " << endl;
	cin >> n;
	for (; n > 0; n--) {
		cout << "podaj nr ucznia [1..6]: ";
		cin >> a;
		cout << "podaj nr przedmiotu [0..3]";
		cin >> b;
		if (b == 0) cout << "Uczen: " << listaStud[a - 1].imie << ", ocena z informatyki: " << listaStud[a - 1].inf << endl;
		if (b == 1) cout << "Uczen: " << listaStud[a - 1].imie << ", ocena z matematyki: " << listaStud[a - 1].mat << endl;
		if (b == 2) cout << "Uczen: " << listaStud[a - 1].imie << ", ocena z chemii: " << listaStud[a - 1].che << endl;
		if (b == 3) cout << "Uczen: " << listaStud[a - 1].imie << ", ocena z polskiego: " << listaStud[a - 1].pol << endl;
	}
}