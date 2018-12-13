#include <iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> part[3];
int part_p[5];

int main() {
	for (int i = 0; i < 3; i++) {
		string fuhao;
		getline(cin, fuhao);
		int p1 = 0, p2 = 0;
		while (p1 != string::npos) {
			p1 = fuhao.find("[", p2);
			p2 = fuhao.find("]", p1);
			part[i].push_back(fuhao.substr(p1 + 1, p2 - p1 - 1));
		}
	}
	int size1 = part[0].size(), size2 = part[1].size(), size3 = part[2].size();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			int tmp;
			scanf("%d", &tmp);
			part_p[j] = tmp - 1;
			
		}
		int flag = 1;
		if (part_p[0] < size1 && part_p[1] < size2 && part_p[2] < size3 && part_p[3] < size2 && part_p[4] < size1
			&& part_p[0] >= 0 && part_p[1] >= 0 && part_p[2] >= 0 && part_p[3] >= 0 && part_p[4] >= 0)
			flag = 1;
		else
			flag = 0;
		if (flag) {
			cout << part[0][part_p[0]] << "(" << part[1][part_p[1]] << part[2][part_p[2]] << part[1][part_p[3]] << ")" << part[0][part_p[4]] << endl;
		}
		else {
			printf("Are you kidding me? @\\/@\n");
		}
	}



	return 0;
}