#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int temp[10001] = { 0 };
    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        temp[num]++;
    }

    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < temp[i]; j++) {
            cout << i << '\n';
        }
    }

    return 0;
}