#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
vector<int> nums;
vector<bool> visit;

void permutation(int depth, int iter, string str) {
	if (depth == 0) {
		cout << str << '\n';
		return;
	}

	for (int n = iter; n < N; n++) {
		if (visit[n])
			continue;

		visit[n] = true;
		permutation(depth - 1, n + 1, str + to_string(nums[n]) + " ");
		visit[n] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true) {
		cin >> N;
		if (N == 0) {
			return 0;
		}

		nums = vector<int>(N);
		visit = vector<bool>(N);
		for (int n = 0; n < N; n++) {
			cin >> nums[n];
		}
		sort(nums.begin(), nums.end());
		permutation(6, 0, "");

		cout << '\n';
	} // End - while

	return 0;
}