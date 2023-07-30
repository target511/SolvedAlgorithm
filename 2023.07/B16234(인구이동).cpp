#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, L, R;
vector<vector<int>> map;
vector<vector<bool>> visit;
vector<vector<pair<int, int>>> united;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

bool done() {
	int dn, dm;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < N; m++) {
			for (int d = 2; d < 4; d++) {
				dn = n + delta[d][0];
				dm = m + delta[d][1];

				if (dn >= N || dm >= N)
					continue;

				int diff = abs(map[n][m] - map[dn][dm]);
				if (diff >= L && diff <= R)
					return false;
			}
		}
	}

	return true;
}

void bfs(int n, int m) {
	queue<pair<int, int>> que;
	que.push(make_pair(n, m));
	visit[n][m] = true;

	int unitedIndex = united.size();
	vector<pair<int, int>> tmpv;
	tmpv.push_back(make_pair(n, m));
	united.push_back(tmpv);

	int i, j, di, dj;
	while (!que.empty()) {
		i = que.front().first;
		j = que.front().second;
		que.pop();

		for (int d = 0; d < 4; d++) {
			di = i + delta[d][0];
			dj = j + delta[d][1];

			if (di < 0 || dj < 0 || di >= N || dj >= N ||
				visit[di][dj])
				continue;

			int diff = abs(map[i][j] - map[di][dj]);
			if (diff >= L && diff <= R) {
				que.push(make_pair(di, dj));
				visit[di][dj] = true;
				united[unitedIndex].push_back(make_pair(di, dj));
			}
		}
	}
}

void unite() {
	int sum, avg;
	for (int i = 0; i < united.size(); i++) {
		sum = 0;
		for (int j = 0; j < united[i].size(); j++) {
			sum += map[united[i][j].first][united[i][j].second];
		}

		avg = sum / united[i].size();
		for (int j = 0; j < united[i].size(); j++) {
			map[united[i][j].first][united[i][j].second] = avg;
		}
	}

	united.clear();
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> L >> R;
	map = vector<vector<int>>(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int dn, dm;
	int diff;

	int result = 0;
	while (!done()) {
		visit = vector<vector<bool>>(N, vector<bool>(N));
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < N; m++) {
				if (visit[n][m])
					continue;

				for (int d = 0; d < 4; d++) {
					dn = n + delta[d][0];
					dm = m + delta[d][1];

					if (dn < 0 || dm < 0 || dn >= N || dm >= N ||
						visit[dn][dm])
						continue;

					diff = abs(map[n][m] - map[dn][dm]);
					if (diff >= L && diff <= R) {
						bfs(n, m);
						break;
					}
				}
			}
		}

		unite();
		result++;
	}

	cout << result;

	return 0;
}