#include <iostream>
#include <vector>


using namespace std;

int main() {
	
	int n = 0;
	cout << "podaj liczbe elementow int " <<endl;
	cin >> n;
	cout << "podaj wartosc elementow, kazda zawtierdz enterem" << endl;
	vector <int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	int maxValue = vec[0];
	vector <int> indexOFmax(1,0);
	for (int i = 0; i < (n-1); i++) {
		if (maxValue < vec[i + 1]) {
			maxValue = vec[i + 1];
			for (int k = (indexOFmax.size()); k > 0; k--) {
				indexOFmax.pop_back();
				//cout << indexOFmax.size() << endl;
			}
			indexOFmax.push_back(i + 1);
			//cout << indexOFmax.size() << endl;
		}
		else if (maxValue == vec[i + 1]) indexOFmax.push_back(i + 1);
	}

	cout << "max wartosc to " << maxValue << " wystepuje na indeks(ach)(indeksy sa liczone od pozycji 0) = ";
	for (int k = (indexOFmax.size()); k > 0; k--) {
		cout << indexOFmax[k-1] << " ";
	}
	//cout << indexOFmax.size();
}
