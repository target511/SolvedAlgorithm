#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K;
vector<vector<bool>> land;
vector<vector<bool>> visit;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
vector<int> result;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M >> K;
	land = vector<vector<bool>>(N, vector<bool>(M));
	visit = vector<vector<bool>>(N, vector<bool>(M));

	int x1, x2, y1, y2;
	for (int k = 0; k < K; k++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				land[y][x] = true;
			}
		}
	}

	queue<pair<int, int>> que;
	int i, j, di, dj, cnt;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (land[n][m] || visit[n][m])
				continue;

			cnt = 0;
			que.push(make_pair(n, m));
			visit[n][m] = true;

			while (!que.empty()) {
				i = que.front().first;
				j = que.front().second;
				que.pop();
				cnt++;

				for (int d = 0; d < 4; d++) {
					di = i + delta[d][0];
					dj = j + delta[d][1];

					if (di < 0 || dj < 0 || di >= N || dj >= M ||
						visit[di][dj] || land[di][dj])
						continue;

					que.push(make_pair(di, dj));
					visit[di][dj] = true;
				}
			}
			result.push_back(cnt);
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}

	return 0;
}