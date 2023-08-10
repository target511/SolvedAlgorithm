#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	unordered_map<string, string> nameToNum;
	unordered_map<string, string> numToName;
	
	string input;
	for (int n = 1; n <= N; n++) {
		cin >> input;
		nameToNum.insert({ input, to_string(n) });
		numToName.insert({ to_string(n), input });
	}

	for (int m = 0; m < M; m++) {
		cin >> input;
		if (input[0] >= '0' && input[0] <= '9') {
			cout << numToName.find(input)->second << '\n';
		}
		else {
			cout << nameToNum.find(input)->second << '\n';
		}
	}

	return 0;
}