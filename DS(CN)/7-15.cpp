#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	unordered_map<string, string> qq;
	for (int i = 0; i < n; i++) {
		char command[10], id[20], pass[20];
		scanf("%s %s %s", command, id, pass);
		if (command[0] == 'L') {
			if (qq.find(id) != qq.end()) {
				if (qq[id] == pass) {
					printf("Login: OK\n");
				}
				else {
					printf("ERROR: Wrong PW\n");
				}
			}
			else {
				printf("ERROR: Not Exist\n");
			}
		}
		else if (command[0] == 'N') {
			if (qq.find(id) == qq.end()) {
				qq[id] = pass;
				printf("New: OK\n");
			}
			else {
				printf("ERROR: Exist\n");
			}
		}
	}
	return 0;
}