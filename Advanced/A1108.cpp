#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector <double> re;
	for (int i = 0; i < n; i++) {
		char num1[101], num2[101];
		double num;
		scanf("%s", num1);

		sscanf(num1, "%lf", &num);
		sprintf(num2, "%.2f", num);
		int flag = 1;
		for (int j = 0; num1[j]; j++) {
			if (num1[j] != num2[j]) {
				flag = 0;
				break;
			}
		}
		if (flag && num <= 1000 && num >= -1000)
			re.push_back(num);
		else
			printf("ERROR: %s is not a legal number\n", num1);
	}

	int cnt = re.size();
	double total = 0;
	for (int i = 0; i < cnt; i++) {
		total += re[i];
	}
	if (cnt == 1)
		printf("The average of 1 number is ");
	else
		printf("The average of %d numbers is ", cnt);
	if (cnt)
		printf("%.2f", total / cnt);
	else
		printf("Undefined");
	printf("\n");
	return 0;
}