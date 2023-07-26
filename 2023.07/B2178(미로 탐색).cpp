#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<bool>> visit;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int main() {
	cin >> N >> M;
	map = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
	visit = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			scanf("%1d", &map[n][m]);
		}
	}

	queue<vector<int>> que;
	que.push({ 1, 1, 1 });
	visit[1][1] = true;

	int result = 0;

	int n, m, l;
	int dn, dm;
	while (!que.empty()) {
		n = que.front()[0];
		m = que.front()[1];
		l = que.front()[2];
		que.pop();

		if (n == N && m == M) {
			result = l;
			break;
		}

		for (int d = 0; d < 4; d++) {
			dn = n + delta[d][0];
			dm = m + delta[d][1];

			if (dn < 1 || dm < 1 || dn > N || dm > M || visit[dn][dm] || map[dn][dm] == 0)
				continue;

			que.push({ dn, dm, l + 1 });
			visit[dn][dm] = true;
		}
	}

	cout << result;

	return 0;
}