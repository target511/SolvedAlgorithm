#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<char>> map;
vector<vector<vector<int>>> visit;
int startN, startM;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	map = vector<vector<char>>(N, vector<char>(M));
	visit = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(64)));

	string str;
	for (int n = 0; n < N; n++) {
		cin >> str;
		for (int m = 0; m < M; m++) {
			map[n][m] = str[m];
			if (map[n][m] == '0') {
				startN = n;
				startM = m;
				map[n][m] = '.';
			}
		}
	}

	queue<vector<int>> que;
	que.push({ startN, startM, 0, 0 });
	visit[startN][startM][0] = true;

	int n, m, dn, dm;
	int depth, key;
	while (!que.empty()) {
		n = que.front()[0];
		m = que.front()[1];
		depth = que.front()[2];
		key = que.front()[3];
		que.pop();

		if (map[n][m] == '1') {
			cout << depth;
			return 0;
		}

		for (int d = 0; d < 4; d++) {
			dn = n + delta[d][0];
			dm = m + delta[d][1];

			if (dn < 0 || dm < 0 || dn >= N || dm >= M ||
				visit[dn][dm][key] || map[dn][dm] == '#')
				continue;

			if (map[dn][dm] >= 'A' && map[dn][dm] <= 'F') { // ¹®
				int door = 1 << (map[dn][dm] - 'A');
				if ((key & door) == door) {
					que.push({ dn, dm, depth + 1, key });
					visit[dn][dm][key] = true;
				}
			}
			else if (map[dn][dm] >= 'a' && map[dn][dm] <= 'f') { // ¿­¼è
				visit[dn][dm][key] = true;
				int k = 1 << (map[dn][dm] - 'a');
				que.push({ dn, dm, depth + 1, key | k });
				visit[dn][dm][key | k] = true;
			}
			else { // ºóÄ­
				que.push({ dn, dm, depth + 1, key });
				visit[dn][dm][key] = true;
			}
		}
	}

	cout << "-1";

	return 0;
}