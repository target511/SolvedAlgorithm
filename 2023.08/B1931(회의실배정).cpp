#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	vector<pair<int, int>> infos;
	cin >> N;

	int start, end;
	for (int n = 0; n < N; n++) {
		cin >> start >> end;
		infos.push_back({ start, end });
	}


	sort(infos.rbegin(), infos.rend());
	start = infos[0].first;
	end = infos[0].second;
	int count = 1;
	for (int i = 1; i < N; i++) {
		if (infos[i].second > start) {
			continue;
		}

		start = infos[i].first;
		end = infos[i].second;
		count++;
	}

	cout << count;
	return 0;
}