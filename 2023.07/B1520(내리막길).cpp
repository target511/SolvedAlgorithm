#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> memo;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int result = 0;

int dfs(int n, int m) {
	if (n == N - 1 && m == M - 1) {
		return 1;
	}

	if (memo[n][m] != -1)
		return memo[n][m];

	memo[n][m] = 0;
	int dn, dm;
	for (int d = 0; d < 4; d++) {
		dn = n + delta[d][0];
		dm = m + delta[d][1];

		if (dn < 0 || dm < 0 || dn >= N || dm >= M)
			continue;

		if (map[n][m] > map[dn][dm]) {
			memo[n][m] += dfs(dn, dm);
		}
	}

	return memo[n][m];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	map = vector<vector<int>>(N, vector<int>(M));
	memo = vector<vector<int>>(N, vector<int>(M, -1));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> map[n][m];
		}
	}

	cout << dfs(0, 0);

	return 0;
}