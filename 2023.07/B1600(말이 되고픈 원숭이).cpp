#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int K, N, M;
vector<vector<int>> map;
vector<vector<vector<bool>>> visit;
int deltaMonkey[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int deltaHorse[8][2] = { {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1} };


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> K >> M >> N;

	map = vector<vector<int>>(N, vector<int>(M));
	visit = vector<vector<vector<bool>>>(N, vector<vector<bool>>(M, vector<bool>(31)));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> map[n][m];
		}
	}

	queue<vector<int>> que;
	que.push({ 0, 0, K, 0 });
	visit[0][0][K] = true;
	int n, m, dn, dm, knight, cnt;
	while (!que.empty()) {
		n = que.front()[0];
		m = que.front()[1];
		knight = que.front()[2];
		cnt = que.front()[3];
		que.pop();
		
		if (n == N - 1 && m == M - 1) {
			cout << cnt;
			return 0;
		}

		if (knight > 0) {
			for (int d = 0; d < 8; d++) {
				dn = n + deltaHorse[d][0];
				dm = m + deltaHorse[d][1];

				if (dn < 0 || dm < 0 || dn >= N || dm >= M ||
					visit[dn][dm][knight - 1] || map[dn][dm] == 1)
					continue;

				que.push({ dn, dm, knight - 1, cnt + 1 });
				visit[dn][dm][knight - 1] = true;
			}
		}

		for (int d = 0; d < 4; d++) {
			dn = n + deltaMonkey[d][0];
			dm = m + deltaMonkey[d][1];

			if (dn < 0 || dm < 0 || dn >= N || dm >= M ||
				visit[dn][dm][knight] || map[dn][dm] == 1)
				continue;

			que.push({ dn, dm, knight, cnt + 1 });
			visit[dn][dm][knight] = true;
		}
	}

	cout << "-1";
	return 0;
}