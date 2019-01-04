#include<bits/stdc++.h>
using namespace std;

const int MAX = 55;
const string shcd = "SHCDJ";

int main() {
	int k;
	vector<int> shuffle(MAX, 0), re, tmp;
	for (int i = 0; i < MAX; i++) {
		re.push_back(i);
	}
	tmp = re;
	scanf("%d", &k);
	for (int i = 1; i < MAX; i++) {
		scanf("%d", &shuffle[i]);
	}
	for (int i = 0; i < k; i++) {
		for (int j = 1; j < MAX; j++)
			tmp[shuffle[j]] = re[j];
		re = tmp;
	}

	for (int i = 1; i < MAX; i++) {
		if (i > 1)
			printf(" ");
		printf("%c%d", shcd[(re[i] - 1) / 13], (re[i] - 1) % 13 + 1);
	}
	printf("\n");
	return 0;
}