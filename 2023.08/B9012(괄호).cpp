#include <iostream>
#include <stack>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		stack<char> stk;
		string str;
		cin >> str;

		bool result = true;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') {
				stk.push('(');
			}
			else {
				if (stk.empty() || stk.top() != '(') {
					result = false;
					break;
				}
				else {
					stk.pop();
				}
			}
		}

		if (!stk.empty())
			result = false;

		if (result)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	

	return 0;
}