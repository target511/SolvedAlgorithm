#include <iostream>
#include <vector>
using namespace std;

int T, N;
vector<vector<int>> values;
vector<vector<int>> memo;

int max(int a, int b, int c) {
	int ret = a > b ? a : b;
	return ret > c ? ret : c;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		values = vector<vector<int>>(N, vector<int>(3));
		memo = vector<vector<int>>(N, vector<int>(3));

		for (int n = 0; n < N; n++) {
			cin >> values[n][1];
		}
		for (int n = 0; n < N; n++) {
			cin >> values[n][2];
		}

		memo[0][0] = 0;
		memo[0][1] = values[0][1];
		memo[0][2] = values[0][2];
		int n = 1;
		while (n < N) {
			memo[n][0] = max(memo[n - 1][0], memo[n - 1][1], memo[n - 1][2]);
			memo[n][1] = max(memo[n - 1][0], memo[n - 1][2]) + values[n][1];
			memo[n][2] = max(memo[n - 1][0], memo[n - 1][1]) + values[n][2];
			n++;
		}

		N--;
		cout << max(memo[N][0], memo[N][1], memo[N][2]) << '\n';
	} // End - TestCase

	return 0;
}