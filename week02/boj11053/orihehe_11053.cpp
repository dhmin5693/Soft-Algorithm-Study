/*
BOJ 11053 - ���� �� �����ϴ� �κ� ����

���� ��(arr[i])���� ���� ���� ���� �� ���� �� ���� + 1�� dp[i]�� ���� �˴ϴ�.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1000], dp[1000];
int main() {
	int n, maxL = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) { // ���� ������ �۴ٸ�
				dp[i] = max(dp[j], dp[i]); // ������ ���� ���� �� ����
			}
		}
		dp[i]++; // ���� �� ���̿� ���� ���� ����
		maxL = max(maxL, dp[i]);
	}
	printf("%d", maxL);

	return 0;
}