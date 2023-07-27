#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int jh_n, jh_m;
vector<vector<char>> map;
vector<vector<int>> visit;
vector<vector<int>> fireVisit;
queue<pair<int, int>> que;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

void printMap(vector<vector<int>> v) {
	cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << v[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}
int main() {
	cin >> N >> M;
	map = vector<vector<char>>(N, vector<char>(M));
	visit = vector<vector<int>>(N, vector<int>(M));
	fireVisit = vector<vector<int>>(N, vector<int>(M));
	
	char tmp;
	scanf("%c", &tmp);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &tmp);
			map[i][j] = tmp;

			if (tmp == 'J') {
				map[i][j] = '.';
				jh_n = i;
				jh_m = j;
			}
			else if (tmp == 'F') {
				que.push(make_pair(i, j));
				fireVisit[i][j] = 1;
			}
		}
		scanf("%c", &tmp);
	}

	int n, m, dn, dm;
	while (!que.empty()) {
		n = que.front().first;
		m = que.front().second;
		que.pop();

		for (int d = 0; d < 4; d++) {
			dn = n + delta[d][0];
			dm = m + delta[d][1];

			if (dn < 0 || dm < 0 || dn >= N || dm >= M || 
				fireVisit[dn][dm] > 0)
				continue;

			if (map[dn][dm] == '.') {
				que.push(make_pair(dn, dm));
				fireVisit[dn][dm] = fireVisit[n][m] + 1;
			}
		}
	}
	
	que.push(make_pair(jh_n, jh_m));
	visit[jh_n][jh_m] = 1;
	while (!que.empty()) {
		n = que.front().first;
		m = que.front().second;
		que.pop();

		if (n == 0 || m == 0 || n == N - 1 || m == M - 1) {
			cout << visit[n][m];
			return 0;
		}

		for (int d = 0; d < 4; d++) {
			dn = n + delta[d][0];
			dm = m + delta[d][1];

			if (dn < 0 || dm < 0 || dn >= N || dm >= M || 
				visit[dn][dm] > 0 || (fireVisit[dn][dm] > 0 && fireVisit[dn][dm] <= visit[n][m] + 1))
				continue;

			if (map[dn][dm] == '.') {
				que.push(make_pair(dn, dm));
				visit[dn][dm] = visit[n][m] + 1;
			}
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}