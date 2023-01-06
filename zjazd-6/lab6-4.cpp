#include <iostream>
#include <string>


using namespace std;


int main() {

	string a,b;
	int n = 0;

	cout << "podaj liczbe konkatenacji nastepnie po spacji tekst do konkatenowania" << endl;
	cin >> n;
	cin >> a;
	for (; n > 0; n--) {
		//cout << a;
		b = b + a;
	}
	cout << b;
}