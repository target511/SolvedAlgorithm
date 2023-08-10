#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> memo;

int dp(int n) {
	if (n % 2 == 1)
		return 0;

	if (n == 0)
		return 1;
	if (n == 2)
		return 3;

	if (memo[n] > 0)
		return memo[n];

	memo[n] = 3 * dp(n - 2);
	for (int i = 4; n - i >= 0; i += 2) {
		memo[n] += 2 * dp(n - i);
	}
	return memo[n];
}
int main() {
	cin >> N;
	memo = vector<int>(N + 1);

	cout << dp(N);

	return 0;
}