#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> nodes;
vector<bool> visit;
bool able = false;

void dfs(int n, int depth) {
	if (able || depth == 5) {
		able = true;
		return;
	}

	int next;
	for (int i = 0; i < nodes[n].size(); i++) {
		next = nodes[n][i];

		if (visit[next])
			continue;

		visit[next] = true;
		dfs(next, depth + 1);
		visit[next] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	nodes = vector<vector<int>>(N);
	visit = vector<bool>(N);
	int tmp1, tmp2;
	for (int m = 0; m < M; m++) {
		cin >> tmp1 >> tmp2;
		nodes[tmp1].push_back(tmp2);
		nodes[tmp2].push_back(tmp1);
	}

	for (int n = 0; n < N; n++) {
		if (able) {
			cout << '1';
			return 0;
		}
		visit[n] = true;
		dfs(n, 1);
		visit[n] = false;
	}

	cout << '0';

	return 0;
}