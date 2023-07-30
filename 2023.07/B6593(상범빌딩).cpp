#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int L, R, C;
vector<vector<vector<int>>> map;
vector<vector<vector<int>>> visit;
int delta[6][3] = { {0, -1, 0}, {0, 0, -1}, {0, 0, 1}, {0, 1, 0}, {-1, 0, 0}, {1, 0, 0} };
int main() {

	while (true) {
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0)
			return 0;

		map = vector<vector<vector<int>>>(L, vector<vector<int>>(R, vector<int>(C)));
		visit = vector<vector<vector<int>>>(L, vector<vector<int>>(R, vector<int>(C)));
		vector<int> S, E;

		char tmp;
		for (int l = 0; l < L; l++) {
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					scanf("%c", &tmp);
					if (tmp == '\n') {
						c--;
						continue;
					}

					if (tmp == '#')
						map[l][r][c] = '#';
					else if (tmp == '.')
						map[l][r][c] = '.';
					else if (tmp == 'S') {
						map[l][r][c] = '.';
						S.push_back(l);
						S.push_back(r);
						S.push_back(c);
					}
					else if (tmp == 'E') {
						map[l][r][c] = '.';
						E.push_back(l);
						E.push_back(r);
						E.push_back(c);
					}
				}
			}
		}

		queue<vector<int>> que;
		int l, r, c, dl, dr, dc;
		que.push(S);
		while (!que.empty()) {
			l = que.front()[0];
			r = que.front()[1];
			c = que.front()[2];
			que.pop();

			if (l == E[0] && r == E[1] && c == E[2]) {
				cout << "Escaped in " << visit[l][r][c] << " minute(s).\n";
				break;
			}

			for (int d = 0; d < 6; d++) {
				dl = l + delta[d][0];
				dr = r + delta[d][1];
				dc = c + delta[d][2];

				if (dl < 0 || dr < 0 || dc < 0 || dl >= L || dr >= R || dc >= C ||
					map[dl][dr][dc] == '#')
					continue;

				if (visit[dl][dr][dc] == 0 || visit[dl][dr][dc] > visit[l][r][c] + 1) {
					que.push({ dl, dr, dc });
					visit[dl][dr][dc] = visit[l][r][c] + 1;
				}
			}
		}

		if (visit[E[0]][E[1]][E[2]] == 0)
			cout << "Trapped!\n";
	}

	return 0;
}