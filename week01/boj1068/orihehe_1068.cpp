/*
BOJ 1068 - Ʈ��

vector�� ����Ͽ� �� ��带 �մ� ���� ������ �־��־����ϴ�.
search�Լ����� dfs������� ������ Ÿ�� ������ ������带 Ž�����ݴϴ�.
�� �� ����� ��尡 ������ ����� Ž������ �ʵ��� �Ͽ���, Ž���� Ƚ���� c������ ī��Ʈ ������ϴ�.
���� c�� 0�̶�� �� ���� ��������̹Ƿ� ī��Ʈ ���־����ϴ�.
*/
#include <cstdio>
#include <vector>
using namespace std;

vector<int> tree[51];
int cnt, x;
void search(int cur) {
	if (cur == x) return;
	int c = 0;
	for (int v : tree[cur]) {
		// ������ ���δ� ���� ����
		if (v == x) continue;
		search(v); c++;
	}
	// ���� ��尡 ���ٸ� �������
	if (c == 0) cnt++;
}
int main() {
	int n, root;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == -1) root = i;
		else tree[x].push_back(i);
	}
	scanf("%d", &x);
	search(root);
	printf("%d", cnt);

	return 0;
}