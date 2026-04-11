#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m,num;
	cin >> n;
	vector<int> temp(n);

	for (int i = 0; i < n; i++) cin >> temp[i];
	sort(temp.begin(), temp.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		if (binary_search(temp.begin(), temp.end(), num)) cout << "1" << "\n";
		else cout << "0" << "\n";
	}
	return 0;
}