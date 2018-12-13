#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int id_max = 0, id_min = 0, _max = -1, _min = 1e6;
	for (int i = 0; i < n; i++) {
		int x, y, id;
		scanf("%d %d %d", &id, &x, &y);
		int re = x * x + y * y;
		if (re > _max) {
			_max = re;
			id_max = id;
		}
		if (re < _min) {
			_min = re;
			id_min = id;
		}
	}

	printf("%04d %04d\n", id_min, id_max);
	return 0;
}