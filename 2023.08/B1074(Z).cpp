#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int N, R, C;
int result = 0;

void Z(int n, int r, int c) {
	if (n < 1) {
		return;
	}

	int middle = pow(2, n - 1);
	if (r < middle && c < middle) { // �»��
		Z(n - 1, r, c);
	}
	else if (r < middle && c >= middle) { // ����
		result += pow(2, 2 * n - 2);
		c -= middle;
		Z(n - 1, r, c);
	}
	else if (r >= middle && c < middle) { // ���ϴ�
		result += 2 * pow(2, 2 * n - 2);
		r -= middle;
		Z(n - 1, r, c);
	}
	else { // ���ϴ�
		result += 3 * pow(2, 2 * n - 2);
		c -= middle;
		r -= middle;
		Z(n - 1, r, c);
	}
}


int main() {
	cin >> N >> R >> C;
	Z(N, R, C);
	cout << result;

	return 0;
}