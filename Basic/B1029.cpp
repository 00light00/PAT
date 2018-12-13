#include <iostream>
using namespace std;

const int MAX = 100;
char word[MAX];
char keyboard[MAX];
char check[MAX];
int cnt[500];

int main() {
	scanf("%s", word);
	scanf("%s", keyboard);
	int p_key = 0, p_check = 0;
	for (int i = 0; word[i]; i++) {
		if (word[i] != keyboard[p_key]) {
			char tmp = word[i];
			if (tmp >= '0'&&tmp <= '9' || tmp >= 'A'&&tmp <= 'Z' || tmp == '_') {
				if (!cnt[tmp]) {
					check[p_check++] = tmp;
					cnt[tmp]++;
				}
			}
			else if (tmp >= 'a'&&tmp <= 'z') {
				tmp = tmp - 'a' + 'A';
				if (!cnt[tmp]) {
					check[p_check++] = tmp;
					cnt[tmp]++;
				}
			}
		}
		else {
			p_key++;
		}
	}
	check[p_check] = 0;
	printf("%s\n", check);
	return 0;
}