#include<bits/stdc++.h>
using namespace std;

struct mycomp {
	bool operator() (pair<int, string>a, pair<int, string>b) {
		return a.first > b.first;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	char command[5];
	priority_queue<pair<int, string>, vector<pair<int, string>>, mycomp> pq;
	for (int i = 0; i < n; i++) {
		scanf("%s", command);
		if (command[0] == 'P') {
			int priorty;
			char msg_c[15];
			scanf("%s %d", msg_c, &priorty);
			string msg(msg_c);
			pq.push(make_pair(priorty, msg));
		}
		else if (command[0] == 'G') {
			if (pq.empty()) {
				printf("EMPTY QUEUE!\n");
			}
			else {
				auto p = pq.top();
				printf("%s\n", p.second.c_str());
				pq.pop();
			}
		}
	}
	return 0;
}