#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
vector<int> nums;
vector<bool> visit;
vector<string> result;

void permutation(int length, string str) {
	if (length == 0) {
		result.push_back(str);
		return;
	}

	for (int n = 0; n < N; n++) {
		if (visit[n])
			continue;

		if (n - 1 >= 0 && !visit[n - 1] && nums[n - 1] == nums[n])
			continue;

		visit[n] = true;
		string tmp = str;
		tmp += to_string(nums[n]);
		permutation(length - 1, tmp + " ");
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
	permutation(M, "");
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	return 0;
}