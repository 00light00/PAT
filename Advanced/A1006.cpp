#include<bits/stdc++.h>
using namespace std;

struct signtime {
	int hour, min, sec;
	signtime() {};
	signtime(int h, int m, int s) :hour(h), min(m), sec(s) {};
	bool operator<(signtime cmp) {
		return hour == cmp.hour ? (min == cmp.min ? sec < cmp.sec : min < cmp.min) : hour < cmp.hour;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	string id_max, id_min;
	signtime t_max(0, 0, 0), t_min(24, 0, 0);
	for (int i = 0; i < n; i++) {
		signtime t_in, t_out;
		char id[20];
		scanf("%s %d:%d:%d %d:%d:%d", id, &t_in.hour, &t_in.min, &t_in.sec, &t_out.hour, &t_out.min, &t_out.sec);
		if (t_in < t_min) {
			id_min = string(id);
			t_min = t_in;
		}
		if (t_max < t_out) {
			id_max = string(id);
			t_max = t_out;
		}
	}
	cout << id_min << " " << id_max;
	return 0;
}