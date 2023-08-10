#include <iostream>
#include <vector>
using namespace std;

long long func(long long num) {
	long long cnt = 1;
	long long result = 0;
	while (num > 0) {
		if (num % 10 > 4)
			result += (num % 10 - 1) * cnt;
		else
			result += (num % 10) * cnt;

		num /= 10;
		cnt *= 9;
	}

	return result;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		long long A, B;
		cin >> A >> B;

		long long result = 0;
		if (A < 0) {
			A = -A;
			result += func(A);
			if (B < 0) {
				B = -B;
				result -= func(B);
			}
			else {
				result += func(B);
				result--;
			}
		}
		else {
			result += func(B);
			result -= func(A);
		}

		cout << '#' << t << ' ' << result << '\n';
	}

	return 0;
}