#include<bits/stdc++.h>
using namespace std;

vector <int> path;

void dfs(vector <int> &heap, int i, int n) {
	path.push_back(heap[i]);
	if (2 * i + 1 <= n)
		dfs(heap, 2 * i + 1, n);
	if (2 * i <= n)
		dfs(heap, 2 * i, n);
	else {
		for (auto it = path.begin(); it != path.end(); it++) {
			if (it != path.begin())
				printf(" ");
			printf("%d", *it);
		}
		printf("\n");
	}
	path.pop_back();
	return;
}

int heappath(vector<int> &heap, int n) {
	int re = 0, ismax = 1, ismin = -1;
	for (int i = 2; i <= n; i++) {
		if (heap[i / 2] < heap[i])
			ismax = 0;
		else if (heap[i / 2] > heap[i])
			ismin = 0;
	}
	dfs(heap, 1, n);
	re = ismax + ismin;
	return re;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> heap(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &heap[i]);
	}
	int flag = 0;
	flag = heappath(heap, n);
	switch (flag) {
	case 0:
		printf("Not Heap\n");
		break;
	case 1:
		printf("Max Heap\n");
		break;
	case -1:
		printf("Min Heap\n");
		break;
	}
	return 0;
}