#include<bits/stdc++.h>
using namespace std;

int main() {
	int year, time;
	scanf("%d %d", &year, &time);
	double total = 0;
	int per = 0;
	if (year >= 5)
		per = 50;
	else
		per = 30;

	if (time > 40) {
		total = (40 + (time - 40)*1.5)*per;
	}
	else
		total = time * per;
	printf("%.2f\n", total);
	return 0;
}