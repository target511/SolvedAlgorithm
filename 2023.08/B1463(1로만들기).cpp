#include <iostream>
#include <vector>
using namespace std;

int N;
int memo[1000001];
int INF;

int min(int a, int b, int c) {
	int result = a < b ? a : b;
	return result < c ? result : c;
}

int main() {
	cin >> N;
	//memo = vector<int>(N + 1); // Stack Overflow 날 가능성 // 1 <= N <= 10^6
	INF = N + 1;

	int a, b, c;
	memo[1] = 0; // 1은 연산 필요 없으니 0....
	memo[2] = 1;
	memo[3] = 1;
	for (int i = 4; i <= N; i++) {
		if (i % 3 > 0)
			a = INF;
		else
			a = memo[i / 3];

		if (i % 2 > 0)
			b = INF;
		else
			b = memo[i / 2];

		c = memo[i - 1];

		memo[i] = min(a, b, c) + 1;
	}

	cout << memo[N];

	return 0;
}