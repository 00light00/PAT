#include<bits/stdc++.h>
using namespace std;



int main() {
	int T, k;
	scanf("%d %d", &T, &k);
	for (int i = 0; i < k; i++) {
		int n1, n2, b, t;
		scanf("%d %d %d %d", &n1, &b, &t, &n2);
		if(t>T){
			printf("Not enough tokens.  Total = %d.\n", T);
		}
		else {
			if (b) {
				swap(n1, n2);
			}
			if (n1 < n2) {
				T -= t;
				printf("Lose %d.  Total = %d.\n", t, T);
			}
			else {
				T += t;
				printf("Win %d!  Total = %d.\n", t, T);
			}
		}
		if (T == 0) {
			printf("Game Over.\n");
			break;
		}
	}
	return 0;
}