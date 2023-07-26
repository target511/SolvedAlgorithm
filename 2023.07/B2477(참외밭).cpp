#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> direction = vector<int>{ 0, 4, 3, 1, 2 };
vector<int> lengths = vector<int>(6, 0);
int main() {
	cin >> N;

	int tmp1, tmp2;
	int cornerIndex = 0;
	cin >> tmp1 >> lengths[0];
	for (int i = 1; i < 6; i++) {
		cin >> tmp2 >> lengths[i];
		if (tmp2 != direction[tmp1]) {
			cornerIndex = i;
		}
		tmp1 = tmp2;
	}

	int a = cornerIndex + 2 > 5 ? cornerIndex - 4 : cornerIndex + 2;
	int b = cornerIndex + 3 > 5 ? cornerIndex - 3 : cornerIndex + 3;
	int c = cornerIndex - 1 < 0 ? cornerIndex + 5 : cornerIndex - 1;
	int d = cornerIndex;
	int size = lengths[a] * lengths[b] - lengths[c] * lengths[d];

	cout << N * size;
	

	return 0;
}

// 좌회전 해야하는 값을 저장한 direction과 방향 값이 일치하지 않는다면
// cornerIndex에 코너 위치를 저장
// 코너 위치 기준으로 넓이 구한 후 결과값 도출