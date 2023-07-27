#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N, M, K;
vector<vector<bool>> map;
vector<vector<bool>> visit;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> M >> N >> K;
		map = vector<vector<bool>>(N, vector<bool>(M));
		visit = vector<vector<bool>>(N, vector<bool>(M));
		int tmp1, tmp2;
		for (int k = 0; k < K; k++) {
			cin >> tmp2 >> tmp1;
			map[tmp1][tmp2] = true;
		}

		queue<pair<int, int>> que;
		int cnt = 0;
		int i, j, di, dj;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (!map[n][m] || visit[n][m])
					continue;

				que.push(make_pair(n, m));
				visit[n][m] = true;
				cnt++;
				while (!que.empty()) {
					i = que.front().first;
					j = que.front().second;
					que.pop();

					for (int d = 0; d < 4; d++) {
						di = i + delta[d][0];
						dj = j + delta[d][1];

						if (di < 0 || dj < 0 || di >= N || dj >= M ||
							visit[di][dj] || !map[di][dj])
							continue;

						que.push(make_pair(di, dj));
						visit[di][dj] = true;
					}
				}
			}
		}

		cout << cnt << '\n';
	}
	

	return 0;
}