#include <iostream>
#include <vector>
using namespace std;

int N, M, L;
vector<int> friends;
int main() {
	cin >> N >> M >> L;
	friends = vector<int>(N);

	int cnt = 0;
	int index = 0;
	friends[index]++;
	while (true) {
		if (friends[index] == M)
			break;

		if (friends[index] % 2 == 0) {
			index = (index + N - L) % N;
		}
		else {
			index = (index + L) % N;
		}
		friends[index]++;
		cnt++;
	}

	cout << cnt;
	return 0;
}