#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;
vector<bool> visit;
vector<int> result;

void permutation(int m) {
	if (m == 0) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int n = 0; n < N; n++) {
		if (visit[n])
			continue;

		visit[n] = true;
		result.push_back(nums[n]);
		permutation(m - 1);
		result.pop_back();
		visit[n] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	nums = vector<int>(N);
	visit = vector<bool>(N);
	for (int n = 0; n < N; n++) {
		cin >> nums[n];
	}
	sort(nums.begin(), nums.end());

	permutation(M);

	return 0;
}