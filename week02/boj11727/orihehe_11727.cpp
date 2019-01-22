/*
BOJ 11727 - 2xn Ÿ�ϸ� 2

2x1 Ÿ���� �ڿ� ���̱� - dp[i-1]
2x2 Ÿ�� 2���� ��� (1x2 �� ��, 2x2 �� ��)�� �ڿ� ���̱� - dp[i-2]*2
2x2 ��쿡 2x1 �� ���� ����ϴ� ���� �̹� 2x1�� ��쿡�� �߰����ִ� ������� �ʽ��ϴ�.
*/
#include <cstdio>
using namespace std;

int dp[1001];
int main() {
	int n;
	scanf("%d", &n);
	dp[1] = 1, dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]*2)%10007;
	}
	printf("%d", dp[n]);

	return 0;
}