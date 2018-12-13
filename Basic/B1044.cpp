#include<iostream>
#include<cstring>
#include<cstdlib> 
using namespace std;

const int MAX = 20;
char in[MAX];
char low[13][MAX] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
char high[13][MAX] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
void translate() {
	memset(in, 0, sizeof(in));
	cin.getline(in, MAX);
	if (in[0] >= '0'&&in[0] <= '9') {
		int num = atoi(in);
		int h = num / 13;
		int l = num % 13;
		if (h) {
			printf("%s", high[h]);
		}
		if (h&&l)
			printf(" ");
		if(l)
			printf("%s", low[l]);
		if (!l && !h) {
			printf("%s", low[l]);
		}
		printf("\n");
	}
	else {
		int hi = 0, lo = 0;
		int len = strlen(in);
		if (len == 3) {
			for (int i = 0; i < 13; i++) {
				if (strcmp(in, high[i]) == 0) {
					hi = i;
					break;
				}
			}

			for (int i = 0; i < 13; i++) {
				if (strcmp(in, low[i]) == 0) {
					lo = i;
					break;
				}
			}
		}
		else if (len == 4) {
			hi = lo = 0;
		}
		else {
			in[3] = '\0';
			char*p1 = in, *p2 = in + 4;

			for (int i = 0; i < 13; i++) {
				if (strcmp(p1, high[i]) == 0) {
					hi = i;
					break;
				}
			}

			for (int i = 0; i < 13; i++) {
				if (strcmp(p2, low[i]) == 0) {
					lo = i;
					break;
				}
			}
		}

		printf("%d\n", 13 * hi + lo);
	}
}

int main() {
	int n;
	scanf("%d\n", &n);
	
	for (int i = 0; i < n; i++) {
		translate();
	}
	return 0;
}
