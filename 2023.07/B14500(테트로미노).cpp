#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<int>> v;
vector<vector<int>> delta;

void rotate() {
	v = vector<vector<int>>(M, vector<int>(N, 0));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			v[i][j] = board[N - 1 - j][i];
		}
	}

	int tmp = N;
	N = M;
	M = tmp;

	board = v;
}

int tetrominoTotal(int n, int m) {
	int total = 0;
	for (int d = 0; d < 4; d++) {
		int dn = n + delta[d][0];
		int dm = m + delta[d][1];

		if (dn < 0 || dm < 0 || dn >= N || dm >= M)
			return 0;

		total += board[dn][dm];
	}

	return total;
}

int coveredTotal(int n, int m) {
	int maximumTotal = 0;
	int tmp;
	// type I
	delta = { {0, 0}, {0, 1}, {0, 2}, {0, 3} };
	tmp = tetrominoTotal(n, m);
	maximumTotal = maximumTotal > tmp ? maximumTotal : tmp;

	// type O
	delta = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
	tmp = tetrominoTotal(n, m);
	maximumTotal = maximumTotal > tmp ? maximumTotal : tmp;

	// type L
	delta = { {0, 0}, {1, 0}, {2, 0}, {2, 1} };
	tmp = tetrominoTotal(n, m);
	maximumTotal = maximumTotal > tmp ? maximumTotal : tmp;

	// type J
	delta = { {0, 0}, {1, 0}, {2, 0}, {2, -1} };
	tmp = tetrominoTotal(n, m);
	maximumTotal = maximumTotal > tmp ? maximumTotal : tmp;

	// type S
	delta = { {0, 0}, {1, 0}, {1, 1}, {2, 1} };
	tmp = tetrominoTotal(n, m);
	maximumTotal = maximumTotal > tmp ? maximumTotal : tmp;

	// type Z
	delta = { {0, 0}, {1, 0}, {1, -1}, {2, -1} };
	tmp = tetrominoTotal(n, m);
	maximumTotal = maximumTotal > tmp ? maximumTotal : tmp;

	// type T
	delta = { {0, 0}, {0, 1}, {0, 2}, {1, 1} };
	tmp = tetrominoTotal(n, m);
	maximumTotal = maximumTotal > tmp ? maximumTotal : tmp;

	return maximumTotal;
}

int main() {
	cin >> N >> M;
	board = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int result = 0;
	int tmp;
	for (int r = 0; r < 4; r++) {
		rotate();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmp = coveredTotal(i, j);
				result = result > tmp ? result : tmp;
			}
		}
	}

	cout << result;

	return 0;
}