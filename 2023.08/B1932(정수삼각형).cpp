#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> values;
vector<vector<int>> memo;

int dp(int n, int m) {
	if (n == 1) {
		return values[1][1];
	}
	
	if (memo[n][m] != -1) {
		return memo[n][m];
	}

	if (m == 1) { // 가장 왼쪽 라인
		memo[n][m] = dp(n - 1, m) + values[n][m];
	}
	else if (m == n) { // 가장 오른쪽 라인
		memo[n][m] = dp(n - 1, m - 1) + values[n][m];
	}
	else {
		memo[n][m] = max(dp(n - 1, m - 1), dp(n - 1, m)) + values[n][m];
	}

	return memo[n][m];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	values = vector<vector<int>>(N + 1, vector<int>(N + 1));
	memo = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= n; m++) {
			cin >> values[n][m];
		}
	}

	int result = 0, temp = 0;
	for (int m = 1; m <= N; m++) {
		temp = dp(N, m);
		result = temp > result ? temp : result;
	}

	cout << result;

	return 0;
}