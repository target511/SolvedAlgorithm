#include <iostream>
#include <vector>
using namespace std;

int T, N;
long long memo[101];

long long dp(int index) {
	if (memo[index] > 0) {
		return memo[index];
	}

	return memo[index] = dp(index - 1) + dp(index - 5);
}

int main() {
	memo[1] = 1;
	memo[2] = 1;
	memo[3] = 1;
	memo[4] = 2;
	memo[5] = 2;
	memo[6] = 3;
	memo[7] = 4;
	memo[8] = 5;
	memo[9] = 7;
	memo[10] = 9;

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		cout << dp(N) << '\n';
	}

	return 0;
}