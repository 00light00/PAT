#include <iostream>
#include <vector>
using namespace std;

const double delta = 1e-6;
struct house {
	int day, freeday;
	bool kongzhi;
	house(int d = 0, int f = 0, bool k = false) :day(d), freeday(f), kongzhi(k) {};
};

int main() {
	int n, d;
	double e;
	scanf("%d %lf %d", &n, &e, &d);
	vector<house> h;
	for (int i = 0; i < n; i++) {
		int day_t, freeday_t = 0;
		scanf("%d", &day_t);
		for (int j = 0; j < day_t; j++) {
			double use;
			scanf("%lf", &use);
			if (use < e)
				freeday_t++;
		}
		h.push_back(house(day_t, freeday_t, freeday_t * 2 > day_t));
	}
	int re1 = 0, re2 = 0;
	for (int i = 0; i < n; i++) {
		if (h[i].kongzhi) {
			if (h[i].day > d)
				re2++;
			else
				re1++;
		}
	}

	printf("%.1f%% %.1f%%\n", 100.0*re1 / n, 100.0*re2 / n);
	return 0;
}