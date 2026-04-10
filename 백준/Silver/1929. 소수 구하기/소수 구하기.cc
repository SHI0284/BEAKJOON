#include <iostream>
#include <vector>
using namespace std;

// 특정 범위 내의 소수를 모두 구하는 알고리즘
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	cin >> M >> N;

	vector<int> temp(N + 1, 0);

	for (int i = 2; i <= N; i++) temp[i] = i;

	for (int i = 2; i * i <= N; i++) {
		if (temp[i] == 0) continue;
		for (int j = 2 * i; j <= N; j += i) {
			if (temp[j] == 0) continue;
			else temp[j] = 0;
		}
	}
	for (int i = M; i <= N; i++) {
		if (temp[i] != 0) cout << temp[i] << "\n";
	}
	return 0;
}