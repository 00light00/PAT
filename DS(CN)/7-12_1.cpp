#include<bits/stdc++.h>
using namespace std;

int comp(const void *a, const void *b) {
	return *(long long *)a - *(long long*)b;
}

template<class T>
struct mycomp {
	bool operator()(T a, T b) {
		return *a < *b;
	}
};

template<class T>
void mysort(T a, T b) {
	T l = a, r = b - 1;
	if (l >= r)
		return;
	while (l != r) {
		while (l != r && *l < *r)
			r--;
		swap(*l, *r);
		while (l != r && *l < *r)
			l++;
		swap(*l, *r);
	}
	mysort(a, l);
	mysort(r + 1, b);
}

template<class T>
void mysort2(T a, T b) {
	auto l = a, r = b - 1;
	for (auto p = r; p != l;) {
		auto i = l, j = i;
		for (; i != p; i++) {
			if (*i > *(i + 1)) {
				swap(*i, *(i + 1));
				j = i;
			}
		}
		p = j;
	}
}



vector<long long> re;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long long num;
		scanf("%lld", &num);
		re.push_back(num);
	}
	mysort2(re.begin(), re.end());
	for (int i = 0; i < n; i++) {
		if (i > 0)
			printf(" ");
		printf("%ld", re[i]);
	}
	return 0;
}