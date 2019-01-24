#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> heap(1, 0);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		heap.push_back(num);
		for (int j = i; j > 1; j /= 2) {
			if (heap[j] < heap[j / 2])
				swap(heap[j], heap[j / 2]);
			else
				break;
		}
	}
	for (int i = 0; i < m; i++) {
		int h;
		scanf("%d", &h);
		while (h > 1) {
			printf("%d ", heap[h]);
			h /= 2;
		}
		printf("%d\n", heap[h]);
	}

	return 0;
}