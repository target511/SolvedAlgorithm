#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> memo;

// flag : 0 - 사자를 배치하지 않는 경우, 1 - 사자를 배치하는 경우
int dp(int index, int flag) {
	if (index == 0) {
		return 1;
	}

	if (memo[index][flag] > 0) {
		return memo[index][flag];
	}

	if (flag == 0) {
		memo[index][flag] = (dp(index - 1, 0) + 2 * dp(index - 1, 1)) % 9901;
	}
	else if (flag == 1) {
		memo[index][flag] = (dp(index - 1, 0) + dp(index - 1, 1)) % 9901;
	}

	return memo[index][flag];
}

int main() {
	cin >> N;
	memo = vector<vector<int>>(N, vector<int>(2));

	N--;
	cout << (dp(N, 0) + 2 * dp(N, 1)) % 9901;

	return 0;
}