#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> nodes;
vector<bool> visit;

void dfs(int n) {
	visit[n] = true;

	int dn;
	for (int d = 0; d < nodes[n].size(); d++) {
		dn = nodes[n][d];

		if (visit[dn])
			continue;

		dfs(dn);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	nodes = vector<vector<int>>(N + 1);
	visit = vector<bool>(N + 1);

	int tmp1, tmp2;
	for (int m = 0; m < M; m++) {
		cin >> tmp1 >> tmp2;
		nodes[tmp1].push_back(tmp2);
		nodes[tmp2].push_back(tmp1);
	}

	int cnt = 0;
	for (int n = 1; n <= N; n++) {
		if (visit[n])
			continue;

		dfs(n);
		cnt++;
	}
	cout << cnt;
	return 0;
}