#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100010;
int n, p;

int main() {
	vector<int> num;
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++) {
		int t_num;
		scanf("%d", &t_num);
		num.push_back(t_num);
	}
	sort(num.begin(), num.end());
	int cnt_max = 1;
	vector<int>::iterator it_min = num.begin(), it_max = num.end();
	it_max--;
	for (; it_max != num.begin(); it_max--) {
		int re = *it_max / p;
		if (*it_max%p)
			it_min = upper_bound(num.begin(), num.end(), re);
		else
			it_min = lower_bound(num.begin(), num.end(), re);
		cnt_max = cnt_max < it_max - it_min + 1 ? it_max - it_min + 1 : cnt_max;
	}

	printf("%d\n",cnt_max);
	return 0;
}