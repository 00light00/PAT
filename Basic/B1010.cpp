#include <iostream>
#include <algorithm>
using namespace std;

struct yuebing
{
	int total;
	int shoujia;
};

struct comp
{
	bool operator()(yuebing a1, yuebing a2) {
		return a1.shoujia*1.0 / a1.total > a2.shoujia*1.0 / a2.total;
	}
};

const int MAX = 1010;
yuebing in[MAX];

int main() {
	int n, d;
	scanf("%d %d", &n, &d);
	for (int i = 0;i < n;i++) {
		scanf("%d", &in[i].total);
	}

	for (int i = 0;i < n;i++) {
		scanf("%d", &in[i].shoujia);
	}

	sort(in, in + n, comp());

	double sum = 0;
	for (int i = 0;i < n;i++) {
		if (d > in[i].total) {
			d -= in[i].total;
			sum += in[i].shoujia;
		}
		else {
			sum += in[i].shoujia*1.0 / in[i].total*d;
			break;
		}
	}

	printf("%.2f\n", sum);
	return 0;
}