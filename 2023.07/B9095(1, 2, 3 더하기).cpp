#include <iostream>
#include <vector>
using namespace std;

int T, N;
vector<int> memo;

int dp(int num) {
	if (num == 1)	return 1;
	if (num == 2)	return 2;
	if (num == 3)	return 4;

	if (memo[num] != 0) 
		return memo[num];

	memo[num] = dp(num - 1) + dp(num - 2) + dp(num - 3);
	return memo[num];
}

int main() {
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;
		memo.clear();
		memo = vector<int>(N + 1, 0);

		cout << dp(N) << '\n';
	}
	return 0;
}