#include <iostream>
using namespace std;

const int MAX = 1010;
char A[MAX];

int main() {
	int B, Q, R = 0;
	cin >> A >> B;
	int flag = 0;
	for (int i = 0;A[i];i++) {
		int tmp = A[i] - '0';
		R = R * 10 + tmp;
		Q = R / B;
		R = R % B;
		if (Q) {
			flag = 1;
			printf("%d", Q);
		}
		else {
			if (flag)
				printf("%d", Q);
		}
	}

	printf(" %d\n",R);

	return 0;
}