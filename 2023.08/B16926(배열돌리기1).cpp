#include <iostream>
#include <vector>
using namespace std;

int N, M, R;
vector<vector<int>> map;
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int direction[4] = { 2, 0, 3, 1 };

void rotate(int i) {
	if (i >= N / 2 || i >= M / 2)
		return;

	int d = 0;
	int n = i, m = i;
	int dn, dm;
	int tmp = map[n][m];
	while (true) {
		dn = n + delta[d][0];
		dm = m + delta[d][1];

		if (dn < i || dm < i || dn >= N - i || dm >= M - i) {
			d = direction[d];
			dn = n + delta[d][0];
			dm = m + delta[d][1];
		}
		
		if (dn == i && dm == i) {
			map[n][m] = tmp;
			break;
		}

		map[n][m] = map[dn][dm];
		n = dn;
		m = dm;
	}
	
	rotate(i + 1);
}

void printMap() {
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cout << map[n][m] << ' ';
		}
		cout << '\n';
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> R;
	map = vector<vector<int>>(N, vector<int>(M));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> map[n][m];
		}
	}
	
	for (int r = 0; r < R; r++) {
		rotate(0);
	}
	printMap();

	return 0;
}