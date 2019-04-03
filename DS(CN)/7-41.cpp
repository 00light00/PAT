/*
	计算机程序设计能力考试（Programming Ability Test，简称PAT）旨在通过统一组织的在线考试及自动评测方法客观地评判考生的算法设计与程序设计实现能力，科学的评价计算机程序设计人才，为企业选拔人才提供参考标准（网址http://www.patest.cn）。

每次考试会在若干个不同的考点同时举行，每个考点用局域网，产生本考点的成绩。考试结束后，各个考点的成绩将即刻汇总成一张总的排名表。

现在就请你写一个程序自动归并各个考点的成绩并生成总排名表。

输入格式:
输入的第一行给出一个正整数N（≤100），代表考点总数。随后给出N个考点的成绩，格式为：首先一行给出正整数K（≤300），代表该考点的考生总数；随后K行，每行给出1个考生的信息，包括考号（由13位整数字组成）和得分（为[0,100]区间内的整数），中间用空格分隔。

输出格式:
首先在第一行里输出考生总数。随后输出汇总的排名表，每个考生的信息占一行，顺序为：考号、最终排名、考点编号、在该考点的排名。其中考点按输入给出的顺序从1到N编号。考生的输出须按最终排名的非递减顺序输出，获得相同分数的考生应有相同名次，并按考号的递增顺序输出。

输入样例:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
输出样例:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/

#include<bits/stdc++.h>
using namespace std;

struct stud {
	string id;
	int potid, score;
	int rank, potrank;
	stud(string _id, int _potid, int _score) : id(_id), potid(_potid), score(_score) { };
	bool operator<(stud op) const {
		return score != op.score ? score > op.score : id < op.id;
	}
};

int main() {
	int n, k;
	int sum = 0;
	vector<stud> re;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);

		for (int j = 1; j <= k; j++) {
			char id[20];
			int score;
			scanf("%s %d", id, &score);
			re.push_back(stud(id, i, score));
		}
		sort(&re[sum], &re[sum] + k);
		int pres = -1;
		for (int j = 0; j < k; j++) {
			if (re[sum + j].score != pres)
				re[sum + j].potrank = j + 1;
			else
				re[sum + j].potrank = re[sum + j - 1].potrank;
			pres = re[sum + j].score;
		}
		sum += k;
	}
	sort(re.begin(), re.end());
	int pres = -1;
	printf("%d\n", sum);
	for (int i = 0; i < sum; i++) {
		if (re[i].score != pres)
			re[i].rank = i + 1;
		else
			re[i].rank = re[i - 1].rank;
		pres = re[i].score;
		printf("%s %d %d %d\n", re[i].id.c_str(), re[i].rank, re[i].potid, re[i].potrank);
	}
	return 0;
}