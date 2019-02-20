#include<bits/stdc++.h>
using namespace std;

string marl[13] = { "tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
string marh[13] = { "tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou" };

int main() {
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		string tra;
		getline(cin, tra);
		int num;
		if (sscanf(tra.c_str(), "%d", &num)) {
			int high = num / 13;
			int low = num % 13;
			if (high)
				printf("%s", marh[high].c_str());
			if (low&&high)
				printf(" ");
			if (low || !num)
				printf("%s", marl[low].c_str());
			printf("\n");
		}
		else {
			if (tra.size() > 4) {
				char marlow[5],marhigh[5];
				int earth = 0;

				sscanf(tra.c_str(), "%s %s", marhigh, marlow);
				string high(marhigh), low(marlow);
				for (int i = 0; i < 13; i++) {
					if (marh[i] == high) {
						earth += i * 13;
					}
					if (marl[i] == low) {
						earth += i;
					}
				}
				printf("%d\n", earth);
			}
			else {
				for (int i = 0; i < 13; i++) {
					if (marl[i] == tra) {
						printf("%d\n", i);
						break;
					}
					if (marh[i] == tra) {
						printf("%d\n", i * 13);
						break;
					}
				}
			}
		}
	}
	return 0;
}