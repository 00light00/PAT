#include<bits/stdc++.h>
using namespace std;

int main() {
	int st, en;
	scanf("%d %d", &st, &en);
	int minute = st % 100, hour = st / 100;
	minute += en + hour * 60;
	hour = minute / 60;
	minute %= 60;
	hour %= 24;
	printf("%d%02d\n", hour, minute);
	return 0;
}