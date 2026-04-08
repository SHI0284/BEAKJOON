#include <iostream>
#include <vector>
using namespace std;

long long N;
long long L[7];
long long T, P;
long long Tshirt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= 6; i++) cin >> L[i];
	cin >> T >> P;

	for (int i = 1; i <= 6; i++) {
		if (L[i] % T == 0) Tshirt += (L[i] / T);
		else Tshirt += (L[i] / T + 1);
	}

	cout << Tshirt << "\n";
	cout << N / P << " " << N % P;
	return 0;
}