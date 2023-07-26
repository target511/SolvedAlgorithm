#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<vector<int>> apartment;
vector<vector<int>> memo;
int dp(int k, int n) {
	if (k == 0)
		return n;

	if (memo[k][n] != 0) {
		return memo[k][n];
	}

	for (int i = 1; i <= n; i++) {
		memo[k][n] += dp(k - 1, i);
	}

	return memo[k][n];
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> K >> N;
		apartment = vector<vector<int>>(K + 1, vector<int>(N + 1, 0));
		memo = vector<vector<int>>(K + 1, vector<int>(N + 1, 0));

		cout << dp(K, N) << '\n';
	}

	return 0;
}