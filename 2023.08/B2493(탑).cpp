#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	stack<pair<int, int>> stk;
	vector<int> result = vector<int>(N + 1);

	int tmp;
	cin >> tmp;
	result[1] = 0;
	stk.push({ 0, 100000001 });
	stk.push({ 1, tmp });
	for (int n = 2; n <= N; n++) {
		cin >> tmp;
		if (tmp >= stk.top().second) {
			while (stk.top().second <= tmp) {
				stk.pop();
			}
		}
		result[n] = stk.top().first;
		stk.push({ n, tmp });
	}

	for (int n = 1; n <= N; n++) {
		cout << result[n] << ' ';
	}

	return 0;
}