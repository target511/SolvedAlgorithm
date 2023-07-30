#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<vector<int>> students;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> K;

	students = vector<vector<int>>(7, vector<int>(2, 0));
	int S, Y;

	for (int n = 0; n < N; n++) {
		cin >> S >> Y;
		students[Y][S]++;
	}

	int result = 0;
	for (int y = 1; y <= 6; y++) {
		for (int s = 0; s <= 1; s++) {
			if (students[y][s] / K > 0) {
				result += students[y][s] / K;
				students[y][s] %= K;
			}

			if (students[y][s] % K > 0)
				result++;
		}
	}

	cout << result;

	return 0;
}