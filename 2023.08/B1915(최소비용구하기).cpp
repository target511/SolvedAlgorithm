#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> nodes;
vector<int> d;

int startNode, endNode;
const int INF = INT32_MAX;

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;

	// priority_queue �� ���������� ������������ ���ĵȴ�.
	// ������ �ּҰ��� �켱������ pop�ϱ� ���� ���� ���·� push�ϰ�
	// ���� �� �ٽ� ����� ��ȯ�Ѵ�.
	while (!pq.empty()) {
		int weight = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (d[node] < weight)
			continue;

		for (int i = 0; i < nodes[node].size(); i++) {
			int next = nodes[node][i].first;
			int totalWeight = nodes[node][i].second + weight;

			if (totalWeight < d[next]) {
				d[next] = totalWeight;
				pq.push({ -totalWeight, next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	nodes = vector<vector<pair<int, int>>>(N + 1);
	d = vector<int>(N + 1, INF);

	int start, end, weight;
	for (int m = 0; m < M; m++) {
		cin >> start >> end >> weight;
		nodes[start].push_back({ end, weight });
	}
	cin >> startNode >> endNode;
	dijkstra(startNode);

	cout << d[endNode];

	return 0;
}