#include<bits/stdc++.h>
using namespace std;

int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

int main() {
	int m, n, tol;
	scanf("%d %d %d", &m, &n, &tol);
	vector<vector<long long> >val;
	map<int, int>val_map;
	for (int i = 0; i < n; i++) {
		vector<long long> line;
		for (int j = 0; j < m; j++) {
			long long val_t;
			scanf("%lld", &val_t);
			line.push_back(val_t);
			val_map[val_t]++;
		}
		val.push_back(line);
	}

	vector<pair<int, int> > re;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (val_map[val[i][j]] == 1) {
				int flag = 1;
				for (int k = 0; k < 8; k++) {
					int ii = i + dir[k][0];
					int jj = j + dir[k][1];
					if (ii >= 0 && ii < n&&jj >= 0 && jj < m) {
						if (abs(val[ii][jj] - val[i][j]) <= tol) {
							flag = 0;
							break;
						}
					}
				}
				if(flag)
					re.push_back(make_pair(j + 1, i + 1));
			}
		}
	}
	if (re.size() == 0) {
		cout << "Not Exist" << endl;
	}
	else if (re.size() == 1) {
		cout << "(" << re[0].first << ", " << re[0].second << "): " << val[re[0].second - 1][re[0].first - 1] << endl;
	}
	else {
		cout << "Not Unique" << endl;
	}

	return 0;
}