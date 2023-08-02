#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> nums;
vector<bool> visit;
vector<int> cycleNodes;
bool dfs(int n, int target) {
	if (target == -1)
		target = n;

	if (visit[n]) {
		if (target == n) {
			cycleNodes.push_back(n);
			return true;
		}
		else {
			return false;
		}
	}

	visit[n] = true;
	int next = nums[n];
	return dfs(next, target);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	nums = vector<int>(N + 1);
	visit = vector<bool>(N + 1);
	for (int n = 1; n <= N; n++) {
		cin >> nums[n];
	}

	for (int n = 1; n <= N; n++) {
		visit = vector<bool >(N + 1);
		dfs(n, -1);
	}

	sort(cycleNodes.begin(), cycleNodes.end());
	cout << cycleNodes.size() << '\n';
	for (int i = 0; i < cycleNodes.size(); i++) {
		cout << cycleNodes[i] << '\n';
	}
	return 0;
}