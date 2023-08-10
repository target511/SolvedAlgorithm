#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> gears = vector<vector<bool>>(4, vector<bool>(8));

void rotate(int gear, bool clockwise, int spread) { // spread : 0 - 왼쪽, 1 - 오른쪽, 2 - 양쪽
	bool left = false;
	bool right = false;
	if (gear > 0 && spread != 1) {
		if (gears[gear][6] != gears[gear - 1][2])
			left = true;
	}
	
	if (gear < 3 && spread != 0) {
		if (gears[gear][2] != gears[gear + 1][6])
			right = true;
	}

	if (clockwise) { // 시계
		bool tmp = gears[gear][7];
		for (int i = 7; i > 0; i--) {
			gears[gear][i] = gears[gear][i - 1];
		}
		gears[gear][0] = tmp;
	}
	else { // 반시계
		bool tmp = gears[gear][0];
		for (int i = 0; i < 7; i++) {
			gears[gear][i] = gears[gear][i + 1];
		}
		gears[gear][7] = tmp;
	}

	if (left)
		rotate(gear - 1, !clockwise, 0);
	if (right)
		rotate(gear + 1, !clockwise, 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string tmp;
	for (int g = 0; g < 4; g++) {
		cin >> tmp;
		for (int i = 0; i < 8; i++) {
			if (tmp[i] == '0')
				gears[g][i] = false;
			else
				gears[g][i] = true;
		}
	}

	int K;
	cin >> K;
	
	int gear, direction;
	bool clockwise;
	for (int k = 0; k < K; k++) {
		cin >> gear >> direction;
		gear--;
		clockwise = (direction == 1 ? true : false);
		rotate(gear, clockwise, 2);
	}

	int result = 0;
	for (int g = 0; g < 4; g++) {
		if (gears[g][0])
			result += (1 << g);
	}
	cout << result;
	return 0;
}