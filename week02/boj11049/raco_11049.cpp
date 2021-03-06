// dp[i][j] : i번째 행렬과 j번째 행렬 사이의 모든 행렬의 최소 곱셈 수
// 인덱스 i와 j의 간격 d라 하고 d를 1로 2로 i+d<N일 때 까지 d값을 증가시킵니다.
// j가 i+d이니 N값과 같거나 크면 안 됩니다.
// i번째 행렬 부터 시작해서 j번째 행렬의 사이의 모든 행렬의 최소값을
// dp[i][j]에 갱신시킵니다. 

#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <iostream>
using namespace std;
#define MXN 501

int N;
int dp[MXN][MXN];
int mat[MXN][2];
const int INF = 2e9;

int min(int a, int b) {
	return a > b ? b : a;
}

void solve() {
	for (int d = 1; d < N; d++) {
		for (int i = 0; i + d < N; i++) {
			int j = i + d;
			dp[i][j] = INF;
			for (int k = i; k < j; k++) {
				// k값을 i부터 시작해서 j와 같을 때 까지 증가시키면서
				// i부터 k 사이의 모든 행렬 곱의 최소값과 k+1부터 j 사이의 모든 행렬 곱의 최소값을 더해주고
				// 이 때 i행렬의 행값 * k행렬의 열값 * j행렬의 열값을 곱해준값도 더해주면서
				// 가장 작은 값을 dp[i][j]에 갱신시켜줍니다.
				// d가 작을 때의 dp[i][j]값을 구해나가면서 d를 증가시키며
				// 이전에 구해 놓은 dp값을 이용해 dp[i][j]를 갱신시킵니다.
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mat[i][0] * mat[k][1] * mat[j][1]);
			}
		}
	}
}

int main() {
	fastio();
	cin >> N;
	for (int i = 0; i < N; i++) cin >> mat[i][0] >> mat[i][1];
	solve();
	cout << dp[0][N - 1] << '\n';
	return 0;
}