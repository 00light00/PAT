#include <iostream>
using namespace std;

struct node {
	int data;
	int next;
};
const int MAX = 100010;
node link[MAX];

void reverselink(int & faddress, int k) {
	static int address;
	if (faddress > 0)
		address = faddress;
	for (int i = 0;i < k;i++) {

	}
}

int main() {
	int faddress, n, k;
	scanf("%d %d %d", &faddress, &n, &k);
	for (int i = 0;i < n;i++) {
		int address, data, next;
		scanf("%d %d %d", &address, &data, &next);
		link[address].data = data;
		link[address].next = next;
	}

	int cnt = 1;
	int pnode = faddress;
	while (link[pnode].next != -1) {
		cnt++;
		pnode = link[pnode].next;
	}
	//printf("%d\n", cnt);

	reverselink(faddress, k);
	for (int i = 0;i < cnt / k - 1;i++) {
		reverselink(-1, k);
	}
	return 0;
}