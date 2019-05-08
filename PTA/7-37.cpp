//将一个正整数N分解成几个正整数相加，可以有多种分解方法，例如7 = 6 + 1，7 = 5 + 2，7 = 5 + 1 + 1，…。编程求出正整数N的所有整数分解式子。
//
//输入格式：
//每个输入包含一个测试用例，即正整数N(0 < N≤30)。
//
//	输出格式：
//	按递增顺序输出N的所有整数分解式子。递增顺序是指：对于两个分解序列N1={n1,n2,⋯ }和N2	={m1,m2,⋯ }，若存在i使得n	1= m1, ⋯, ni	= mi，但是ni + 1< mi + 1, 则N1序列必定在N2序列之前输出。每个式子由小到大相加，式子间用分号隔开，且每输出4个式子后换行。
//	输入样例：
//	7
//	输出样例：
//	7 = 1 + 1 + 1 + 1 + 1 + 1 + 1; 7 = 1 + 1 + 1 + 1 + 1 + 2; 7 = 1 + 1 + 1 + 1 + 3; 7 = 1 + 1 + 1 + 2 + 2
//	7 = 1 + 1 + 1 + 4; 7 = 1 + 1 + 2 + 3; 7 = 1 + 1 + 5; 7 = 1 + 2 + 2 + 2
//	7 = 1 + 2 + 4; 7 = 1 + 3 + 3; 7 = 1 + 6; 7 = 2 + 2 + 3
//	7 = 2 + 5; 7 = 3 + 4; 7 = 7

//分析：此题和poj上整数划分很像，但是需要按照一定顺序输出表达式，可以判断为是按一定顺序遍历，综合题意可以判断用dfs。

#include<bits/stdc++.h>
using namespace std;

vector<int> n_part;
int n;

void print() {
	static int cnt = 0;
	printf("%d", n);
	for (auto it = n_part.begin(); it != n_part.end(); it++) {
		if (it == n_part.begin())
			printf("=");
		else
			printf("+");
		printf("%d", *it);
	}
	cnt++;
	if (cnt % 4 == 0)
		printf("\n");
	else {
		if (n_part.size() > 1)
			printf(";");
	}
}

bool solve(int x, int pre) {
	if (x == 0) {
		print();
		return true;
	}
	while (x >= pre) {
		n_part.push_back(pre);
		solve(x - pre, pre);
		n_part.pop_back();
		pre++;
	}
}

int main() {
	scanf("%d", &n);
	solve(n, 1);
	return 0;
}