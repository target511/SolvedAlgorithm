#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<long long>> memo;

long long dp(int length, int num) {
	if (length == 1) {
		return 1;
	}

	if (memo[length][num] > 0) {
		return memo[length][num];
	}

	for (int i = 0; i <= num; i++) {
		memo[length][num] += dp(length - 1, i) % 10007;
	}

	return memo[length][num] % 10007;
}

int main() {
	cin >> N;
	memo = vector<vector<long long>>(N + 1, vector<long long>(10));

	int result = 0;
	for (int n = 0; n <= 9; n++) {
		result += dp(N, n);
	}

	cout << result % 10007;

	return 0;
}