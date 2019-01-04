#include<bits/stdc++.h>
using namespace std;

int main() {
	int cm, foot, inch;
	scanf("%d", &cm);
	foot = cm / 30.48;
	inch = cm / 30.48 * 12;
	inch %= 12;
	printf("%d %d\n", foot, inch);
	return 0;
}
