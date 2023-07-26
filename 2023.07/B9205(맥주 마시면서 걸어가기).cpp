#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int T, N;
vector<pair<int, int>> pos;
vector<vector<int>> nodes;
vector<bool> visit;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int tmp1, tmp2;
		cin >> N;
		cin >> tmp1 >> tmp2;
		pos.push_back(make_pair(tmp1, tmp2));

		nodes = vector<vector<int>>(N + 2);
		for (int n = 1; n <= N + 1; n++) {
			cin >> tmp1 >> tmp2;
			for (int i = 0; i < n; i++) {
				if (abs(pos[i].first - tmp1) + abs(pos[i].second - tmp2) <= 1000) {
					nodes[i].push_back(n);
					nodes[n].push_back(i);
				}
			}
			pos.push_back(make_pair(tmp1, tmp2));
		}

		visit = vector<bool>(N + 2, false);
		queue<int> que;
		que.push(0);
		visit[0] = true;

		int current, next;
		bool festival = false;
		while (!que.empty()) {
			current = que.front();
			que.pop();

			if (current == N + 1) {
				festival = true;
				break;
			}

			for (int i = 0; i < nodes[current].size(); i++) {
				next = nodes[current][i];
				if (visit[next])
					continue;

				que.push(next);
				visit[next] = true;
			}
		}

		if (festival)
			cout << "happy\n";
		else
			cout << "sad\n";

		pos.clear();
		nodes.clear();
		visit.clear();
	}

	return 0;
}