/*
BOJ 1431 - �ø��� ��ȣ

info ����ü�� ����� ���ڿ�, ���ڿ� ����, �ڸ��� �� ������ �����մϴ�.
�������� ���ϴ� ��� �����ϱ� ���� operator �� ���������ϴ�.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct info {
	char st[51];
	int len, hap;   // len - ���ڿ� ����, hap - �ڸ��� ��
};
bool operator < (info &a, info &b) {
	// ���̿� �ڸ��� ���� ���ٸ� ������ ��
	if (a.len == b.len && a.hap == b.hap) {
		for (int i = 0; i < a.len; i++) {
			if (a.st[i] != b.st[i]) {
				return a.st[i] < b.st[i];
			}
		}
	}
	// ���̰� ���ٸ� �ڸ��� �� ��
	if (a.len == b.len) return a.hap < b.hap;
	return a.len < b.len;  // ���� ��
}
int main() {
	char x[51];
	int n, sum, l;
	info sr[1001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		sum = 0;
		scanf("%s", x);
		strcpy(sr[i].st, x);
		l = strlen(x);
		sr[i].len = l;    // �ø����ȣ ����
		for (int j = 0; j < l; j++) {
			// ������ �͸� ���ϱ�
			if (x[j] <= '9' && x[j] >= '1') 
				sum += x[j] - '0';
		}
		sr[i].hap = sum;  // hap�� �ڸ��� ��
	}
	sort(sr, sr + n);
	for (int i = 0; i < n; i++) {
		printf("%s\n", sr[i].st);
	}

	return 0;
}