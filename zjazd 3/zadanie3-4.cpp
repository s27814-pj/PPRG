#include <iostream>


using namespace std;

int pascala(int a,int b) {
	if ((a == b) || (b==0)) return 1;
	else return (pascala(a - 1, b-1) + pascala(a-1, b));
}

int main() {
	cout << "podaj liczbe wierszy" << endl;
	int n = 0;
	cin >> n;
	n++;
	if (n > 0) {
		//n--;
		for (int i = 0; i < n; i++) {
		if (i != 0) cout << 1 << '\t';
		//cout << i + 1 << '\t';
		if (i > 2)
		{
			for (int k = 1; k < i; k++) {
				cout << pascala(i, k) << '\t';
			}
		}

		if (i != 1 && i != 0) cout << 1 << '\t';
		cout << endl;
		}
	}


}
