#include <iostream>
using namespace std;

const int MAX = 20010;
char num[MAX];

int main() {
	scanf("%s", num);
	int flag = 0, flag_e = 0, p_e = 0, ex = 0;
	if (num[0] == '-')
		flag = 1;
	num[2] = num[1];

	while (num[p_e] != 'E') {
		p_e++;
	}
	if (num[p_e + 1] == '-')
		flag_e = 1;
	for (int i = p_e + 2; num[i]; i++) {
		ex *= 10;
		ex += num[i] - '0';
	}

	if (flag)
		printf("-");

	if (flag_e) {
		printf("0.");
		for (int i = 1; i < ex; i++) {
			printf("0");
		}
		for (int i = 2; i < p_e; i++) {
			printf("%c",num[i]);
		}
	}
	else {
		if (ex < p_e - 3) {
			for (int i = 2; i < p_e; i++) {
				printf("%c", num[i]);
				if (i == ex + 2)
					printf(".");
			}
		}
		else {
				for (int i = 2; i < p_e; i++) {
					printf("%c", num[i]);
				}
				for (int i = 0; i < ex + 3 - p_e; i++) {
					printf("0");
				}
			
		}
	}
	printf("\n");
	return 0;
}