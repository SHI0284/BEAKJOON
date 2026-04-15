#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    map<string, int> nameToNum;
    map<int, string> numToName;

    for (int i = 1; i <= N; i++) {
        string name;
        cin >> name;
        nameToNum[name] = i;
        numToName[i] = name;
    }

    for (int i = 0; i < M; i++) {
        string query;
        cin >> query;

        if (query[0] >= '0' && query[0] <= '9') {
            int num = stoi(query);
            cout << numToName[num] << '\n';
        }
        else {
            cout << nameToNum[query] << '\n';
        }
    }

    return 0;
}