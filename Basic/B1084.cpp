#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int d, n;
	scanf("%d %d", &d, &n);
	string re(to_string(d));
	for (int i = 1; i < n; i++) {
		string tmp;
		int len = re.size();
		int cnt = 1;
		for (int i = 1; i <= len; i++) {
			if (re[i] == re[i - 1])
				cnt++;
			else {
				tmp.push_back(re[i - 1]);
				tmp.push_back(cnt + '0');
				cnt = 1;
			}
			
		}
		re = tmp;
	}
	cout << re << endl;
	return 0;
}