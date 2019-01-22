/*
BOJ 11060 - ���� ����

���� ĭ�� ���ڸ�ŭ ���� ĭ���� ���캾�ϴ�.
(���� ĭ�� �����ϱ� ���� �� Ƚ�� + 1)�� (�̹� �����ִ� Ƚ��) �� �ּڰ��� ���� ĭ�� ���� �˴ϴ�.
dp[i]���� ���� ĭ�� ������ �ּ� ���� Ƚ���� ����ǰ� �˴ϴ�.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1002], arr[1002];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	fill(dp, dp + n, 1001);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		// ���� ĭ�� ������ �� ���ٸ� ���� ĭ���ʹ� �� �ʿ䰡 ����.
		if (dp[i] == 1001) break; 
		for (int j = 1; j <= arr[i]; j++) {
			if (i + j > 1000) break; // �迭 ���� �Ѿ�� break
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	if (dp[n - 1] == 1001) printf("-1");
	else printf("%d", dp[n - 1]);

	return 0;
}