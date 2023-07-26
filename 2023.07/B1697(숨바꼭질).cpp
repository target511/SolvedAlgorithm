#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<bool> visit = vector<bool>(100001, false);
int main() {
	cin >> N >> K;

	int move, current, cnt = 0;
	queue<pair<int, int>> que;
	que.push(make_pair(N, 0));
	visit[N] = true;

	while (!que.empty()) {
		current = que.front().first;
		cnt = que.front().second;
		que.pop();

		if (current == K) {
			break;
		}

		move = current + 1;
		if (move <= 100000 && !visit[move]) {
			que.push(make_pair(move, cnt + 1));
			visit[move] = true;
		}

		move = current - 1;
		if (move >= 0 && !visit[move]) {
			que.push(make_pair(move, cnt + 1));
			visit[move] = true;
		}

		move = current * 2;
		if (move <= 100000 && !visit[move]) {
			que.push(make_pair(move, cnt + 1));
			visit[move] = true;
		}
	}

	cout << cnt;
	return 0;
}