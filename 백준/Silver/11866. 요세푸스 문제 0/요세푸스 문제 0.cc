#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> Q;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) Q.push(i);
	cout << "<";
	while (Q.size() != 0) {
		for (int i = 1; i < k; i++) {
			Q.push(Q.front());
			Q.pop();
		}
		cout << Q.front();
		if (Q.size() != 1) cout << ", ";
		Q.pop();
	}
	cout << ">";

	return 0;
}

