#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int HORIZONTAL = 0;
const int VERTICAL = 1;

int N;
vector<vector<char>> map;
vector<vector<vector<bool>>> visit;
int deltaVerticalLeft[3][2] = { {-1, -1}, {0, -1}, {1, -1} };
int deltaHorizontalUpper[3][2] = { {-1, -1}, {-1, 0}, {-1, 1} };
int deltaRotate[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	map = vector<vector<char>>(N, vector<char>(N));
	visit = vector<vector<vector<bool>>>(N, vector<vector<bool>>(N, vector<bool>(2)));

	int startN, startM, endN, endM;
	string str;
	int cntB = 0, cntE = 0;
	int startType, endType;
	for (int n = 0; n < N; n++) {
		cin >> str;
		for (int m = 0; m < N; m++) {
			map[n][m] = str[m];
			if (map[n][m] == 'B') {
				cntB++;
				if (cntB == 2) {
					startN = n;
					startM = m;
					if (m > 0 && map[n][m - 1] == 'B')
						startType = HORIZONTAL;
					else
						startType = VERTICAL;
				}
			}
			else if (map[n][m] == 'E') {
				cntE++;
				if (cntE == 2) {
					endN = n;
					endM = m;
					if (m > 0 && map[n][m - 1] == 'E')
						endType = HORIZONTAL;
					else
						endType = VERTICAL;
				}
			}
		}
	}

	queue<vector<int>> que;
	int n, m, dn, dm;
	int nowType, move;
	que.push({ startN, startM, startType, 0 });
	visit[startN][startM][startType] = true;
	while (!que.empty()) {
		n = que.front()[0];
		m = que.front()[1];
		nowType = que.front()[2];
		move = que.front()[3];
		que.pop();

		if (n == endN && m == endM && nowType == endType) {
			cout << move;
			return 0;
		}

		if (nowType == VERTICAL) { // 세로
			// U
			dn = n - 2;
			dm = m;
			if (dn >= 0 && map[dn][dm] != '1' && !visit[n - 1][m][nowType]) { 
				que.push({ n - 1, m, VERTICAL, move + 1 });
				visit[n - 1][m][VERTICAL] = true;
			}

			// D
			dn = n + 2;
			dm = m;
			if (dn < N && map[dn][dm] != '1' && !visit[n + 1][m][nowType]) { 
				que.push({ n + 1, m, VERTICAL, move + 1 });
				visit[n + 1][m][VERTICAL] = true;
			}

			// L
			int flag = true;
			for (int d = 0; d < 3; d++) {
				dn = n + deltaVerticalLeft[d][0];
				dm = m + deltaVerticalLeft[d][1];

				if (dm < 0 || map[dn][dm] == '1') {
					flag = false;
					break;
				}
			}
			if (flag && !visit[n][m - 1][VERTICAL]) {
				que.push({ n, m - 1, VERTICAL, move + 1 });
				visit[n][m - 1][VERTICAL] = true;
			}

			// R
			flag = true;
			for (int d = 0; d < 3; d++) {
				dn = n - deltaVerticalLeft[d][0];
				dm = m - deltaVerticalLeft[d][1];

				if (dm >= N || map[dn][dm] == '1') {
					flag = false;
					break;
				}
			}
			if (flag && !visit[n][m + 1][VERTICAL]) {
				que.push({ n, m + 1, VERTICAL, move + 1 });
				visit[n][m + 1][VERTICAL] = true;
			}

			// T
			flag = true;
			for (int d = 0; d < 8; d++) {
				dn = n + deltaRotate[d][0];
				dm = m + deltaRotate[d][1];

				if (dn < 0 || dm < 0 || dn >= N || dm >= N || map[dn][dm] == '1') {
					flag = false;
					break;
				}
			}
			if (flag && !visit[n][m][HORIZONTAL]) {
				que.push({ n, m, HORIZONTAL, move + 1 });
				visit[n][m][HORIZONTAL] = true;
			}
		}
		else { // 가로
			// U
			bool flag = true;
			for (int d = 0; d < 3; d++) {
				dn = n + deltaHorizontalUpper[d][0];
				dm = m + deltaHorizontalUpper[d][1];

				if (dn < 0 || map[dn][dm] == '1') {
					flag = false;
					break;
				}
			}
			if (flag && !visit[n - 1][m][HORIZONTAL]) {
				que.push({ n - 1, m, HORIZONTAL, move + 1 });
				visit[n - 1][m][HORIZONTAL] = true;
			}

			// D
			flag = true;
			for (int d = 0; d < 3; d++) {
				dn = n - deltaHorizontalUpper[d][0];
				dm = m - deltaHorizontalUpper[d][1];

				if (dn >= N || map[dn][dm] == '1') {
					flag = false;
					break;
				}
			}
			if (flag && !visit[n + 1][m][HORIZONTAL]) {
				que.push({ n + 1, m, HORIZONTAL, move + 1 });
				visit[n + 1][m][HORIZONTAL] = true;
			}

			// L
			dn = n;
			dm = m - 2;
			if (dm >= 0 && map[dn][dm] != '1' && !visit[n][m - 1][nowType]) {
				que.push({ n, m - 1, HORIZONTAL, move + 1 });
				visit[n][m - 1][HORIZONTAL] = true;
			}

			// R
			dn = n;
			dm = m + 2;
			if (dm < N && map[dn][dm] != '1' && !visit[n][m + 1][nowType]) {
				que.push({ n, m + 1, HORIZONTAL, move + 1 });
				visit[n][m + 1][HORIZONTAL] = true;
			}
			
			// T
			flag = true;
			for (int d = 0; d < 8; d++) {
				dn = n + deltaRotate[d][0];
				dm = m + deltaRotate[d][1];

				if (dn < 0 || dm < 0 || dn >= N || dm >= N || map[dn][dm] == '1') {
					flag = false;
					break;
				}
			}
			if (flag && !visit[n][m][VERTICAL]) {
				que.push({ n, m, VERTICAL, move + 1 });
				visit[n][m][VERTICAL] = true;
			}
		}
	}

	cout << '0';
	return 0;
}