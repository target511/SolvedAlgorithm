#include <iostream>
#include <vector>
using namespace std;

int result(int n) {
	switch (n % 5) {
	case 0:
		if (n == 0) return -1;
		return n / 5;
	case 1:
		if (n < 5) return -1;
		return n / 5 - 1 + 2;
	case 2:
		if (n < 10) return -1;
		return n / 5 - 2 + 4;
	case 3:
		return n / 5 + 1;
	case 4:
		if (n < 5) return -1;
		return n / 5 - 1 + 3;
	}
}

int main() {
	int N;
	cin >> N;
	
	cout << result(N);

	return 0;
}