#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> nums;
vector<int> operators;

int calc() {
	int result = nums[0];
	for (int i = 0; i < operators.size(); i++) {
		switch (operators[i]) {
		case 0:	result += nums[i + 1]; break;
		case 1: result -= nums[i + 1]; break;
		case 2: result *= nums[i + 1]; break;
		case 3: result /= nums[i + 1]; break;
		}
	}

	return result;
}

int main() {
	cin >> N;
	nums = vector<int>(N, 0);
	for (int n = 0; n < N; n++) {
		cin >> nums[n];
	}

	for (int i = 0; i < 4; i++) {
		int tmp;
		cin >> tmp;
		for (int t = 0; t < tmp; t++) {
			operators.push_back(i);
		}
	}

	int minimum = 1000000001;
	int maximum = -10000000001;

	do {
		int tmp = calc();
		minimum = minimum > tmp ? tmp : minimum;
		maximum = maximum < tmp ? tmp : maximum;
	} while(next_permutation(operators.begin(), operators.end()));

	cout << maximum << '\n' << minimum << '\n';
	return 0;
}