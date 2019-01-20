/*
BOJ 11049 - ��� ���� ����

������ ��ĳ����� ���������� �����ϰ�, ���� ������ ���� ���� ���� �޶����ϴ�.
���� k ������ ������ ������ ������ ���ʱ����� ������ �ּڰ���, 
������ ������ ������ �ּڰ����� �� ������ ���� ���� ���� �ּڰ��� ���߽��ϴ�.
dp[i][i+k] �� i~i+k ���������� ������ �ּڰ��� ���� �˴ϴ�.
*/
#include <cstdio>
#include <algorithm>
#define P pair<int,int>
#define INF 2147483647
using namespace std;

int dp[502][502];
P arr[501];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	for (int k = 1; k <= n; k++) {	// ������ �� ���� ũ��
		for (int i = 1; i <= n - k; i++) {  // ������ ���� ��
			dp[i][i + k] = INF;  // i�� ���������� �ϴ� k������ �ּڰ��� ������ ��
			for (int j = i; j < i + k; j++) { // i~i+k ���� j�� �������� �� ������ ������ ����.
				dp[i][i + k] = min(dp[i][i + k],
					dp[i][j] + dp[j + 1][i + k] + arr[i].first*arr[i + k].second*arr[j].second);
			}
		}
	}
	printf("%d", dp[1][n]);

	return 0;
}