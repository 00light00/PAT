#include <iostream>
#include <cstring>
using namespace std;

char A[10010];

int main() {
	int flag1 = 0, flag2 = 0, point = 0;
	scanf("%s", A);
	if (A[0] == '-')
		flag1 = 1;
	
	A[2] = A[1];
	int i = 2, j;
	while (A[i] != 'E') {
		i++;
	}
	j = 1;
	if (A[i + j] == '-')
		flag2 = 1;
	while (A[i + j]) {

	}

	return 0;
}