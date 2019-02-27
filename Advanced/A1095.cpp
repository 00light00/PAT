#include<bits/stdc++.h>
using namespace std;

struct parktime {
	int hour, min, sec;
	parktime(int h = 0, int m = 0, int s = 0) :hour(h), min(m), sec(s) {};
	bool operator< (parktime op) const {
		return hour != op.hour ? hour < op.hour : min != op.min ? min < op.min : sec < op.sec;
	}
	parktime operator-(parktime op) {
		int h, m, s;
		s = sec - op.sec;
		if (s < 0) {
			s += 60;
			min--;
		}
		m = min - op.min;
		if (m < 0) {
			m += 60;
			hour--;
		}
		h = hour - op.hour;
		return parktime(h, m, s);
	}
	parktime operator+(parktime op) {
		int h, m, s;
		s = sec + op.sec;
		m = min + op.min + s / 60;
		h = hour + op.hour + m / 60;
		return parktime(h, m % 60, s % 60);
	}
	bool operator== (parktime op)const {
		return hour == op.hour&&min == op.min&&sec == op.sec;
	}
};

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	map<parktime, string> in, out;
	map<string, parktime> total;
	for (int i = 0; i < n; i++) {
		char id[10], status[10];
		int hour, min, sec;
		scanf("%s %d:%d:%d %s", id, &hour, &min, &sec, status);
		if (status[0] == 'i') {
			in[parktime(hour, min, sec)] = id;

			total[id] = total[id] - parktime(hour, min, sec);
		}
		else if (status[0] == 'o') {
			out[parktime(hour, min, sec)] = id;
			if(parktime(0,0,0)<total[id])

			total[id] = total[id] + parktime(hour, min, sec);
		}
	}
	parktime pa(0, 0, 0);
	int cnt = 0;
	auto it_in = in.begin(), it_out = out.begin();
	for (int i = 0; i < k; i++) {
		scanf("%d:%d:%d", &pa.hour, &pa.min, &pa.sec);
		while(it_in!=in.end()){
			if (pa < it_in->first) {
				break;
			}
			cnt++;
			it_in++;
		}
		while (it_out != out.end()) {
			if (pa < it_out->first) {
				break;
			}
			cnt--;
			it_out++;
		}
		printf("%d\n", cnt);
	}
	vector<string> re;
	parktime max(0, 0, 0);
	for (auto it = total.begin(); it != total.end(); it++) {
		if (max < it->second) {
			re.clear();
			max = it->second;
			re.push_back(it->first);
		}
		else if (max == it->second)
			re.push_back(it->first);
	}

	for (auto it = re.begin(); it != re.end(); it++) {
		printf("%s ", it->c_str());
	}
	printf("%d:%d:%d\n", max.hour, max.min, max.sec);
	return 0;
}