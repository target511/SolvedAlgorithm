#include <iostream>
#include <algorithm>
using namespace std;

int N;
char values[100001][3];
int memo[100001][3];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;

	for (int n = 1; n <= N; n++) {
		for (int m = 0; m < 3; m++) {
			cin >> values[n][m];
			values[n][m] -= '0';
		}
	}

	for (int m = 0; m < 3; m++) {
		memo[1][m] = values[1][m];
	}

	for (int n = 2; n <= N; n++) {
		memo[n][0] = max(memo[n - 1][0], memo[n - 1][1]) + values[n][0];
		memo[n][1] = max(max(memo[n - 1][0], memo[n - 1][1]), memo[n - 1][2]) + values[n][1];
		memo[n][2] = max(memo[n - 1][1], memo[n - 1][2]) + values[n][2];
	}

	cout << max(max(memo[N][0], memo[N][1]), memo[N][2]);

	for (int n = 2; n <= N; n++) {
		memo[n][0] = min(memo[n - 1][0], memo[n - 1][1]) + values[n][0];
		memo[n][1] = min(min(memo[n - 1][0], memo[n - 1][1]), memo[n - 1][2]) + values[n][1];
		memo[n][2] = min(memo[n - 1][1], memo[n - 1][2]) + values[n][2];
	}
	cout << ' ' << min(min(memo[N][0], memo[N][1]), memo[N][2]);

	return 0;
}
//int min(int a, int b) {
//	return (a < b ? a : b);
//}
//
//int min(int a, int b, int c) {
//	int ret = (a < b ? a : b);
//	return ret < c ? ret : c;
//}
//
//int max(int a, int b) {
//	return (a > b ? a : b);
//}
//
//int max(int a, int b, int c) {
//	int ret = (a > b ? a : b);
//	return ret > c ? ret : c;
//}
