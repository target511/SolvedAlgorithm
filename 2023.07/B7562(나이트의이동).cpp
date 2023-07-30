#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N;
int startN, startM, endN, endM;
vector<vector<int>> visit;
int delta[8][2] = { {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1} };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		visit = vector<vector<int>>(N, vector<int>(N));
		cin >> startN >> startM >> endN >> endM;

		queue<pair<int, int>> que;
		que.push(make_pair(startN, startM));
		visit[startN][startM] = 1;
		int dn, dm;
		while (!que.empty()) {
			int n = que.front().first;
			int m = que.front().second;
			que.pop();

			if (n == endN && m == endM) {
				cout << visit[n][m] - 1 << '\n';
				break;
			}

			for (int d = 0; d < 8; d++) {
				dn = n + delta[d][0];
				dm = m + delta[d][1];

				if (dn < 0 || dm < 0 || dn >= N || dm >= N)
					continue;

				if (visit[dn][dm] == 0 || visit[dn][dm] > visit[n][m] + 1) {
					que.push(make_pair(dn, dm));
					visit[dn][dm] = visit[n][m] + 1;
				}
			}
		}
	}

	return 0;
}