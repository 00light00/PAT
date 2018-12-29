#include<bits/stdc++.h>
using namespace std;

const char ap[2][3] = { "AM","PM" };

int main() {
	int hour, minute, flag = 0;
	scanf("%d:%d", &hour, &minute);
	if (hour >= 12) {
		flag = 1;
		if(hour>12)
			hour %= 12;
	}
	printf("%d:%d %s", hour, minute, ap[flag]);
	return 0;
}