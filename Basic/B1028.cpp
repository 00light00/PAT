#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100010;
struct person {
	char name[10];
	int year, month, day;
	person() {};
	person(char na[], int ye, int mo, int da) :year(ye), month(mo), day(da) {
		strcpy(name, na);
	}
	bool operator<(const person& cmp)const {
		if (year != cmp.year)
			return year < cmp.year;
		else{
			if (month != cmp.month)
				return month < cmp.month;
			else
				return day < cmp.day;
		}
	}
};
person people[MAX];

int main() {
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		person tmp;
		scanf("%s %d/%d/%d", tmp.name, &tmp.year, &tmp.month, &tmp.day);
		if (tmp < person(" ", 1814, 9, 6) || person(" ", 2014, 9, 6) < tmp) {
			continue;
		}
		else {
			people[cnt++] = tmp;
		}
	}

	sort(people, people + cnt);
	if (cnt)
		printf("%d %s %s\n", cnt, people[0].name, people[cnt - 1].name);
	else
		printf("%d\n", cnt);
	return 0;
}