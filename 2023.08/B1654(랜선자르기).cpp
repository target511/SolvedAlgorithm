#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> lines;

long long countLines(long long num) {
	long long ret = 0;
	for (int k = 0; k < K; k++) {
		ret += lines[k] / num;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> K >> N;
	lines = vector<int>(K + 1);

	int maxLength = 0;
	for (int k = 0; k < K; k++) {
		cin >> lines[k];
		maxLength = lines[k] > maxLength ? lines[k] : maxLength;
	}

	long long left = 1;
	long long right = maxLength;
	long long mid = (left + right) / 2;
	while (left <= right) {
		if (countLines(mid) < N) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}

		mid = (left + right) / 2;
	}

	cout << mid;

	return 0;
}