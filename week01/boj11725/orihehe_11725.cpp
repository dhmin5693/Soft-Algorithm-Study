/*
BOJ 11725 - Ʈ���� �θ� ã��

��Ʈ�������� dfs������� ����� ������ Ž�����ݴϴ�.
�ڽ��� �θ� ������ �ڽŰ� ����� ������ �ڽ��� �ڽĵ��Դϴ�.
���� �θ� ���� ����� ������ �θ� �ڽ����� ���� �� dfs�� Ÿ�� �������� �˴ϴ�.
*/
#include <cstdio>
#include <vector>
using namespace std;

vector<int> vec[100001];
int parent[100001];
void dfs(int cur) {
	for (int &v : vec[cur]) {
		if (parent[cur] != v) {
			parent[v] = cur; // v�� �θ�� ��
			dfs(v);
		}
	}
}
int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) printf("%d\n", parent[i]);

	return 0;
}