#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> map;
pair<int, int> pos = make_pair(0, 0);
int look;
int directions[4] = {3, 0, 1, 2};
int delta[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

bool isBackWall() {
	int i = pos.first;
	int j = pos.second;
	int back = directions[look];
	int di = i + delta[back][0];
	int dj = j + delta[back][1];

	if (di < 0 || dj < 0 || di >= N || dj >= M || map[di][dj] == 1)
		return true;

	return false;
}

bool areRoomsClean() {
	int i = pos.first;
	int j = pos.second;
	for (int d = 0; d < 4; d++) {
		int di = i + delta[d][0];
		int dj = j + delta[d][1];

		if (di < 0 || dj < 0 || di >= N || dj >= M)
			continue;

		if (map[di][dj] == 0)
			return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M >> pos.first >> pos.second >> look;
	map = vector<vector<int>>(N, vector<int>(M, 0));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> map[n][m];
		}
	}

	int cnt = 0;
	while (true) {
		// 1. ���� ĭ�� ���� û�ҵ��� ���� ���, ���� ĭ�� û���Ѵ�.
		if (map[pos.first][pos.second] == 0) {
			map[pos.first][pos.second] = 2;
			cnt++;
		}

		// 2. ���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� ���� ���
		if (areRoomsClean()) {
			// 2-1 �ٶ󺸴� ������ ������ ä�� ��ĭ ������ �� �ִٸ� ��ĭ �����ϰ� 1������ ���ư���.
			if (!isBackWall()) {
				int back = directions[look];
				int di = pos.first + delta[back][0];
				int dj = pos.second + delta[back][1];
				pos.first = di;
				pos.second = dj;

				continue;
			}
			// 2-2 ���̶� ������ �� ���ٸ� �۵��� �����.
			else {
				break;
			}
		}
		// 3. û�ҵ��� ���� �� ĭ�� �ִ� ���
		else {
			// 3-1. �ݽð� �������� 90�� ȸ���Ѵ�.
			// 3-2. ���� ĭ�� û�ҵ��� ���� �� ĭ�� ��� �� ĭ �����Ѵ�.
			int di = pos.first + delta[look][0];
			int dj = pos.second + delta[look][1];
			look = directions[look];

			if (di < 0 || dj < 0 || di >= N || dj >= M)
				continue;

			if (map[di][dj] == 0) {
				pos.first = di;
				pos.second = dj;
			}
		}
	}
	cout << cnt;
	return 0;
}