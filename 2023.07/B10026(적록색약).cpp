#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<char>> mapNormal;
vector<vector<char>> mapAbnormal;
vector<vector<bool>> visit;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int bfs(vector<vector<char>> map) {
	visit = vector<vector<bool>>(N, vector<bool>(N, false));
	queue<pair<int, int>> que;
	int cnt = 0;
	int di, dj;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				cnt++;
				que.push(make_pair(i, j));
				visit[i][j] = true;

				while (!que.empty()) {
					int n = que.front().first;
					int m = que.front().second;
					que.pop();

					for (int d = 0; d < 4; d++) {
						di = n + delta[d][0];
						dj = m + delta[d][1];

						if (di < 0 || dj < 0 || di >= N || dj >= N || visit[di][dj])
							continue;

						if (map[n][m] == map[di][dj]) {
							que.push(make_pair(di, dj));
							visit[di][dj] = true;
						}
					}
				}
			}
		}
	}

	return cnt;
}

int main() {
	cin >> N;

	mapNormal = vector<vector<char>>(N, vector<char>(N));
	mapAbnormal = vector<vector<char>>(N, vector<char>(N));

	char tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%c", &tmp);
			if (tmp == '\n') {
				j--;
				continue;
			}

			if (tmp == 'R')
				mapAbnormal[i][j] = 'G';
			else
				mapAbnormal[i][j] = tmp;

			mapNormal[i][j] = tmp;
		}
	}

	cout << bfs(mapNormal) << ' ' << bfs(mapAbnormal);


	return 0;
}