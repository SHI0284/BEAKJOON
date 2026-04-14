#include <iostream>

using namespace std;

int n, a[129][129], white, blue;

bool check(int x, int y, int len, int num) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (a[i + x][j + y] != num) return false;
		}
	}
	return true;
}

void cut(int x, int y, int len) {
	// 0은 흰색
	if (check(x, y, len, 0)) {
		white++;
		return;
	}
	// 1은 파란색
	if (check(x, y, len, 1)) {
		blue++;
		return;
	}
	int half = len / 2;
	cut(x, y, half);
	cut(x + half, y, half);
	cut(x, y + half, half);
	cut(x + half, y + half, half);
	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cut(0, 0, n);

	cout << white << '\n' << blue << '\n';
	return 0;
}