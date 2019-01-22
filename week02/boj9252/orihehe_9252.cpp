/*
BOJ 9252 - LCS 2

dp[i][j] = s1���ڿ� i����, s2���ڿ� j������ LCS���� ������ �����մϴ�.
s1�� i-1, s2�� j������ LCS ����, s1�� i, s2�� j-1������ LCS ����,
i-1, j-1������ LCS ���̿� s1[i]�� s2[j]�� ���ٸ� +1 �� ���� �ִ��� �������ݴϴ�.

���� ����� ������ �� dp[i - 1][j - 1] + (s1[i] == s2[j]) �κп����� ���� �����ϱ� ������
LCS�� dp[i][j]�� ���ʷ� ������ �κ��� ���ڸ� �����ϰ� �˴ϴ�.
���� ���� ��ġ (p1,p2)���� dp[p1-1][p2] �� dp[p1][p2-1] �� ������ 
��� dp[p1][p2]�� �ٸ� �� ���ÿ� ���ڸ� �־��ְ� ������ݴϴ�.

���ڿ��� �Է� ���� �� s1�� �ּҰ� + 1 ���� �־��־� dp�� ä�� �� ���� ���ϰ� �Ϸ� �õ��߽��ϴ�.
�̷� ����� ó�� �� �ôµ� ��Ÿ�� ������ ��� ���� ������ ã�ƺ���
strlen(s1)�� �� �� s1[0]�� '\0' ���ڰ� ����ִٸ� ���� 0�� ���Ϲ޾� dp�迭�� ����� ä������ �ʰ�,
���� while������ dp[-1]�� �����ϰ� �ƽ��ϴ�.
(�쿬�� ���� �Խ��ǿ� ���� ��Ȳ�� ���� ��ż� ������ �� �� �־����ϴ�..)
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

int dp[1001][1001];
int main() {
	char s1[1002], s2[1002];
	int len1, len2, p1, p2;
	stack<char> sta;
	scanf("%s %s", 1 + s1, 1 + s2);
	s1[0] = '0', s2[0] = '1';
	len1 = strlen(s1)-1, len2 = strlen(s2)-1;
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			dp[i][j] = max({dp[i - 1][j - 1] + (s1[i] == s2[j]),
				dp[i][j - 1], dp[i - 1][j]});
		}
	}
	p1 = len1, p2 = len2;
	while (dp[p1][p2] > 0) {
		int tmp = dp[p1][p2];
		if (dp[p1 - 1][p2] == tmp) p1--;
		else if (dp[p1][p2 - 1] == tmp) p2--;
		else { // ���ʷ� ������ �κ�
			sta.push(s1[p1]);
			p1--, p2--;
		}
	}
	printf("%d\n", dp[len1][len2]);
	while (!sta.empty()) {
		printf("%c", sta.top()); sta.pop();
	}

	return 0;
}