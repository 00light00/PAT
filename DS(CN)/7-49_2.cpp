//1.����Ŀγ̲��ǰ�˳���
//2.��ѧ��û����ѯ���������е�ѧ�����Կγ�id������������ᳬʱ��ֻ�ܶԲ�ѯ��n��ѧ������

#include<bits/stdc++.h>
using namespace std;

unordered_map<string, vector<int>>st;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int course_id, stnum;
		scanf("%d %d", &course_id, &stnum);
		for (int j = 0; j < stnum; j++) {
			char name[5];
			scanf("%s", name);
			st[name].push_back(course_id);
		}
	}

	for (int i = 0; i < n; i++) {
		char name[5];
		scanf("%s", name);
		printf("%s %d", name, st[name].size());
		sort(st[name].begin(), st[name].end());
		for (auto it = st[name].begin(); it != st[name].end(); it++) {
			printf(" %d", *it);
		}
		printf("\n");
	}
	return 0;
}