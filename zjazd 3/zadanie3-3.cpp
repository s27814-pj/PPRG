#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a = 0, b = 0, c = 0;
	cout << "rownanie kwadratowe ma postac (A)x^2+(B)x+(C)=0" << endl;
	cout << "podaj A,B,C oddzielone spacja" << endl;
	cin >> a >> b >> c;
	cout << "rownanie kwadratowe z podanymi liczbami to: (" << a << ")x^2+(" << b << ")x+(" << c << ")=0" << endl;
	if ((b * b) - (4 * a * c) < 0) cout << "brak pierwiastkow rownania w rzeczywistych";
	if ((b * b) - (4 * a * c) == 0) cout << "pierwiastek rownania to: " << (-1 * b) / (2 * a);
	double delta = ((b * b) - (4 * a * c));
	if ((b * b) - (4 * a * c) > 0) cout << "pierwiastki rownania to: " << ((-1 * b) - sqrt(delta)) / (2 * a) << "oraz: " << ((-1 * b) + sqrt(delta)) / (2 * a);
	//cout << endl << sqrt((3 * 2) - (4 * 1 * 1));
}