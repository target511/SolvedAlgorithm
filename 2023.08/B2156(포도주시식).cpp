#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> values;
vector<vector<int>> memo;

int max(int a, int b, int c) {
	int ret = a > b ? a : b;
	ret = ret > c ? ret : c;
	return ret;
}

int max(int a, int b) {
	return (a > b ? a : b);
}

int dp(int index, int chain) {
	if (index == 0) {
		if (chain == 0) {
			return values[0];
		}
		else if (chain == 1) {
			return values[0];
		}
		else if (chain == 2) {
			return 0;
		}
	}

	if (index == 1) {
		if (chain == 0) {
			return values[1];
		}
		else if (chain == 1) {
			return values[0] + values[1];
		}
		else if (chain == 2) {
			return values[0];
		}
	}

	if (index == 2) {
		if (chain == 0) {
			return values[0] + values[2];
		}
		else if (chain == 1) {
			return values[1] + values[2];
		}
		else if (chain == 2) {
			return values[0] + values[1];
		}
	}

	if (memo[index][chain] > -1) {
		return memo[index][chain];
	}

	if (chain == 0) {
		memo[index][chain] = max(dp(index - 2, 0), dp(index - 2, 1), dp(index - 2, 2)) + values[index];
	}
	else if (chain == 1) {
		memo[index][chain] = dp(index - 1, 0) + values[index];
	}
	else if (chain == 2) {
		memo[index][chain] = dp(index - 1, 1);
	}

	return memo[index][chain];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	values = vector<int>(N);
	memo = vector<vector<int>>(N, vector<int>(3, -1));

	for (int n = 0; n < N; n++) {
		cin >> values[n];
	}

	N--;
	cout << max(dp(N, 0), dp(N, 1), dp(N, 2));

	return 0;
}