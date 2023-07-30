#include <iostream>
#include <vector>
using namespace std;

vector<int> map = vector<int>(1001);
int N;
int maxIndex, maxHeight = 0;
int result = 0;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	int tmp1, tmp2;
	for (int n = 0; n < N; n++) {
		cin >> tmp1 >> tmp2;
		map[tmp1] = tmp2;
		if (maxHeight < tmp2) {
			maxHeight = tmp2;
			maxIndex = tmp1;
		}
	}

	int currentHeight = 0;
	for (int i = 0; i <= maxIndex; i++) {
		if (currentHeight < map[i]) {
			currentHeight = map[i];
		}

		result += currentHeight;
	}

	currentHeight = 0;
	for (int i = 1000; i > maxIndex; i--) {
		if (currentHeight < map[i]) {
			currentHeight = map[i];
		}

		result += currentHeight;
	}

	cout << result;

	return 0;
}