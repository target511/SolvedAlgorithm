#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<bool>> map = vector<vector<bool>>(102, vector<bool>(102));
int delta[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	int tmp1, tmp2;
	for (int n = 0; n < N; n++) {
		cin >> tmp1 >> tmp2;
		for (int i = tmp1; i < tmp1 + 10; i++) {
			for (int j = tmp2; j < tmp2 + 10; j++) {
				map[i][j] = true;
			}
		}
	}

	int result = 0;
	int di, dj;
	for (int i = 0; i <= 101; i++) {
		for (int j = 0; j <= 101; j++) {
			if (map[i][j])
				continue;

			for (int d = 0; d < 4; d++) {
				di = i + delta[d][0];
				dj = j + delta[d][1];

				if (di < 0 || dj < 0 || di > 101 || dj > 101 ||
					!map[di][dj])
					continue;

				result++;
			}
		}
	}

	cout << result;

	return 0;
}