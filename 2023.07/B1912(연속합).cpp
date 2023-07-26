#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> nums;
vector<int> memo;

int dp(int index) {
	if (index == N - 1) {
		memo[index] = nums[index];
		return memo[index];
	}

	if (memo[index] != 0) {
		return memo[index];
	}

	memo[index] = nums[index] + dp(index + 1) > nums[index] ? nums[index] + dp(index + 1) : nums[index];
	return memo[index];
}

int main() {
	cin >> N;

	int temp;
	for (int n = 0; n < N; n++) {
		cin >> temp;
		nums.push_back(temp);
	}
	memo = vector<int>(N, 0);
	dp(0);
	int result = -1001;
	for (int n = 0; n < N; n++) {
		if (result < memo[n])
			result = memo[n];
	}

	cout << result;

	return 0;
}