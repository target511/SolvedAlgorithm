#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

int N, K, L;
vector<vector<int>> map;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int directionL[4] = { 1, 3, 0, 2 };
int directionR[4] = { 2, 0, 3, 1 };
int timer = 0;
// 0 ºóÄ­ / 1 ¹ì / 2 »ç°ú

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	map = vector<vector<int>>(N + 1, vector<int>(N + 1));
	int tmp1, tmp2;
	for (int k = 0; k < K; k++) {
		cin >> tmp1 >> tmp2;
		map[tmp1][tmp2] = 2;
	}

	cin >> L;
	queue<pair<int, char>> que;
	for (int l = 0; l < L; l++) {
		int x;
		char c;
		cin >> x >> c;
		que.push({ x, c });
	}

	// Game Start
	deque<pair<int, int>> deq;
	int result = 0;

	deq.push_back({ 1, 1 });
	map[1][1] = 1;

	int X, x;
	char C, c;
	int d = 2;
	int n, m, dn, dm;

	while (true) {
		n = deq.front().first;
		m = deq.front().second;
		dn = n + delta[d][0];
		dm = m + delta[d][1];

		if (dn < 1 || dm < 1 || dn > N || dm > N ||
			map[dn][dm] == 1) {
			timer++;
			break;
		}

		if (map[dn][dm] == 2) { // »ç°ú ¸ÔÀº °æ¿ì
			deq.push_front({ dn, dm });
			map[dn][dm] = 1;
		}
		else {
			deq.push_front({ dn, dm });
			map[dn][dm] = 1;
			map[deq.back().first][deq.back().second] = 0;
			deq.pop_back();
		}

		timer++;

		if (!que.empty()) {
			x = que.front().first;
			if (x == timer) {
				c = que.front().second;
				que.pop();
				if (c == 'L')
					d = directionL[d];
				else
					d = directionR[d];
			}
		}
	}

	cout << timer;

	return 0;
}