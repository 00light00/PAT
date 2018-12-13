#include <iostream>
#include <string>
using namespace std;

const int MAX1 = 512;
const int MAX2 = 100010;
int hash_c[MAX1];
string word[2];


int main() {
	for (int i = 0; i < 2; i++) {
		getline(cin,word[i]);
	}

	for (int i = 0; word[0][i]; i++) {
		char c = word[0][i];
			if (c >= 'A' && c <= 'Z' ) {
			hash_c[c]++;
			hash_c[c - 'A' + 'a']++;
		}
		else if (c == '+') {
			for (int j = 0; j < 26; j++) {
				hash_c[j + 'A']++;
			}
		}
		else {
				hash_c[c]++;
		}
	}

	for (int i = 0; word[1][i]; i++) {
		if (!hash_c[word[1][i]])
			printf("%c", word[1][i]);
	}
	
	return 0;
}