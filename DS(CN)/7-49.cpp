#include<bits/stdc++.h>
using namespace std;

const int MAX = 327680;
vector<vector<int>>student(MAX);

int myhash(char id[]) {
	return (id[0] - 'A') + (id[1] - 'A') * 26 + (id[2] - 'A') * 26 * 26 + (id[3] - '0') * 26 * 26 * 26;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int course_id, num;
		scanf("%d %d", &course_id, &num);
		for (int j = 0; j < num; j++) {
			char st_id[5];
			scanf("%s", st_id);
			int st = myhash(st_id);
			student[st].push_back(course_id);
		}
	}

	for (int i = 0; i < n; i++) {
		char st_id[5];
		scanf("%s", st_id);
		int st = myhash(st_id);
		int len = student[st].size();
		sort(student[st].begin(), student[st].end());
		printf("%s %d", st_id, len);
		for (int j = 0; j < len; j++) {
			printf(" %d", student[st][j]);
		}
		printf("\n");
	}
	return 0;
}