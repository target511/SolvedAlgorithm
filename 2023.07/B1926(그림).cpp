#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<bool>> visit;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	map = vector<vector<int>>(N, vector<int>(M));
	visit = vector<vector<bool>>(N, vector<bool>(M));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> map[n][m];
		}
	}

	queue<pair<int, int>> que;
	int i, j, di, dj;
	int maxSize = 0;
	int cnt = 0;

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (map[n][m] == 0 || visit[n][m])
				continue;

			que.push(make_pair(n, m));
			visit[n][m] = true;
			cnt++;
			int size = 0;
			while (!que.empty()) {
				int i = que.front().first;
				int j = que.front().second;
				que.pop();
				size++;

				for (int d = 0; d < 4; d++) {
					di = i + delta[d][0];
					dj = j + delta[d][1];

					if (di < 0 || dj < 0 || di >= N || dj >= M ||
						visit[di][dj] || map[di][dj] == 0)
						continue;

					que.push(make_pair(di, dj));
					visit[di][dj] = true;
				}
			}

			maxSize = size > maxSize ? size : maxSize;
		}
	}

	cout << cnt << '\n' << maxSize;
	return 0;
}