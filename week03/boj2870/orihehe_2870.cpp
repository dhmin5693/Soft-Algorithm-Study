/*
BOJ 2870 - ���м���

���ڰ� ������ �� tmp���ڿ��� ���� �־��־����ϴ�.
�׸��� ���ڰ� ������ ��, ���ڿ��� ������ �о��� �� vector�� tmp���ڿ��� �־��ݴϴ�.

�񳻸����� ����� cmp�Լ����� �����Ͽ����ϴ�.
���̰� ª�� ���ڿ��� ���̰� �� ���ڿ����� ���� ���� ���ۿ� ����,
���̰� ���ٸ� ���������� �������ָ� ���� ���� ������ ���� �˴ϴ�.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> vec;
bool cmp(string &a, string &b) {
	// �� ������ ���̰� ���ٸ� ���������� ����
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size(); // ���̰� ���� ���� ���� ��
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, len;
	string st, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> st;
		len = st.size();
		tmp = "";
		for (int j = 0; j < len; j++) {
			if (st[j] <= '9' && st[j] >= '1') {
				// �� ���ڸ��� 0�� �� 0�� �ƴ� ���� ������ 0 ����
				if (tmp.size() != 0 && tmp[0] == '0') {
					tmp = ""; tmp += st[j];
				}
				else
					tmp += st[j];
			}
			else if (st[j] == '0') {
				// �� ���ڸ��� 0�� �� 0�� ������ �Ѿ
				if (tmp.size() != 0 && tmp[0] == '0') {
					continue;
				}
				tmp += st[j];
			} 
			else if (tmp.size() != 0) {  // ���ڰ� �ƴ� ���
				vec.push_back(tmp);		 // vec�迭�� ����� ���� ���ڿ��� �־��ݴϴ�
				tmp = "";
			}
		}
		if (tmp.size() != 0) vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end(), cmp); // cmp���� ����
	for (string v : vec) cout << v << "\n";

	return 0;
}