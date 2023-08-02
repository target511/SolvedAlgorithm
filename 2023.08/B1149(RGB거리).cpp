#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> values;
vector<vector<int>> memo;
int otherColors[3][2] = { {1, 2}, {0, 2}, {0, 1} };

int dp(int index, int color) {
	if (index == 0) {
		return values[index][color];
	}

	if (memo[index][color] > 0) {
		return memo[index][color];
	}

	memo[index][color] = 
		min(dp(index - 1, otherColors[color][0]), dp(index - 1, otherColors[color][1]))
		+ values[index][color];

	return memo[index][color];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	values = vector<vector<int>>(N, vector<int>(3));
	memo = vector<vector<int>>(N, vector<int>(3));

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < 3; m++) {
			cin >> values[n][m];
		}
	}

	N--;
	int result = min(dp(N, 0), dp(N, 1));
	result = min(result, dp(N, 2));

	cout << result;

	return 0;
}