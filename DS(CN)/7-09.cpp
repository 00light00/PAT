#include<bits/stdc++.h>
using namespace std;

const int MAX = 250001;
struct City {
	int len, cost;
	City() {};
	City(int l, int c) :len(l), cost(c) {};
	bool operator<(City op) const{
		return len != op.len ? len < op.len : cost < op.cost;
	}
};

typedef pair<City, int> pci;
priority_queue<pci, vector<pci>, greater<pci> >pq;

void Dijkstra1(int s, vector<vector<City> > & graph, int n);
void Dijkstra2(int s, vector<vector<City> > & graph, int n);

int main() {
	int n, m, s, d;
	scanf("%d %d %d %d", &n, &m, &s, &d);
	vector<vector<City>>graph(n, vector<City>(n, City(MAX, MAX)));
	for (int i = 0; i < m; i++) {
		int c1, c2, len, cost;
		scanf("%d %d %d %d", &c1, &c2, &len, &cost);
		graph[c1][c2] = graph[c2][c1] = City(len, cost);
	}
	Dijkstra1(s, graph, n);
	printf("%d %d\n", graph[s][d].len, graph[s][d].cost);
	return 0;
}

void Dijkstra1(int s, vector<vector<City> > & graph, int n) {

	vector<int> visit(n, 0);

	visit[s] = 1;
	
	while (1) {
		int city = s;

		City min_city(MAX, MAX);
		for (int i = 0; i < n; i++) {

			if (!visit[i]) {
				if (graph[s][i] < min_city) {
					min_city = graph[s][i];
					city = i;
				}
			}
		}
		if (city == s)
			break;
		visit[city] = 1;
		for (int i = 0; i < n; i++) {
			if (graph[city][i].len < MAX && !visit[i]) {
				int len = graph[city][i].len + min_city.len;
				int cost = graph[city][i].cost + min_city.cost;
				City op(len, cost);
				if (op < graph[s][i]) {
					graph[i][s] = graph[s][i] = City(len, cost);
				}
			}
		}
	}
}


void Dijkstra2(int s, vector<vector<City> > & graph, int n) {

	vector<int> visit(n, 0);
	visit[s] = 1;

	pq.push(pci(graph[s][i], s));

	while (1) {
		int city = s;

		City min_city = pq.top();
		for (int i = 0; i < n; i++) {

			if (!visit[i]) {
				if (graph[s][i] < min_city) {
					min_city = graph[s][i];
					city = i;
				}
			}
		}
		if (city == s)
			break;
		visit[city] = 1;
		for (int i = 0; i < n; i++) {
			if (graph[city][i].len < MAX && !visit[i]) {
				int len = graph[city][i].len + min_city.len;
				int cost = graph[city][i].cost + min_city.cost;
				City op(len, cost);
				if (op < graph[s][i]) {
					graph[i][s] = graph[s][i] = City(len, cost);
				}
			}
		}
	}
}