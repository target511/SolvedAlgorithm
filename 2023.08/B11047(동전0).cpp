#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> coins(N);
	for (int n = N - 1; n >= 0; n--) {
		cin >> coins[n];
	}

	int result = 0;
	for (int n = 0; n < N; n++) {
		result += K / coins[n];
		K %= coins[n];
	}

	cout << result;

	return 0;
}