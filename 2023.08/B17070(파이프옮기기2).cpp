#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> map;
vector<vector<vector<long long>>> memo;

void init() {
	map = vector<vector<int>>(N + 1, vector<int>(N + 1));
	memo = vector<vector<vector<long long>>>(N + 1, 
			vector<vector<long long>>(N + 1, 
				vector<long long>(3, -1)));
	for (int i = 0; i <= N; i++) {
		memo[i][0][0] = memo[i][0][1] = memo[i][0][2] = 0;
	}
	for (int j = 0; j <= N; j++) {
		memo[0][j][0] = memo[0][j][1] = memo[0][j][2] = 0;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				memo[i][j][0] = memo[i][j][1] = memo[i][j][2] = 0;
			}
		}
	}
	memo[1][1][0] = memo[1][1][1] = memo[1][1][2] = 0;
	memo[1][2][0] = 1;
	memo[1][2][1] = memo[1][2][2] = 0;
}

// 0 가로, 1 세로, 2 대각선
long long dp(int n, int m, int type) {
	if (memo[n][m][type] > -1)
		return memo[n][m][type];

	if (map[n][m] == 1) {
		memo[n][m][type] = 0;
		return 0;
	}

	if (type == 0) {
		memo[n][m][type] = dp(n, m - 1, 0) + dp(n, m - 1, 2);
	}
	else if (type == 1) {
		memo[n][m][type] = dp(n - 1, m, 1) + dp(n - 1, m, 2);
	}
	else {
		if (map[n - 1][m] == 1 || map[n][m - 1] == 1) {
			memo[n][m][type] = 0;
		}
		else {
			memo[n][m][type] = dp(n - 1, m - 1, 0) + dp(n - 1, m - 1, 1) + dp(n - 1, m - 1, 2);
		}
	}

	return memo[n][m][type];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	init();

	long long result = dp(N, N, 0) + dp(N, N, 1) + dp(N, N, 2);
	if (result < 0)
		cout << '0';
	else
		cout << result;
	return 0;
}