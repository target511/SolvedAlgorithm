#include <iostream>
#include <vector>
using namespace std;

int L, N;
vector<int> cake;
vector<int> eat;
int maxCallIndex = 0, maxCall = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> L >> N;
	cake = vector<int>(L + 1);
	eat = vector<int>(N + 1);

	int tmp1, tmp2, length, cut;
	for (int n = 1; n <= N; n++) {
		cin >> tmp1 >> tmp2;
		length = tmp2 - tmp1 + 1;
		if (maxCall < length) {
			maxCall = length;
			maxCallIndex = n;
		}

		cut = 0;
		for (int i = tmp1; i <= tmp2; i++) {
			if (cake[i] != 0) {
				cut++;
				continue;
			}

			cake[i] = n;
			eat[n]++;
		}
	}

	int winner = 0, winnerIndex = 0;
	for (int n = 1; n <= N; n++) {
		if (eat[n] > winner) {
			winner = eat[n];
			winnerIndex = n;
		}
	}

	cout << maxCallIndex << '\n' << winnerIndex;

	return 0;
}