#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 1010;
struct mooncake {
	double num;
	double price;
	bool operator>(const mooncake& a)const {
		return price/num > a.price/a.num;
	}
};

mooncake yuebing[MAX];

int main() {
	int n, d;
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &yuebing[i].num);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf", &yuebing[i].price);
	}
	sort(yuebing, yuebing + n, greater<mooncake>());

	double sum = 0;
	double total = 0;
	for (int i = 0; i < n; i++) {
		total += yuebing[i].num;
		if (total < d&&fabs(total - d) > 1e-6) {
			sum += yuebing[i].price;
		}
		else {
			sum += (yuebing[i].num + d - total)*yuebing[i].price / yuebing[i].num;
			break;
		}
	}
	printf("%.2f", sum);
	return 0;
}