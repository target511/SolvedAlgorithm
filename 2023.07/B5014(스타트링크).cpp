#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int F, S, G, U, D;
vector<bool> visit;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> F >> S >> G >> U >> D;

	visit = vector<bool>(F + 1, false);
	queue<pair<int, int>> que;
	que.push(make_pair(S, 0));
	visit[S] = true;

	int result = -1;

	int current, d;
	while (!que.empty()) {
		current = que.front().first;
		d = que.front().second;
		que.pop();

		if (current == G) {
			result = d;
			break;
		}

		if (current + U <= F && !visit[current + U]) {
			que.push(make_pair(current + U, d + 1));
			visit[current + U] = true;
		}
		if (current - D > 0 && !visit[current - D]) {
			que.push(make_pair(current - D, d + 1));
			visit[current - D] = true;
		}
	}

	if (result == -1)
		cout << "use the stairs";
	else
		cout << result;
	

	return 0;
}