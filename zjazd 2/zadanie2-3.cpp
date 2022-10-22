#include <iostream>

using namespace std;

int main() {
	int miesiac = 0;
	cout << "podaj 1-12: ";
	cin >> miesiac;
	switch (miesiac) {
	case 1:
		cout << "styczen" << endl;
		break;
	case 2:
		cout << "luty" << endl;
		break;
	case 3:
		cout << "marzec" << endl;
		break;
	case 4:
		cout << "kwiecien" << endl;
		break;
	case 5:
		cout << "maj" << endl;
		break;
	case 6:
		cout << "czerwiec" << endl;
		break;
	case 7:
		cout << "lipiec" << endl;
		break;
	case 8:
		cout << "sierpien" << endl;
		break;
	case 9:
		cout << "wrzesien" << endl;
		break;
	case 10:
		cout << "pazdziernik" << endl;
		break;
	case 11:
		cout << "listopad" << endl;
		break;
	case 12:
		cout << "grudzien" << endl;
		break;
	default:
		cout << "liczba spoza przedzialu" <<endl;
	}
	if (miesiac == 1 || miesiac == 3 || miesiac == 5 || miesiac == 7 || miesiac == 8 || miesiac == 10 || miesiac == 12) cout << "liczba dni to 31";
	else if (miesiac == 2) cout << "liczba dni to 28";
	else if (miesiac >0 && miesiac <13) cout << "liczba dni to 30";
}