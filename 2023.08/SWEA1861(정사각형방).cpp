#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N;
vector<vector<int>> map;
vector<vector<int>> visit;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int dfs(int n, int m) {
	int count = 1;

	int dn, dm;
	for (int d = 0; d < 4; d++) {
		dn = n + delta[d][0];
		dm = m + delta[d][1];

		if (dn < 0 || dm < 0 || dn >= N || dm >= N ||
			map[dn][dm] - map[n][m] != 1)
			continue;

		if (visit[dn][dm] > 0) {
			count += visit[dn][dm];
		}
		else {
			count += dfs(dn, dm);
		}
	}

	visit[n][m] = count;
	return count;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		map = vector<vector<int>>(N, vector<int>(N));
		visit = vector<vector<int>>(N, vector<int>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		int tmp;
		int maxMove = 0;
		int maxMoveNumber = N * N + 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				tmp = dfs(i, j);
				if ((tmp > maxMove) || (tmp == maxMove && map[i][j] < maxMoveNumber)) {
					maxMove = tmp;
					maxMoveNumber = map[i][j];
				}
			}
		}
		cout << '#' << t << ' ' << maxMoveNumber << ' ' << maxMove << '\n';
	}

	return 0;
}