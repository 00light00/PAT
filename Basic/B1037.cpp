#include<iostream>
using namespace std;

struct harry {
	int Galleon, Sickle, Knut;
	
};

int cmp(harry a, harry b) {
	int re;
	if (a.Galleon == b.Galleon) {
		if (a.Sickle == b.Sickle) {
			if (a.Knut == b.Knut) {
				re = 0;
			}
			else {
				re = a.Knut - b.Knut;
			}
		}
		else {
			re = a.Sickle - b.Sickle;
		}
	}
	else {
		re = a.Galleon - b.Galleon;
	}
	return re;
}

int main() {
	harry p, a;
	scanf("%d.%d.%d %d.%d.%d", &p.Galleon, &p.Sickle, &p.Knut, &a.Galleon, &a.Sickle, &a.Knut);
	if (cmp(p, a) == 0) {
		printf("0.0.0\n");
	}
	else {
		int flag = 0;
		if (cmp(p, a) > 0) {
			swap(p, a);
			flag = 1;
		}
		harry re;
		re.Galleon = a.Galleon - p.Galleon;
		re.Sickle = a.Sickle - p.Sickle;
		re.Knut = a.Knut - p.Knut;
		re.Galleon--;
		re.Sickle += 16;
		re.Knut += 29;
		re.Sickle += re.Knut / 29;
		re.Knut %= 29;
		re.Galleon += re.Sickle / 17;
		re.Sickle %= 17;
		if (flag)
			printf("-");
		printf("%d.%d.%d\n", re.Galleon, re.Sickle, re.Knut);
	}
	
	return 0;
}