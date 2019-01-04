#include<bits/stdc++.h>
using namespace std;

int main() {
	int sp;
	scanf("%d", &sp);
	printf("Speed: %d - ", sp);
	if (sp > 60)
		printf("Speeding\n");
	else
		printf("OK\n");
	return 0;
}