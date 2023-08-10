#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<bool>> map;

void compress(int i, int j, int size) {
	int compare = map[i][j];
	bool possible = true;
	for (int n = i; n < i + size; n++) {
		for (int m = j; m < j + size; m++) {
			if (map[n][m] != compare) {
				possible = false;
				cout << '(';
				compress(i, j, size / 2);
				compress(i, j + size / 2, size / 2);
				compress(i + size / 2, j, size / 2);
				compress(i + size / 2, j + size / 2, size / 2);
				cout << ')';
				n = i + size;
				break;
			}
		}
	}

	if (possible) {
		cout << compare;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	map = vector<vector<bool>>(N, vector<bool>(N));
	
	char tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp == '0')
				map[i][j] = false;
			else
				map[i][j] = true;
		}
	}
	compress(0, 0, N);
	return 0;
}