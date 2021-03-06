// dp[i] : 현재 인덱스까지 최소 점프 회수
// 인덱스 i는 0부터 시작해서 i에서 띌 수 있는 모든 경우에 대해
// 뛴 값 j를 이용해 dp[i+j]의 값과 dp[i]+1의 값을 비교해서
// 최소의 값을 dp[i+j]에 갱신시켜 준다.

#include <iostream>
using namespace std;
#define MXN 1001

int dp[MXN];
int arr[MXN];
int N;
const int INF = 2e9;

int min(int a, int b) {
	return a > b ? b : a;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 1; i < N; i++) dp[i] = INF;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= arr[i]; j++) {
			if (i + j >= N) break;
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	if (dp[N - 1] == INF) cout << -1 << '\n';
	else cout << dp[N - 1] << '\n';
	return 0;
}