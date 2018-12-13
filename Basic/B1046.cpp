#include<iostream>
using namespace std;

const int MAX = 2;
int cnt[MAX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int han1, hua1, han2, hua2;
		scanf("%d %d %d %d", &han1, &hua1, &han2, &hua2);
		int sum = han1 + han2;
		bool win1, win2;
		if (hua1 == sum)
			win1 = true;
		else
			win1 = false;
		if (hua2 == sum)
			win2 = true;
		else
			win2 = false;

		if (win1 != win2) {
			if (win1)
				cnt[1]++;
			else
				cnt[0]++;
		}
	}

	printf("%d %d\n", cnt[0], cnt[1]);
	return 0;
}