#include <iostream>
#include <vector>
using namespace std;

int N, K;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	vector<int> nums;
	vector<int> result;
	for (int n = 1; n <= N; n++) {
		nums.push_back(n);
	}
	
	int removeIndex = K - 1;
	while (nums.size() > 1) {
		result.push_back(nums[removeIndex]);
		nums.erase(nums.begin() + removeIndex);
		removeIndex = (removeIndex + K - 1) % nums.size();
	}

	cout << '<';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ", ";
	}
	cout << nums[0] << '>';
	return 0;
}