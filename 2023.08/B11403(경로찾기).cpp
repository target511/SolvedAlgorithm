#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> nodes;
vector<bool> visit;
vector<vector<int>> result;

bool dfs(int start, int target) {
	if (nodes[start][target] == 1) {
		return true;
	}
	
	visit[start] = true;

	for (int n = 0; n < N; n++) {
		if (nodes[start][n] == 0 || visit[n])
			continue;

		if (dfs(n, target)) {
			return true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	nodes = vector<vector<int>>(N, vector<int>(N));
	visit = vector<bool>(N);
	result = vector<vector<int>>(N, vector<int>(N));

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < N; m++) {
			cin >> nodes[n][m];
		}
	}

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < N; m++) {
			visit = vector<bool>(N);
			if (dfs(n, m)) {
				result[n][m] = 1;
			}

			cout << result[n][m] << ' ';
		}
		cout << '\n';
	}

	return 0;
}