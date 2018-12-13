#include<iostream>
using namespace std;

int cnt_jia[3][3],cnt_yi[3][3];
char bcj[4] = "BCJ";

int change(char i) {
	int re = 0;
	switch (i) {
	case 'B':
		re = 0;
		break;
	case 'C':
		re = 1;
		break;
	case 'J':
		re = 2;
		break;
	}
	return re;
}

int main() {
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char jia, yi;
		int a, b;
		cin >> jia >> yi;
		a = change(jia);
		b = change(yi);
		switch ((a - b + 2) % 3) {
		case 0:
			cnt_jia[0][a]++;
			cnt_yi[0][b]++;
			break;
		case 1:
			cnt_jia[1][a]++;
			cnt_yi[1][b]++;
			break;
		case 2:
			cnt_jia[2][a]++;
			cnt_yi[2][b]++;
			break;
		}
	}
	int win = 0, lose = 0, draw = 0;
	int index_max_jia = 0, max_jia = cnt_jia[1][0];
	int index_max_yi = 0, max_yi = cnt_yi[0][0];
	for (int i = 0; i < 3; i++) {
		win += cnt_jia[1][i];
		lose += cnt_jia[0][i];
		draw += cnt_jia[2][i];
		if (max_jia < cnt_jia[1][i]) {
			index_max_jia = i;
			max_jia = cnt_jia[1][i];
		}
		if (max_yi < cnt_yi[0][i]) {
			index_max_yi = i;
			max_yi = cnt_yi[0][i];
		}
	}

	printf("%d %d %d\n", win, draw, lose);
	printf("%d %d %d\n", lose, draw, win);
	printf("%c %c\n", bcj[index_max_jia], bcj[index_max_yi]);
	return 0;

}