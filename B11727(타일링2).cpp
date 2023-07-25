#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> memo;

long dp(int k) {
	if (k == 1)
		return 1;
	else if (k == 2)
		return 3;

	if (memo[k] != 0)
		return memo[k];
	else {
		memo[k] = (dp(k - 1) + 2 * dp(k - 2)) % 10007;
		return memo[k];
	}
}

int main() {
	cin >> N;
	memo = vector<int>(N + 1, 0);

	cout << dp(N);

	return 0;
}