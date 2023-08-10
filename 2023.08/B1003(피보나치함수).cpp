#include <iostream>
#include <vector>
using namespace std;

int T, N;
vector<vector<int>> memo;

pair<int, int> dp(int num) {
	if (num == 0) {
		return make_pair(1, 0);
	}
	else if (num == 1) {
		return make_pair(0, 1);
	}

	if (memo[num][0] > 0) {
		return make_pair(memo[num][0], memo[num][1]);
	}

	memo[num][0] = dp(num - 1).first + dp(num - 2).first;
	memo[num][1] = dp(num - 1).second + dp(num - 2).second;

	return make_pair(memo[num][0], memo[num][1]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	memo = vector<vector<int>>(41, vector<int>(2));
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		cout << dp(N).first << ' ' << dp(N).second << '\n';
	} // End - TestCase

	return 0;
}