#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<vector<int>> nodes;
vector<bool> visit;
queue<int> que;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> K;
	nodes = vector<vector<int>>(N + 1);
	int tmp1, tmp2;
	for (int k = 0; k < K; k++) {
		cin >> tmp1 >> tmp2;
		nodes[tmp1].push_back(tmp2);
		nodes[tmp2].push_back(tmp1);
	}

	int cnt = -1;
	visit = vector<bool>(N + 1, false);
	que.push(1);
	visit[1] = true;
	while (!que.empty()) {
		int node = que.front();
		que.pop();
		cnt++;

		for (int i = 0; i < nodes[node].size(); i++) {
			if (!visit[nodes[node][i]]) {
				que.push(nodes[node][i]);
				visit[nodes[node][i]] = true;
			}
		}
	}

	cout << cnt;
	return 0;
}