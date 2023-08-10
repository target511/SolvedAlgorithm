#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;
vector<int> result;

void permutation(int m, int iter) {
	if (m == 0) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int n = iter; n < N; n++) {
		result.push_back(nums[n]);
		permutation(m - 1, n);
		result.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	nums = vector<int>(N);
	for (int n = 0; n < N; n++) {
		cin >> nums[n];
	}
	sort(nums.begin(), nums.end());

	permutation(M, 0);

	return 0;
}