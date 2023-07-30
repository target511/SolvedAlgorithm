#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<bool>> visit;
vector<pair<int, int>> blanks;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int wall = 0;
int result = 0;

void spreadAndCalcVirus() {
	visit = vector<vector<bool>>(N, vector<bool>(M));
	queue<pair<int, int>> que;

	int cnt = 0;
	int i, j, di, dj;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (map[n][m] == 2 && !visit[n][m]) {
				que.push(make_pair(n, m));
				visit[n][m] = true;
			}

			while (!que.empty()) {
				i = que.front().first;
				j = que.front().second;
				que.pop();
				cnt++;

				for (int d = 0; d < 4; d++) {
					di = i + delta[d][0];
					dj = j + delta[d][1];

					if (di < 0 || dj < 0 || di >= N || dj >= M ||
						visit[di][dj] || map[di][dj] == 1)
						continue;

					que.push(make_pair(di, dj));
					visit[di][dj] = true;
				}
			}
		}
	}

	int virus = N * M - wall - 3 - cnt;
	result = virus > result ? virus : result;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;

	map = vector<vector<int>>(N, vector<int>(M));
	visit = vector<vector<bool>>(N, vector<bool>(M));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> map[n][m];

			if (map[n][m] == 1) {
				wall++;
			}
			else if (map[n][m] == 0) {
				blanks.push_back(make_pair(n, m));
			}
		}
	}

	// DFS로 할 수 있긴 한데 굳이..?
	for (int i = 0; i < blanks.size(); i++) {
		map[blanks[i].first][blanks[i].second] = 1;
		for (int j = i + 1; j < blanks.size(); j++) {
			map[blanks[j].first][blanks[j].second] = 1;
			for (int k = j + 1; k < blanks.size(); k++) {
				map[blanks[k].first][blanks[k].second] = 1;

				spreadAndCalcVirus();

				map[blanks[k].first][blanks[k].second] = 0;
			}
			map[blanks[j].first][blanks[j].second] = 0;
		}
		map[blanks[i].first][blanks[i].second] = 0;
	}

	cout << result << '\n';

	return 0;
}