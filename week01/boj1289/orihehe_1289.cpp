/*
BOJ 1289 - Ʈ���� ����ġ

���� ��忡�� �ڽ��� Ÿ�� �������� ��� ����ġ�� ���� ������ ���� �� �����
(���� ����� �ڽ��� ��� ����ġ ��) * (���� ��忡�� �ڽ����� ���� ������ ����ġ) ���� �� �� �ֽ��ϴ�.
���� ���� ����� �ڽĵ鳢���� ��� ����ġ �� ���� �����־�� �ϹǷ�
�������� ���� �ڽĵ��� ��� ����ġ �տ� ���� ���� �ڽĿ��� ���� ��� ����ġ�� �����ݴϴ�.
���ؾ� �� ���� ��� ��� ����ġ ���̹Ƿ� ���� ���� ������ ������ ���� �����ݴϴ�.
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll long long
#define P pair<int,int>
#define mod 1000000007
using namespace std;

vector<P> vec[100001];
int parent[100001];
ll ans;
ll dfs(int cur) {
	int vcnt = 0;
	ll ret = 0; // cur���� �ڽĵ�� ���� ��� ����ġ �� (������ ��)
	for (P &v : vec[cur]) { // �� �ڽľ�
		if (parent[cur] == v.first) continue;
		parent[v.first] = cur; vcnt++;
		ll re = dfs(v.first); // �� �ڽĿ��� ���� ��� ����ġ ��

		// cur->�ڽ� ���� ����ġ + �ڽ��� ��� ����ġ �� * cur->�ڽ� ���� ����ġ
		ll rr = (v.second*re + v.second) % mod; 
		ans = (ans + rr + rr * ret) % mod; // �̹� Ž���� �ڽĵ�� ���� ��θ� ����
		ret = (ret + rr) % mod;			   // Ž���� �ڽĵ�� ���� ����� ����ġ ��
	}
	if (vcnt == 0) return 0; // ��������� �� 0 ��ȯ
	return ret;
}
int main() {
	int n, a, b, c;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}
	dfs(1);
	printf("%lld", ans);

	return 0;
}