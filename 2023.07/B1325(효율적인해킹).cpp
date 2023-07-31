#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> nodes;
vector<bool> visit;
vector<int> result;

int dfs(int n) {
	visit[n] = true;
	int cnt = 1;
	int dn;
	for (int d = 0; d < nodes[n].size(); d++) {
		dn = nodes[n][d];

		if (visit[dn])
			continue;

		cnt += dfs(dn);
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;

	nodes = vector<vector<int>>(N + 1);
	int tmp1, tmp2;
	for (int m = 0; m < M; m++) {
		cin >> tmp1 >> tmp2;
		nodes[tmp2].push_back(tmp1);
	}

	int maxCount = 0;
	int maxNode = 0;
	result.push_back(0);
	for (int n = 1; n <= N; n++) {
		visit = vector<bool>(N + 1);
		int count = dfs(n);
		result.push_back(count);
		if (maxCount < count) {
			maxCount = count;
		}
	}
	
	for (int n = 1; n <= N; n++) {
		if (result[n] == maxCount)
			cout << n << ' ';
	}

	return 0;
}