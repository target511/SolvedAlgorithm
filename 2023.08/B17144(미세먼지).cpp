#include <iostream>
#include <vector>
using namespace std;

int N, M, T;
vector<vector<int>> map;
int filter1, filter2;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int directionUpper[4] = { 2, 0, 3, 1 };
int directionLower[4] = { 1, 3, 0, 2 };

void spread() {
	vector<vector<int>> sp = vector<vector<int>>(N, vector<int>(M));

	int dn, dm;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			for (int d = 0; d < 4; d++) {
				dn = n + delta[d][0];
				dm = m + delta[d][1];

				if (dn < 0 || dm < 0 || dn >= N || dm >= M ||
					map[dn][dm] == -1)
					continue;

				sp[dn][dm] += map[n][m] / 5;
				sp[n][m] -= map[n][m] / 5;
			}
		}
	}

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			map[n][m] += sp[n][m];
		}
	}
}

void filteringUpper() {
	int n = filter1;
	int m = 0;
	int d = 0;
	int dn, dm;
	while (true) {
		dn = n + delta[d][0];
		dm = m + delta[d][1];

		if (dn < 0 || dm < 0 || dn > filter1 || dm >= M) {
			d = directionUpper[d];
			dn = n + delta[d][0];
			dm = m + delta[d][1];
		}

		map[n][m] = map[dn][dm];
		if (n == filter1 && m == 0)
			map[n][m] = -1;
		else if (dn == filter1 && m == 1) {
			map[dn][dm] = -1;
			map[n][m] = 0;
			break;
		}

		n = dn;
		m = dm;
	}
}

void filteringLower() {
	int n = filter2;
	int m = 0;
	int d = 3;
	int dn, dm;
	while (true) {
		dn = n + delta[d][0];
		dm = m + delta[d][1];

		if (dn < filter2 || dm < 0 || dn >= N || dm >= M) {
			d = directionLower[d];
			dn = n + delta[d][0];
			dm = m + delta[d][1];
		}

		map[n][m] = map[dn][dm];
		if (n == filter2 && m == 0)
			map[n][m] = -1;
		else if (dn == filter2 && m == 1) {
			map[dn][dm] = -1;
			map[n][m] = 0;
			break;
		}

		n = dn;
		m = dm;
	}
}

int countDirts() {
	int count = 0;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (map[n][m] > 0) {
				count += map[n][m];
			}
		}
	}

	return count;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> T;
	map = vector<vector<int>>(N, vector<int>(M));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> map[n][m];
			if (map[n][m] == -1) {
				filter2 = n;
			}
		}
	}
	filter1 = filter2 - 1;

	for (int t = 0; t < T; t++) {
		spread();
		filteringUpper();
		filteringLower();
	}

	cout << countDirts();
	
	return 0;
}