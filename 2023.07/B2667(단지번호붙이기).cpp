#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> map;
vector<vector<bool>> visit;
queue<pair<int, int>> que;

int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
vector<int> counts;

int main() {
	cin >> N;

	map = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	visit = vector<vector<bool>>(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !visit[i][j]) {
				que.push(make_pair(i, j));
				visit[i][j] = true;

				int count = 0;
				while (!que.empty()) {
					int x = que.front().first;
					int y = que.front().second;
					que.pop();
					count++;

					for (int d = 0; d < 4; d++) {
						int di = x + delta[d][0];
						int dj = y + delta[d][1];

						if (di < 0 || dj < 0 || di >= N || dj >= N) {
							continue;
						}

						if (map[di][dj] == 1 && !visit[di][dj]) {
							que.push(make_pair(di, dj));
							visit[di][dj] = true;
						}
					}
				}

				counts.push_back(count);
			}
		}
	}
	sort(counts.begin(), counts.end());
	cout << counts.size() << '\n';
	for (int i = 0; i < counts.size(); i++) {
		cout << counts[i] << '\n';
	}

	return 0;
}