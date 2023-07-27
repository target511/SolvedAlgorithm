#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<bool>> map;
vector<vector<bool>> visit;
int delta[3] = { -1, 0, 1 };
int main() {
	while (true) {
		ios::sync_with_stdio(false); cin.tie(NULL);
		cin >> M >> N;

		if (N == 0 && M == 0)
			break;

		map = vector<vector<bool>>(N, vector<bool>(M));
		visit = vector<vector<bool>>(N, vector<bool>(M));
		int tmp;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				cin >> tmp;
				if (tmp == 1)
					map[n][m] = true;
				else
					map[n][m] = false;
			}
		}

		queue<pair<int, int>> que;
		int i, j, di, dj, cnt = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (visit[n][m] || !map[n][m])
					continue;

				que.push(make_pair(n, m));
				visit[n][m] = true;
				cnt++;

				while (!que.empty()) {
					i = que.front().first;
					j = que.front().second;
					que.pop();

					for (int d1 = 0; d1 < 3; d1++) {
						for (int d2 = 0; d2 < 3; d2++) {
							di = i + delta[d1];
							dj = j + delta[d2];

							if (di < 0 || dj < 0 || di >= N || dj >= M ||
								visit[di][dj] || !map[di][dj])
								continue;

							que.push(make_pair(di, dj));
							visit[di][dj] = true;
						}
					}
				}
			}
		}

		cout << cnt << '\n';
	}
	
	return 0;
}