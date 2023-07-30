#include <iostream>
#include <vector>
using namespace std;

vector<bool> visit = vector<bool>(42);

int main() {
	int num;
	for (int n = 0; n < 10; n++) {
		cin >> num;

		visit[num % 42] = true;
	}

	int cnt = 0;
	for (int i = 0; i < 42; i++) {
		if (visit[i])
			cnt++;
	}

	cout << cnt;
	return 0;
}