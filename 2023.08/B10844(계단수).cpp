#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<long long>> memo;

long long dp(int index, int num) {
	if (index == 1) {
		if (num == 0) 
			return 0;
		else 
			return 1;
	}

	if (memo[index][num] > 0)
		return memo[index][num];

	if (num == 0) {
		memo[index][num] = dp(index - 1, 1) % 1000000000;
	}
	else if (num == 9) {
		memo[index][num] = dp(index - 1, 8) % 1000000000;
	}
	else {
		memo[index][num] = ( dp(index - 1, num - 1) + dp(index - 1, num + 1) ) % 1000000000;
	}

	return memo[index][num];
}

int main() {
	cin >> N;
	memo = vector<vector<long long>>(N + 1, vector<long long>(10, 0));

	long long result = 0;
	for (int i = 0; i <= 9; i++) {
		result += dp(N, i);
	}

	cout << result % 1000000000;

	return 0;
}