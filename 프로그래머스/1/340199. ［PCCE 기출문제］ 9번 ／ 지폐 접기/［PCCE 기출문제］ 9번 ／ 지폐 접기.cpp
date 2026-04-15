#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

    // 지갑 정렬 (작은 값, 큰 값)
    int w1 = min(wallet[0], wallet[1]);
    int w2 = max(wallet[0], wallet[1]);

    int b1 = min(bill[0], bill[1]);
    int b2 = max(bill[0], bill[1]);

    while (true) {
        // 들어가는 경우 (회전 포함)
        if ((b1 <= w1 && b2 <= w2) || (b2 <= w1 && b1 <= w2)) {
            break;
        }

        // 긴 쪽을 반으로 접기
        if (b2 >= b1) {
            b2 /= 2;
        } else {
            b1 /= 2;
        }

        // 다시 정렬 (항상 b1 <= b2 유지)
        if (b1 > b2) swap(b1, b2);

        answer++;
    }

    return answer;
}