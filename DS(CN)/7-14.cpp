#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	map<string, int> cnt;
	for (int i = 0; i < n; i++) {
		char ph1[20], ph2[20];
		scanf("%s %s", ph1, ph2);
		string phonenum1(ph1), phonenum2(ph2);
		cnt[phonenum1]++;
		cnt[phonenum2]++;
	}
	int max = 0, m_cnt = 0;
	string ph_max;
	for (auto i = cnt.begin(); i != cnt.end(); i++) {
		if (max < i->second) {
			max = i->second;
			m_cnt = 1;
			ph_max = i->first;
		}
		else if (max == i->second) {
			m_cnt++;
			if (ph_max > i->first)
				ph_max = i->first;
		}
	}
	printf("%s %d", ph_max.c_str(), max);
	if (m_cnt > 1)
		printf(" %d", m_cnt);
	return 0;
}