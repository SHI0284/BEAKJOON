#include <iostream>
#include <vector>
using namespace std;

vector<int> temp[1001];
int visited[1001];
int n, m;

void DFS(int vertex) {
    visited[vertex] = 1;

    for (int i = 0; i < temp[vertex].size(); i++) {
        int idx = temp[vertex][i];

        if (visited[idx] == 0)
            DFS(idx);
    }
}

int main() {
    int a, b;
    int cnt = 0;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        temp[a].push_back(b);
        temp[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            cnt++;
            DFS(i);
        }
    }

    cout << cnt << "\n";
}