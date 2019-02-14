#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int floor = 0, time = 0;
	for (int i = 0; i < n; i++) {
		int aim;
		scanf("%d", &aim);
		if (aim < floor)
			time += (floor - aim) * 4;
		else if (aim > floor)
			time += (aim - floor) * 6;
		time += 5;
		floor = aim;
	}
	printf("%d\n", time);
	return 0;
}