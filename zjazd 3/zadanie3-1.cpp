#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	float x = 0.123f, y = 0.256f;
	cout << "podaj 2 liczby oddzielone spacja" << endl;
	cin >> x >> y;
	cout << fixed << setprecision(2) << x << "+" << y << "=" << x + y << endl;
	cout << x << "-" << y << "=" << x - y << endl;
	cout << x << "*" << y << "=" << x * y << endl;
	cout << x << "/" << y << "=" << x / y << endl;
}