#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, H;
vector<vector<vector<int>>> box;
vector<vector<vector<bool>>> visit;
vector<vector<int>> delta = { {0, -1, 0}, {0, 0, -1}, {0, 0, 1}, {0, 1, 0}, {-1, 0, 0}, {1, 0, 0} };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> M >> N >> H;
	box = vector<vector<vector<int>>>(H, vector<vector<int>>(N, vector<int>(M)));
	visit = vector<vector<vector<bool>>>(H, vector<vector<bool>>(N, vector<bool>(M, false)));
	queue<vector<int>> que;
	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				cin >> box[h][n][m];
				if (box[h][n][m] == 1) {
					que.push(vector<int>{h, n, m, 0});
				}
			}
		}
	}

	int cnt = 0;
	int dh, dn, dm;
	while (!que.empty()) {
		for (int d = 0; d < 6; d++) {
			dh = que.front()[0] + delta[d][0];
			dn = que.front()[1] + delta[d][1];
			dm = que.front()[2] + delta[d][2];

			if (dh < 0 || dn < 0 || dm < 0 || dh >= H || dn >= N || dm >= M || visit[dh][dn][dm])
				continue;

			if (box[dh][dn][dm] == 0) {
				que.push({ dh, dn, dm, que.front()[3] + 1 });
				box[dh][dn][dm] = 1;
				visit[dh][dn][dm] = true;
			}
		}
		cnt = que.front()[3];
		que.pop();
	}
	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (box[h][n][m] == 0) {
					cnt = -1;
					n = N;
					break;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}