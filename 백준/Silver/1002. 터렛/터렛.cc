#include <iostream>
using namespace std;

// 두 원의 교점 개수를 구하는 문제

int main() {
    int T;
    cin >> T; 

    int x1, y1, r1; 
    int x2, y2, r2; 

    int a, b;

    for (int i = 0; i < T; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        // 두 원 중심 사이 거리의 제곱
        int distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

        // (r1 - r2)^2 → 내접/포함 여부 판단 기준
        a = (r1 - r2) * (r1 - r2);

        // (r1 + r2)^2 → 외접/분리 여부 판단 기준
        b = (r1 + r2) * (r1 + r2);

        // 중심이 같은 경우 (distance == 0)
        if (distance == 0) {
            // 반지름도 같으면 → 완전히 같은 원 → 교점 무한개
            if (a == 0) cout << "-1" << '\n';
            // 반지름 다르면 → 동심원 → 교점 없음
            else cout << "0" << '\n';
        }

        // distance == a → 내접 (한 점에서 만남)
        // distance == b → 외접 (한 점에서 만남)
        else if (distance == a || distance == b) {
            cout << "1" << "\n";
        }

        // 두 원이 서로 두 점에서 만나는 경우
        else if (a < distance && distance < b) {
            cout << "2" << "\n";
        }

        // 나머지 경우 (완전히 떨어져 있거나, 한 원이 다른 원 안에 있음)
        else {
            cout << "0" << '\n';
        }
    }
}