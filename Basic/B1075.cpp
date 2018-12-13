#include<bits/stdc++.h>
using namespace std;

const int MAX = 100010;
const int HEAD = 100009;
struct node {
	int address,data, next;
};
node linklist[MAX];

int main(){
	int start, n, k;
	scanf("%d %d %d", &start, &n, &k);
	linklist[HEAD].next = start;
	for (int i = 0; i < n; i++) {
		int add, date_t, next_t;
		scanf("%d %d %d", &add, &date_t, &next_t);
		linklist[add].data = date_t;
		linklist[add].next = next_t;
		linklist[add].address = add;
	}
	int p = linklist[HEAD].next;
	vector<node>re1, re2, re3;
	while (p != -1) {
		int _data = linklist[p].data;
		if (_data < 0) {
			re1.push_back(linklist[p]);
		}
		else if (_data >= 0 && _data <= k)
			re2.push_back(linklist[p]);
		else {
			re3.push_back(linklist[p]);
		}
		p = linklist[p].next;
	}
	int len1 = re1.size(), len2 = re2.size(), len3 = re3.size();
	int h1, h2, h3;
	if (len3) {
		h3 = re3[0].address;
		re3[len3 - 1].next = -1;
	}
	else
		h3 = -1;
	if (len2) {
		h2 = re2[0].address;
		re2[len2 - 1].next = h3;
	}
	else
		h2 = h3;
	if (len1) {
		h1 = re1[0].address;
		re1[len1 - 1].next = h2;
	}
	else
		h1 = h2;
	for (int i = 0; i < len1-1; i++) {
		printf("%05d %d %05d\n", re1[i].address, re1[i].data, re1[i + 1].address);
	}
	if (len1) {
		printf("%05d %d ", re1[len1 - 1].address, re1[len1 - 1].data);
		if (h2 != -1) {
			printf("%05d\n", h2);
		}
		else
			printf("-1\n");
	}
	for (int i = 0; i < len2 - 1; i++) {
		printf("%05d %d %05d\n", re2[i].address, re2[i].data, re2[i + 1].address);
	}
	if (len2) {
		printf("%05d %d ", re2[len2 - 1].address, re2[len2 - 1].data);
		if (h3 != -1) {
			printf("%05d\n", h3);
		}
		else
			printf("-1\n");
	}

	for (int i = 0; i < len3 - 1; i++) {
		printf("%05d %d %05d\n", re3[i].address, re3[i].data, re3[i + 1].address);
	}
	if (len3)
		printf("%05d %d -1\n", re3[len3 - 1].address, re3[len3 - 1].data);
	return 0;
}