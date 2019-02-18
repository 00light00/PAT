#include<bits/stdc++.h>
using namespace std;

const int MAX = 505;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
vector<pii> grapht[MAX],graphl[MAX];
int minl[MAX],minl2[MAX];
int mint[MAX],mint2[MAX];
int prel[MAX];
int pret[MAX];
int visit[MAX];

void dijstra(vector<pii> graph[], int min[],int min2[], int pre[], int visit[], int s, int e) {
	while (!pq.empty())
		pq.pop();
	memset(min, 127, sizeof(min));
	memset(visit, 0, sizeof(visit));

	min[s] = 0;
	pq.push(make_pair(min[s], s));

	while (!pq.empty()) {
		int intersection = pq.top().second;
		pq.pop();
		if (!visit[intersection]) {
			visit[intersection] = 1;
			for (auto it = graph[intersection].begin(); it != graph[intersection].end(); it++) {
				int street = it->second, weight = it->first;
				if (min[street] > weight + min[intersection]) {
					min[street] = weight + min[intersection];
					pre[street] = intersection;
				}
				else if (min[street] == weight + min[intersection]) {
					if()
				}
			}
		}
	}

}

int main() {
	int n, m, s, e;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v1, v2, oneway, len, time;
		scanf("%d %d %d %d %d", &v1, &v2, &oneway, &len, &time);
		graphl[v1].push_back(make_pair(v2, len));
		grapht[v1].push_back(make_pair(v2, time));
		if (!oneway) {
			graphl[v2].push_back(make_pair(v1, len));
			grapht[v2].push_back(make_pair(v1, time));
		}
	}
	scanf("%d %d", &s, &e);
	dijstra(grapht, mint, mint2, pret, visit, s, e);
	dijstra(graphl, minl, minl2, prel, visit, s, e);



	return 0;
}