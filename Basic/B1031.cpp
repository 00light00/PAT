#include <iostream>
using namespace std;

int  weight[18] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
char zm[15] = "10X98765432";

int main() {
	int n, flag_all = 0;
	char id[20];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", id);
		int m = 0, flag = 0;
		for (int j = 0; j < 17; j++) {
			if (id[j] >= '0'&&id[j] <= '9') {
				m += (id[j] - '0')*weight[j];
				m %= 11;
			}
			else {
				flag = flag_all = 1;
				break;
			}
		}

		if (id[17] != zm[m])
			flag = flag_all = 1;
		if (flag) {
			printf("%s\n", id);
		}

	}
	if (!flag_all)
		printf("All passed\n");
	return 0;
}