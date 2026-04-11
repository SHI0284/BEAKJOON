#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, num, sum = 0;
	vector<int> temp;
	
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> num;
		temp.push_back(num);
	}

	sort(temp.begin(), temp.end());
	int erase = round(float(n) * 0.15);

	for (int i = erase; i < n - erase; i++) sum += temp[i];
	int result = round(float(sum) / (n - erase * 2));
	cout << result;

}