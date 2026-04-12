#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string isbn;
    cin >> isbn;

    int sum = 0;
    int starIdx = -1;

    // 1. 전체 합 계산
    for (int i = 0; i < 13; i++) {
        if (isbn[i] == '*') {
            starIdx = i;
            continue;
        }

        int weight = (i % 2 == 0) ? 1 : 3;
        sum += (isbn[i] - '0') * weight; // 0을 빼는 이유는 문자를 숫자로 바꾸기 위함
    }

    // 2. * 위치의 weight
    int weight = (starIdx % 2 == 0) ? 1 : 3;

    // 3. x 찾기
    for (int x = 0; x <= 9; x++) {
        if ((sum + x * weight) % 10 == 0) {
            cout << x;
            break;
        }
    }

    return 0;
}