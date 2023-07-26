#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<bool>> board;

int main() {
	cin >> N;
	board = vector<vector<bool>>(100, vector<bool>(100, false));
	int tmp1, tmp2;
	for (int n = 0; n < N; n++) {
		cin >> tmp1 >> tmp2;

		for (int t1 = tmp1; t1 < tmp1 + 10; t1++) {
			for (int t2 = tmp2; t2 < tmp2 + 10; t2++) {
				board[t1][t2] = true;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j])
				result++;
		}
	}

	cout << result;

	return 0;
}