#include <iostream>
#include <string>
using namespace std;

string week[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

int main() {

	int day, hour, min;
	string a1, a2, a3, a4;
	cin >> a1 >> a2 >> a3 >> a4;
	int i = 0;
	while (a1[i] && a2[i]) {
		if (a1[i] == a2[i] && a1[i] >= 'A' && a1[i] <= 'Z') {
			day = a1[i] - 'A' + 1;
			break;
		}
		i++;
	}
	i++;
	while (a1[i] && a2[i]) {
		if (a1[i] == a2[i]) {
			char tmp = a1[i];
			if (tmp >= 'A'&&tmp <= 'N') {
				hour = 10 + tmp - 'A';
			}
			else if (tmp <= '9'&&tmp >= '0') {
				hour = tmp - '0';
			}
			break;
		}
		i++;
	}

	i = 0;
	while (a3[i] && a4[i]) {
		if (a3[i] == a4[i] && isalpha(a3[i])) {
			min = i;
			break;
		}
		i++;
	}
	printf("%s %02d:%02d", week[day - 1].c_str(), hour, min);
	return 0;
}