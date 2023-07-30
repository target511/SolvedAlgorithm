#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<vector<int>>> visit;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int main() {
	cin >> N >> M;
	map = vector<vector<int>>(N, vector<int>(M));
	visit = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(2)));
	string tmp = "";
	for (int n = 0; n < N; n++) {
		cin >> tmp;
		for (int m = 0; m < M; m++) {
			if (tmp[m] == '1')
				map[n][m] = 1;
		}
	}

	queue<vector<int>> que;
	que.push({ 0, 0, 1 });
	visit[0][0][1] = 1;

	int n, m, k, dn, dm;
	while (!que.empty()) {
		n = que.front()[0];
		m = que.front()[1];
		k = que.front()[2];
		que.pop();

		if (n == N - 1 && m == M - 1) {
			cout << visit[n][m][k];
			return 0;
		}

		for (int d = 0; d < 4; d++) {
			dn = n + delta[d][0];
			dm = m + delta[d][1];

			if (dn < 0 || dm < 0 || dn >= N || dm >= M)
				continue;

			if (map[dn][dm] == 0 && 
				(visit[dn][dm][k] == 0 || visit[dn][dm][k] > visit[n][m][k] + 1)) {
				que.push({ dn, dm, k });
				visit[dn][dm][k] = visit[n][m][k] + 1;
			}

			if (map[dn][dm] == 1 && k == 1 && 
				(visit[dn][dm][0] == 0 || visit[dn][dm][0] > visit[n][m][1] + 1)) {
				que.push({ dn, dm, 0 });
				visit[dn][dm][0] = visit[n][m][1] + 1;
			}
		}
	}

	cout << "-1";
	return 0;
}