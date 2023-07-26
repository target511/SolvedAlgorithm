#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
vector<vector<bool>> nodes;
vector<bool> visit;

void dfs(int node) {
	visit[node] = true;
	cout << node << ' ';

	for (int n = 1; n <= N; n++) {
		if (nodes[node][n] && !visit[n]) {
			dfs(n);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M >> V;

	nodes = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
	visit = vector<bool>(N + 1, false);
	int tmp1, tmp2;
	for (int m = 0; m < M; m++) {
		cin >> tmp1 >> tmp2;
		nodes[tmp1][tmp2] = true;
		nodes[tmp2][tmp1] = true;
	}

	dfs(V);
	cout << '\n';

	queue<int> que;
	visit = vector<bool>(N + 1, false);
	que.push(V);
	visit[V] = true;

	int node;
	while (!que.empty()) {
		node = que.front();
		cout << node << ' ';
		que.pop();

		for (int n = 1; n <= N; n++) {
			if (!nodes[node][n] || visit[n])
				continue;

			que.push(n);
			visit[n] = true;
		}
	}
	cout << '\n';

	return 0;
}