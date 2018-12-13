#include<iostream>
#include<cstring>
#include<string>
using namespace std;

const int MAX = 1010;
char word[MAX];
int cnt[26];
 
int main() {
	cin.getline(word, MAX);
	for (int i = 0; word[i]; i++) {
		if (word[i] >= 'a'&&word[i] <= 'z') {
			cnt[word[i] - 'a']++;
		}
		else if (word[i] >= 'A'&&word[i] <= 'Z') {
			cnt[word[i] - 'A']++;
		}
	}
	int i_max = 0, max = cnt[i_max];
	for (int i = 0; i < 26; i++) {
		if (max < cnt[i]) {
			i_max = i;
			max = cnt[i];
		}
	}
	printf("%c %d\n", 'a' + i_max, max);
	return 0;
}