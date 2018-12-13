#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> sen(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &sen[i]);
	}

	int flag_re = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			vector<int>guess(n + 1, 1), lie(n + 1, 0);
			guess[i] = guess[j] = -1;
			int lie_c = 0;
			for (int k = 1; k <= n; k++) {
				int id=sen[k];
				if (id < 0) {
					if (id == -i || id == -j)
						lie[k]++;
					else {
						lie[k]--;
						lie_c++;
					}
				}
				else {
					if (id == i || id == j) {
						lie[k]--;
						lie_c++;
					}
					else
						lie[k]++;
				}
			}
			
			if (lie_c == 2 && lie[i] * lie[j] < 0) {
				printf("%d %d\n", i, j);
				flag_re = 0;
				break;
			}
		}
		if (flag_re == 0)
			break;
	}
	if (flag_re)
		printf("No Solution\n");
	return 0;
}