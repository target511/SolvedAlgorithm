#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, M, R;
vector<vector<int>> map;

vector<vector<int>> func1() {
	vector<vector<int>> copy = vector<vector<int>>(N, vector<int>(M));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			copy[n][m] = map[N - 1 - n][m];
		}
	}

	return copy;
}
vector<vector<int>> func2() {
	vector<vector<int>> copy = vector<vector<int>>(N, vector<int>(M));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			copy[n][m] = map[n][M - 1 - m];
		}
	}

	return copy;
}
vector<vector<int>> func3() {
	vector<vector<int>> copy = vector<vector<int>>(M, vector<int>(N));
	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			copy[m][n] = map[N - 1 - n][m];
		}
	}

	int tmp = N;
	N = M;
	M = tmp;
	return copy;
}

vector<vector<int>> func4() {
	vector<vector<int>> copy = vector<vector<int>>(M, vector<int>(N));
	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			copy[m][n] = map[n][M - 1 - m];
		}
	}

	int tmp = N;
	N = M;
	M = tmp;
	return copy;
}

vector<vector<int>> func5() {
	vector<vector<int>> copy = vector<vector<int>>(N, vector<int>(M));
	for (int n = 0; n < N / 2; n++) {
		for (int m = 0; m < M / 2; m++) {
			copy[n][m] = map[n + N / 2][m];
		}
	}

	for (int n = 0; n < N / 2; n++) {
		for (int m = M / 2; m < M; m++) {
			copy[n][m] = map[n][m - M / 2];
		}
	}

	for (int n = N / 2; n < N; n++) {
		for (int m = 0; m < M / 2; m++) {
			copy[n][m] = map[n][m + M / 2];
		}
	}

	for (int n = N / 2; n < N; n++) {
		for (int m = M / 2; m < M; m++) {
			copy[n][m] = map[n - N / 2][m];
		}
	}

	return copy;
}

vector<vector<int>> func6() {
	vector<vector<int>> copy = vector<vector<int>>(N, vector<int>(M));
	for (int n = 0; n < N / 2; n++) {
		for (int m = 0; m < M / 2; m++) {
			copy[n][m] = map[n][m + M / 2];
		}
	}

	for (int n = 0; n < N / 2; n++) {
		for (int m = M / 2; m < M; m++) {
			copy[n][m] = map[n + N / 2][m];
		}
	}

	for (int n = N / 2; n < N; n++) {
		for (int m = 0; m < M / 2; m++) {
			copy[n][m] = map[n - N / 2][m];
		}
	}

	for (int n = N / 2; n < N; n++) {
		for (int m = M / 2; m < M; m++) {
			copy[n][m] = map[n][m - M / 2];
		}
	}

	return copy;
}

void print() {
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

	vector<int> ops(7);
	bool flipped = false;
	int op = 0;
	for (int r = 0; r < R; r++) {
		cin >> op;
		switch (op) {
		case 1: 
			ops[1]++;
			flipped = !flipped;
			break;
		case 2:
			ops[1]++;
			flipped = !flipped;
			break;
		case 3:
			if (flipped)
				ops[4]++;
			else
				ops[3]++;
			break;
		case 4:
			if (flipped)
				ops[3]++;
			else
				ops[4]++;
			break;
		case 5:
			if (flipped)
				ops[6]++;
			else
				ops[5]++;
			break;
		case 6:
			if (flipped)
				ops[5]++;
			else
				ops[6]++;
			break;
		} // End - SwitchCase
	} // End For-loop (R)

	int flipVertical = ops[1] % 2;
	int flipHorizontal = ops[2] % 2;
	int rotate = (ops[3] - ops[4]) % 4;
	int rotateCube = (ops[5] - ops[6]) % 4;

	if (flipVertical > 0)
		map = func1();
	if (flipHorizontal > 0)
		map = func2();
	if (rotate > 0) {
		for (int r = 0; r < rotate; r++) {
			map = func3();
		}
	}
	else {
		for (int r = 0; r < -rotate; r++) {
			map = func4();
		}
	}
	if (rotateCube > 0) {
		for (int r = 0; r < rotateCube; r++) {
			map = func5();
		}
	}
	else {
		for (int r = 0; r < -rotateCube; r++) {
			map = func6();
		}
	}


	//switch (op) {
	//case 1: map = func1(); break;
	//case 2: map = func2(); break;
	//case 3: map = func3(); break;
	//case 4: map = func4(); break;
	//case 5: map = func5(); break;
	//case 6: map = func6(); break;
	//}
	

	print();
	return 0;
}