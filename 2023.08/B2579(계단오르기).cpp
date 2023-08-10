#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> scores;
vector<vector<int>> memo;
int result = 0;

int max(int a, int b) {
	return (a > b ? a : b);
}

int dp(int index, int stepOrNot) {
	if (index == 0) {
		result = scores[0] > result ? scores[0] : result;
		return scores[0];
	}
	if (index == 1) {
		if (stepOrNot == 0) {
			result = scores[1] > result ? scores[1] : result;
			return scores[1];
		}
		else {
			result = scores[0] + scores[1] > result ? scores[0] + scores[1] : result;
			return scores[0] + scores[1];
		}
	}

	if (memo[index][stepOrNot] > 0)
		return memo[index][stepOrNot];

	if (stepOrNot == 0) {
		memo[index][0] = max(dp(index - 2, 0), dp(index - 2, 1)) + scores[index];
		result = memo[index][0] > result ? memo[index][0] : result;
	}
	else {
		memo[index][1] = dp(index - 1, 0) + scores[index];
		result = memo[index][1] > result ? memo[index][1] : result;
	}

	return memo[index][stepOrNot];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	scores = vector<int>(N);
	memo = vector<vector<int>>(N, vector<int>(2));

	for (int n = 0; n < N; n++) {
		cin >> scores[n];
	}

	N--;
	dp(N, 0);
	dp(N, 1);

	cout << result;

	return 0;
}