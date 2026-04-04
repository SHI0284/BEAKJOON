#include <iostream>
using namespace std;

// 이걸 매번 [S, E] 구간이 팰린드롬인지 직접 검사하면 시간 초과
// 미리 DP 테이블을 만들어 두고 바로 답해보자

int arr[2001];
int dp[2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    // 수열 입력
    for (int i = 1; i <= N; i++) cin >> arr[i];

    // 여기서부터 DP 초기화하는 과정임.

    // 길이 1인 구간은 모두 팰린드롬
    for (int i = 1; i <= N; i++) dp[i][i] = 1;

    // 길이 2인 구간 확인
    for (int i = 1; i < N; i++) {
        if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
    }

    // 길이 3 이상인 구간 확인
    // len = 구간 길이
    for (int len = 3; len <= N; len++) {
        for (int start = 1; start <= N - len + 1; start++) {
            int end = start + len - 1;

            // 그 이미 안 쪽이 팰린드롬이면 양 끝만 같다면 얘도 팰린드롬
            if (arr[start] == arr[end] && dp[start + 1][end - 1] == 1) {
                dp[start][end] = 1;
            }
        }
    }

    int M; cin >> M;

    // 저장한 dp로 질문 처리함.
    while (M--) {
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }

    return 0;
}