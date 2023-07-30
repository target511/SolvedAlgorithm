#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, H, W;
vector<string> map;
vector<vector<int>> visit;
vector<vector<int>> fireVisit;
pair<int, int> start;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> W >> H;
		map = vector<string>(H);
		visit = vector<vector<int>>(H, vector<int>(W));
		fireVisit = vector<vector<int>>(H, vector<int>(W));

		char tmp;
		for (int h = 0; h < H; h++) {
			cin >> map[h];
			for (int w = 0; w < W; w++) {
				if (map[h][w] == '@') {
					map[h][w] = '.';
					start.first = h;
					start.second = w;
				}
			}
		}
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				if (map[h][w] != '*')
					continue;

				queue<pair<int, int>> que;
				que.push(make_pair(h, w));
				fireVisit[h][w] = 1;

				int n, m, dn, dm;
				while (!que.empty()) {
					n = que.front().first;
					m = que.front().second;
					que.pop();

					for (int d = 0; d < 4; d++) {
						dn = n + delta[d][0];
						dm = m + delta[d][1];

						if (dn < 0 || dm < 0 || dn >= H || dm >= W ||
							map[dn][dm] != '.')
							continue;

						if (fireVisit[dn][dm] == 0 || fireVisit[dn][dm] > fireVisit[n][m] + 1) {
							que.push(make_pair(dn, dm));
							fireVisit[dn][dm] = fireVisit[n][m] + 1;
						}
					}
				}
			}
		}

		queue<pair<int, int>> que;
		que.push(start);
		visit[start.first][start.second] = 1;

		int h, w, dh, dw;
		bool possible = false;
		while (!que.empty()) {
			h = que.front().first;
			w = que.front().second;
			que.pop();

			if (h == 0 || w == 0 || h == H - 1 || w == W - 1) {
				possible = true;
				break;
			}

			for (int d = 0; d < 4; d++) {
				dh = h + delta[d][0];
				dw = w + delta[d][1];

				if (dh < 0 || dw < 0 || dh >= H || dw >= W ||
					map[dh][dw] != '.' || (fireVisit[dh][dw] != 0 && fireVisit[dh][dw] <= visit[h][w] + 1))
					continue;

				if (visit[dh][dw] == 0 || visit[dh][dw] > visit[h][w] + 1) {
					que.push(make_pair(dh, dw));
					visit[dh][dw] = visit[h][w] + 1;
				}
			}
		}

		if (possible) 
			cout << visit[h][w] << '\n';
		else 
			cout << "IMPOSSIBLE\n";
	}

	return 0;
}