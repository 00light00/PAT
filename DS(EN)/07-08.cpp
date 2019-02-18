#include<bits/stdc++.h>
using namespace std;

const int MAX = 10010;
int network[MAX];

bool check(int id1, int id2);
void connect(int id1, int id2);
int find(int id);

int main() {
	int n;
	char command[2];
	scanf("%d", &n);
	scanf("%s", command);
	while (command[0] != 'S') {
		int id1, id2;
		scanf("%d %d", &id1, &id2);
		switch(command[0]) {
		case 'C':
			if (check(id1, id2)) {
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
			break;
		case 'I':
			connect(id1, id2);
			break;
		}
		scanf("%c", command);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (network[i] <= 0) {
			cnt++;
		}
	}
	if (cnt == 1) {
		printf("The network is connected.\n");
	}
	else {
		printf("There are %d components.\n", cnt);
	}
	return 0;
}

int find(int id) {
	int re = network[id];
	if (re > 0) {
		while (network[re] > 0) {
			network[id] = network[re];
			re = network[re];
		}
	}
	else
		re = id;
	return re;
}

bool check(int id1, int id2) {
	int root1 = find(id1);
	int root2 = find(id2);
	if (root1 == root2)
		return true;
	else
		return false;
}

void connect(int id1, int id2) {
	int root1 = find(id1);
	int root2 = find(id2);
	if (root1 != root2) {
		if (network[root1] < network[root2])
			swap(root1, root2);
		network[root2]--;
		network[root1] = root2;
	}
}