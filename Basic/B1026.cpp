#include <iostream>
using namespace std;

const int CLK_TCK = 100;

int main() {
	int c1, c2;
	scanf("%d %d", &c1, &c2);
	int time = c2 - c1;
	printf("%02d:%02d:%02.0f", time / CLK_TCK / 3600, time / CLK_TCK / 60 % 60, time % (60 * CLK_TCK)*1.0 / CLK_TCK);
	return 0;
}