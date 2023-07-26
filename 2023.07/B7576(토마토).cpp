#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> box;
vector<vector<bool>> visit;
vector<vector<int>> delta = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> M >> N;
	box = vector<vector<int>>(N, vector<int>(M));
	visit = vector<vector<bool>>(N, vector<bool>(M, false));
	queue<vector<int>> que;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> box[n][m];
			if (box[n][m] == 1) {
				que.push(vector<int>{n, m, 0});
			}
		}
	}
	   
	int cnt = 0;
	int dn, dm;
	while (!que.empty()) {
		for (int d = 0; d < 4; d++) {
			dn = que.front()[0] + delta[d][0];
			dm = que.front()[1] + delta[d][1];

			if (dn < 0 || dm < 0 || dn >= N || dm >= M || visit[dn][dm])
				continue;

			if (box[dn][dm] == 0) {
				que.push({ dn, dm, que.front()[2] + 1 });
				box[dn][dm] = 1;
				visit[dn][dm] = true;
			}
		}
		cnt = que.front()[2];
		que.pop();
	}

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (box[n][m] == 0) {
				cnt = -1;
				n = N;
				break;
			}
		}
	}

	cout << cnt;

	return 0;
}