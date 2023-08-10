#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> delay;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	delay = vector<int>(N);
	for (int n = 0; n < N; n++) {
		cin >> delay[n];
	}
	sort(delay.begin(), delay.end());

	int result = 0;
	for (int n = 0; n < N; n++) {
		result += (N - n) * delay[n];
	}
	cout << result;
	return 0;
}