#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string s;
int main() {
	int T;
	long long hashing = 1234567891;
	long long r = 1;
	long long sum = 0;

	cin >> T;
	cin >> s;

	for (int i = 0; i < T; i++) {
		sum += ((long(s[i]) - 96) * r) % hashing;
		r = (r * 31) % hashing;
	}
	cout << sum % hashing;
}
