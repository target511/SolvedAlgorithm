#include <iostream>
#include <vector>
using namespace std;

const int N = 12;
const int M = 6;
vector<vector<char>> map;
vector<vector<int>> visit;
vector<pair<int, int>> search;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int dfsCount;

bool puyo() {
	bool ret = false;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (visit[n][m] >= 4) {
				ret = true;
				map[n][m] = '.';
			}
		}
	}

	if (!ret) {
		return false;
	}

	vector<string> strs(M);
	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			if (map[n][m] == '.')
				continue;

			strs[m] += map[n][m];
		}
	}

	for (int m = 0; m < M; m++) {
		int n;
		for (n = 0; n < strs[m].size(); n++) {
			map[n][m] = strs[m][n];
		}
		for (; n < N; n++) {
			map[n][m] = '.';
		}
	}

	return true;
}

void dfs(int n, int m, char color) {
	visit[n][m] = dfsCount;
	search.push_back(make_pair(n, m));

	int dn, dm;
	for (int d = 0; d < 4; d++) {
		dn = n + delta[d][0];
		dm = m + delta[d][1];

		if (dn < 0 || dm < 0 || dn >= N || dm >= M ||
			map[dn][dm] != color || visit[dn][dm] > 0)
			continue;

		dfsCount++;
		dfs(dn, dm, color);
	}

	if (visit[n][m] >= 4) {
		for (int i = 0; i < search.size(); i++) {
			visit[search[i].first][search[i].second] = 4;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	map = vector<vector<char>>(N, vector<char>(M));
	string tmp;
	for (int n = N - 1; n >= 0; n--) {
		cin >> tmp;
		for (int m = 0; m < M; m++) {
			map[n][m] = tmp[m];
		}
	}

	int cnt = -1;

	do {
		cnt++;
		visit = vector<vector<int>>(N, vector<int>(M));
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (visit[n][m] > 0 || map[n][m] == '.')
					continue;

				dfsCount = 1;
				dfs(n, m, map[n][m]);
				search.clear();
			}
		}
	} while (puyo());

	cout << cnt;

	return 0;
}