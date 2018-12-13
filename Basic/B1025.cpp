#include <iostream>
using namespace std;

const int MAX = 100010;
const int HEAD = 100009;
struct Node {
	int Data, Next;
	Node() {};
	Node(int d, int n) :Data(d), Next(n) {};
};
Node linklist[MAX];

int reverse_link(int address, int k) {
	int ppAddress = address, pAddress = linklist[ppAddress].Next, npAddress = linklist[pAddress].Next;
	int cnt = 0;
	while (cnt < k - 1) {
		ppAddress = pAddress;
		pAddress = npAddress;
		npAddress = linklist[npAddress].Next;
		linklist[pAddress].Next = ppAddress;
		cnt++;
	}
	int faddress=linklist[address].Next;
	linklist[faddress].Next = npAddress;
	linklist[address].Next = pAddress;
	return faddress;

}

int main() {
	int n, k;
	scanf("%d %d %d", &linklist[HEAD].Next, &n, &k);
	for (int i = 0; i < n; i++) {
		int address, data, next;
		scanf("%d %d %d", &address, &data, &next);
		linklist[address] = Node(data, next);
	}
	int cnt = 0, p = linklist[HEAD].Next;
	while (p != -1) {
		p = linklist[p].Next;
		cnt++;
	}
	int pAddress = HEAD;
	for (int i = 0; i < cnt / k; i++) {
		pAddress = reverse_link(pAddress, k);
	}
	pAddress = linklist[HEAD].Next;
	while (pAddress != -1) {
		printf("%05d %d ", pAddress, linklist[pAddress].Data);
		if (linklist[pAddress].Next != -1)
			printf("%05d\n", linklist[pAddress].Next);
		else
			printf("-1\n");
		pAddress = linklist[pAddress].Next;
	}
	return 0;
}