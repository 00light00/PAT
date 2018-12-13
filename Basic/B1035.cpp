#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 110;
int orign[MAX], cmp[MAX], cmp_t[MAX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &orign[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cmp[i]);
		cmp_t[i] = cmp[i];
	}
	int p_insert = 0;
	while (cmp[p_insert] <= cmp[p_insert + 1]) {
		p_insert++;
	}
	int is_insert = 1;
	for (int i = p_insert + 1; i < n; i++) {
		if (cmp[i] != orign[i]) {
			is_insert = 0;
			break;
		}
	}

	if (is_insert) {
		printf("Insertion Sort\n");
		for (; p_insert >= 0; p_insert--) {
			if (cmp_t[p_insert + 1] < cmp_t[p_insert])
				swap(cmp_t[p_insert + 1], cmp_t[p_insert]);
			else
				break;
		}

	}
	else {
		printf("Merge Sort\n");
		int flag_merge = 0;
		for (int l = 2; l <= n; l *= 2) {
			for (int k = 1; k*l < n; k += 2) {
				if (cmp[k*l - 1] > cmp[k*l]) {
					flag_merge = 1;
					break;
				}
			}

			if (flag_merge) {
				for (int k = 0; k*l < n; k += 2) {
					int p_1 = k * l;
					int p_2 = (k + 1)*l;
					int p_merge = k * l;
					while (p_1 < (k + 1)*l&&p_2 < (k + 2)*l&&p_2 < n) {
						cmp_t[p_merge++] = cmp[p_1] < cmp[p_2] ? cmp[p_1++] : cmp[p_2++];
					}
					while (p_1 < (k + 1)*l) {
						cmp_t[p_merge++] = cmp[p_1++];
					}
					while (p_2 < (k + 2)*l&&p_2 < n) {
						cmp_t[p_merge++] = cmp[p_2++];
					}
				}
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (i > 0)
			printf(" ");
		printf("%d", cmp_t[i]);
	}
	printf("\n");
	return 0;
}