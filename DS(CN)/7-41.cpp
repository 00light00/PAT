/*
	�������������������ԣ�Programming Ability Test�����PAT��ּ��ͨ��ͳһ��֯�����߿��Լ��Զ����ⷽ���͹۵����п������㷨�����������ʵ����������ѧ�����ۼ������������˲ţ�Ϊ��ҵѡ���˲��ṩ�ο���׼����ַhttp://www.patest.cn����

ÿ�ο��Ի������ɸ���ͬ�Ŀ���ͬʱ���У�ÿ�������þ�����������������ĳɼ������Խ����󣬸�������ĳɼ������̻��ܳ�һ���ܵ�������

���ھ�����дһ�������Զ��鲢��������ĳɼ���������������

�����ʽ:
����ĵ�һ�и���һ��������N����100����������������������N������ĳɼ�����ʽΪ������һ�и���������K����300��������ÿ���Ŀ������������K�У�ÿ�и���1����������Ϣ���������ţ���13λ��������ɣ��͵÷֣�Ϊ[0,100]�����ڵ����������м��ÿո�ָ���

�����ʽ:
�����ڵ�һ��������������������������ܵ�������ÿ����������Ϣռһ�У�˳��Ϊ�����š����������������š��ڸÿ�������������п��㰴���������˳���1��N��š�����������밴���������ķǵݼ�˳������������ͬ�����Ŀ���Ӧ����ͬ���Σ��������ŵĵ���˳�������

��������:
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
�������:
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