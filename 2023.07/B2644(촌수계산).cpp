#include <iostream>
#include <vector>
using namespace std;

int N, K1, K2, M;
vector<vector<int>> nodes;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> K1 >> K2 >> M;
	nodes = vector<vector<int>>(N + 1, vector<int>(2, 0));
	int tmp1, tmp2;
	for (int m = 0; m < M; m++) {
		cin >> tmp1 >> tmp2;
		nodes[tmp1][1] = tmp2;
		nodes[tmp2][0] = tmp1;
	}

	vector<int> parents1, parents2;
	parents1.push_back(K1);
	parents2.push_back(K2);
	while (nodes[K1][0] > 0) {
		parents1.push_back(nodes[K1][0]);
		K1 = nodes[K1][0];
	}
	while (nodes[K2][0] > 0) {
		parents2.push_back(nodes[K2][0]);
		K2 = nodes[K2][0];
	}

	int result = -1;
	for (int i = 0; i < parents1.size(); i++) {
		for (int j = 0; j < parents2.size(); j++) {
			if (parents1[i] == parents2[j]) {
				result = i + j;
				i = parents1.size();
				break;
			}
		}
	}

	cout << result;

	return 0;
}

