#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long A, B;

int main() {
	cin >> A >> B;
	int result = -1;
	if (A > B) {
		cout << "-1";
		return 0;
	}

	queue<pair<int, int>> que;
	que.push(make_pair(A, 1));

	long long num, next, count;
	while (!que.empty()) {
		num = que.front().first;
		count = que.front().second;
		que.pop();

		if (num == B) {
			result = count;
			break;
		}

		next = num * 10 + 1;
		if (next <= B) {
			que.push(make_pair(next, count + 1));
		}

		next = num * 2;
		if (next <= B) {
			que.push(make_pair(next, count + 1));
		}
	}

	cout << result;

	return 0;
}