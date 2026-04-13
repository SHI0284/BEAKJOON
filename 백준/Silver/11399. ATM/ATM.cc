#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> t;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		t.push_back(p);
	}

	sort(t.begin(), t.end());

	int ans = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += t[i];
		ans += sum;
	}
	
	cout << ans;
}