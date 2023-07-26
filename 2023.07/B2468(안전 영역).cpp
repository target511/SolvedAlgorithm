#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> map;
vector<vector<bool>> safeArea;
vector<vector<bool>> visit;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int maxHeight = 0;

void flood(int h) {
	safeArea = vector<vector<bool>>(N, vector<bool>(N, false));
	visit = vector<vector<bool>>(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] > h)
				safeArea[i][j] = true;
		}
	}
}

void bfs(int n, int m) {
	queue<pair<int, int>> que;
	que.push(make_pair(n, m));
	visit[n][m] = true;

	int i, j, di, dj;
	while (!que.empty()) {
		i = que.front().first;
		j = que.front().second;
		que.pop();
		for (int d = 0; d < 4; d++) {
			di = i + delta[d][0];
			dj = j + delta[d][1];

			if (di < 0 || dj < 0 || di >= N || dj >= N || visit[di][dj] || !safeArea[di][dj])
				continue;

			que.push(make_pair(di, dj));
			visit[di][dj] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	map = vector<vector<int>>(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] > maxHeight)
				maxHeight = map[i][j];
		}
	}

	int result = 0;

	int cnt = 0;
	for (int h = 0; h <= maxHeight; h++) {
		flood(h);
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (safeArea[i][j] && !visit[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		result = cnt > result ? cnt : result;
	}

	cout << result;

	return 0;
}