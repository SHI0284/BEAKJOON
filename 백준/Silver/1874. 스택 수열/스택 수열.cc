#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> sequence;
vector<char> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int cur_num = 1;
    bool valid = true;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        while (cur_num <= num) {
            sequence.push(cur_num++);
            ans.push_back('+');
        }

        if (!sequence.empty() && sequence.top() == num) {
            sequence.pop();
            ans.push_back('-');
        } else {
            valid = false;
            break;
        }
    }

    if (!valid) {
        cout << "NO\n";
    } else {
        for (char ch : ans) {
            cout << ch << '\n';
        }
    }
}