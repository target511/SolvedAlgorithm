#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> map;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

bool isAllMelted() {
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (map[i][j] > 0)
				return false;
		}
	}

	return true;
}

void melt() {
	vector<vector<int>> surrounded = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (map[i][j] <= 0)
				continue;

			int count = 0;
			for (int d = 0; d < 4; d++) {
				int di = i + delta[d][0];
				int dj = j + delta[d][1];

				if (di < 0 || dj < 0 || di >= N || dj >= M)
					continue;

				if (map[di][dj] <= 0) { // ¹Ù´Ù
					count++;
				}
			}
			surrounded[i][j] = count;
		}
	}

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			map[i][j] -= surrounded[i][j];
		}
	}
}

int unionFind() {
	vector<vector<bool>> visit = vector<vector<bool>>(N, vector<bool>(M, false));
	queue<pair<int, int>> que;
	vector<int> counts;

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (map[i][j] <= 0 || visit[i][j])
				continue;

			int count = 0;
			que.push(make_pair(i, j));
			while (!que.empty()) {
				int n = que.front().first;
				int m = que.front().second;
				que.pop();
				count++;

				for (int d = 0; d < 4; d++) {
					int di = n + delta[d][0];
					int dj = m + delta[d][1];

					if (di < 0 || dj < 0 || di >= N || dj >= M)
						continue;

					if (map[di][dj] > 0 && !visit[di][dj]) {
						visit[di][dj] = true;
						que.push(make_pair(di, dj));
					}
				}
			}
			if (count > 0)
				counts.push_back(count);
		}
	}

	return counts.size();
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	map = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int count = 0;
	while (!isAllMelted()) {
		if (unionFind() > 1)
			break;

		melt();
		count++;
	}

	if (unionFind() < 2)
		count = 0;

	cout << count;

	return 0;
}