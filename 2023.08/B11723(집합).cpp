#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int M;
	cin >> M;
	set<int> s;
	set<int> allSet = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

	string tmp;
	int num;
	for (int m = 0; m < M; m++) {
		cin >> tmp;

		switch (tmp[1]) {
		case 'd': // add
			cin >> num;
			s.insert(num);
			break;
		case 'e': // remove
			cin >> num;
			s.erase(num);
			break;
		case 'h': // check
			cin >> num;
			if (s.find(num) == s.end())
				cout << '0';
			else
				cout << '1';

			cout << '\n';
			break;
		case 'o': // toggle
			cin >> num;
			if (s.find(num) == s.end())
				s.insert(num);
			else
				s.erase(num);
			break;
		case 'l': // all
			s = allSet;
			break;
		case 'm': // empty
			s.clear();
			break;
		}
	}

	return 0;
}