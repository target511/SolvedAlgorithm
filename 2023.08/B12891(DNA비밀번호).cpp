#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int S, P;
	string password;
	vector<int> ACGT(20);
	int A, C, G, T;

	cin >> S >> P;
	cin >> password;
	cin >> A >> C >> G >> T;

	for (int p = 0; p < P - 1; p++) {
		ACGT[password[p] - 'A']++;
	}

	int result = 0;
	int left = 0;
	int right = P - 1;
	do {
		ACGT[password[right++] - 'A']++;

		if (ACGT['A' - 'A'] >= A && ACGT['C' - 'A'] >= C &&
			ACGT['G' - 'A'] >= G && ACGT['T' - 'A'] >= T) {
			result++;
		}
			
		ACGT[password[left++] - 'A']--;
	} while (right < S);

	cout << result;
	return 0;
 }