#include <iostream>
#include <vector>
using namespace std;

int R, C;
vector<vector<char>> map;
vector<bool> visit;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int result = 0;

void dfs(int r, int c, int num) {
	result = num > result ? num : result;

	int dr, dc;
	for (int d = 0; d < 4; d++) {
		dr = r + delta[d][0];
		dc = c + delta[d][1];

		if (dr < 0 || dc < 0 || dr >= R || dc >= C ||
			visit[map[dr][dc]])
			continue;

		visit[map[dr][dc]] = true;
		dfs(dr, dc, num + 1);
		visit[map[dr][dc]] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> R >> C;
	map = vector<vector<char>>(R, vector<char>(C));
	visit = vector<bool>(91);
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];
		}
	}

	visit[map[0][0]] = true;
	dfs(0, 0, 1);

	cout << result;

	return 0;
}