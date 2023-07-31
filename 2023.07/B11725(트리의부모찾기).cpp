#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> nodes;
vector<int> parent;
vector<bool> visit;

void dfs(int n) {
	visit[n] = true;

	int dn;
	for (int d = 0; d < nodes[n].size(); d++) {
		dn = nodes[n][d];

		if (visit[dn])
			continue;

		parent[dn] = n;
		dfs(dn);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	nodes = vector<vector<int>>(N + 1);
	int tmp1, tmp2;
	for (int n = 0; n < N - 1; n++) {
		cin >> tmp1 >> tmp2;
		nodes[tmp1].push_back(tmp2);
		nodes[tmp2].push_back(tmp1);
	}
	
	visit = vector<bool>(N + 1);
	parent = vector<int>(N + 1);
	dfs(1);
	for (int n = 2; n <= N; n++) {
		cout << parent[n] << '\n';
	}
	
	return 0;
}