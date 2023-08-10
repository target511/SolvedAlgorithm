#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, N;
	string P;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> P >> N;
		string nums = "";
		cin >> nums;

		deque<string> deq;
		string str = "";
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == '[') {
				continue;
			}
			else if (nums[i] == ',' || nums[i] == ']') {
				if (str.empty()) {
					continue;
				}

				deq.push_back(str);
				str = "";
			}
			else {
				str += nums[i];
			}
		}

		bool front = true;
		bool success = true;
		for (char p : P) {
			if (p == 'R') {
				front = !front;
			}
			else {
				if (deq.empty()) {
					success = false;
					break;
				}

				if (front) {
					deq.pop_front();
				}
				else {
					deq.pop_back();
				}
			}
		}

		string result = "error";
		if (success) {
			result = "[";
			if (deq.empty()) {
				result += "]";
			}
			else {
				while (!deq.empty()) {
					if (front) {
						result += deq.front();
						deq.pop_front();
						result += ',';
					}
					else {
						result += deq.back();
						deq.pop_back();
						result += ',';
					}
				}

				result[result.size() - 1] = ']';
			}
		}

		cout << result << '\n';
	}

	return 0;
}