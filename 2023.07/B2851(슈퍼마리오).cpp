#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> mushrooms = vector<int>(10);
int total = 0;

int main() {
	for (int n = 0; n < 10; n++) {
		cin >> mushrooms[n];
		total += mushrooms[n];
	}

	vector<int> diffs = vector<int>(10);
	int sum = 0;
	int minimumDiff = 101;
	int result = 0;
	for (int n = 0; n < 10; n++) {
		sum += mushrooms[n];
		
		if (abs(sum - 100) < minimumDiff) {
			minimumDiff = abs(sum - 100);
			result = sum;
		}
		else if (abs(sum - 100) == minimumDiff) {
			if (result < sum)
				result = sum;
		}
	}

	cout << result;

	return 0;
}