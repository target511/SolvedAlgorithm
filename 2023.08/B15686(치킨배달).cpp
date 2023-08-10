#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, int>> chickens;
vector<bool> visit;
vector<pair<int, int>> houses;
int minDistance;
vector<pair<int, int>> selected;

void selectChickens(int count, int iter) {
	if (count == 0) {
		int result = 0;
		for (int i = 0; i < houses.size(); i++) {
			int distance = 2 * N;
			for (int j = 0; j < selected.size(); j++) {
				int d = abs(houses[i].first - selected[j].first)
					+ abs(houses[i].second - selected[j].second);
				if (d < distance) {
					distance = d;
				}
			}
			result += distance;
		}

		if (result < minDistance)
			minDistance = result;

		return;
	}

	for (int i = iter; i < chickens.size(); i++) {
		if (visit[i])
			continue;

		visit[i] = true;
		selected.push_back({ chickens[i].first, chickens[i].second });
		selectChickens(count - 1, i + 1);
		selected.pop_back();
		visit[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;

	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (input == 1)
				houses.push_back({ i, j });
			else if (input == 2)
				chickens.push_back({ i, j });
		}
	}

	visit = vector<bool>(chickens.size());
	minDistance = 2 * N * houses.size();
	selectChickens(M, 0);
	cout << minDistance;

	return 0;
}