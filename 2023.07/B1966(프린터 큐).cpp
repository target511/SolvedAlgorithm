#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
queue<pair<int, bool>> que;
vector<int> priority;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		priority = vector<int>(10, 0);
		que = queue<pair<int, bool>>();
		int p;
		for (int n = 0; n < N; n++) {
			cin >> p;
			if (n == M) {
				que.push(make_pair(p, true));
			}
			que.push(make_pair(p, false));
			priority[p]++;
		}

		int cnt = 0;
		int result = 0;
		for (int i = 9; i > 0; i--) {
			while (priority[i] > 0) {
				if (que.front().first == i) {
					priority[i]--;
					cnt++;
					if (que.front().second) {
						result = cnt;
					}
					que.pop();
				}
				else {
					que.push(make_pair(que.front().first, que.front().second));
					que.pop();
				}
			}
		}

		cout << result << '\n';
	}

	return 0;
}