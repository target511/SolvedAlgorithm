#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

int T;

int D(int num) {
	return (num * 2) % 10000;
}

int S(int num) {
	if (num == 0)
		return 9999;
	else
		return num - 1;
}

int L(int num) {
	return (num % 1000) * 10 + (num / 1000);
}

int R(int num) {
	return (num % 10) * 1000 + (num / 10);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int A, B;
		cin >> A >> B;

		vector<bool> visit(10000);
		queue<pair<int, string>> que;
		que.push({ A, "" });
		int num, dnum;
		string str;
		
		while (!que.empty()) {
			num = que.front().first;
			str = que.front().second;
			que.pop();

			if (num == B) {
				cout << str << '\n';
				break;
			}

			dnum = D(num);
			if (!visit[dnum]) {
				visit[dnum] = true;
				que.push({ dnum, str + "D" });
			}
			dnum = S(num);
			if (!visit[dnum]) {
				visit[dnum] = true;
				que.push({ dnum, str + "S" });
			}
			dnum = L(num);
			if (!visit[dnum]) {
				visit[dnum] = true;
				que.push({ dnum, str + "L" });
			}
			dnum = R(num);
			if (!visit[dnum]) {
				visit[dnum] = true;
				que.push({ dnum, str + "R" });
			}
		}
	}
	return 0;
}