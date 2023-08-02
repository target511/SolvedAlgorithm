#include <iostream>
#include <vector>
using namespace std;
struct Node {
	int num;
	vector<Node> sub;
	int parent;
};

int N;
vector<Node> nodes;
int rootIndex;
int deletedNodeIndex;
int cnt = 0;

void dfs(int nodeIndex) {
	if (nodes[nodeIndex].sub.size() == 0) {
		cnt++;
		return;
	}

	for (int i = 0; i < nodes[nodeIndex].sub.size(); i++) {
		dfs(nodes[nodeIndex].sub[i].num);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;

	nodes = vector<Node>(N);
	int tmp;
	for (int n = 0; n < N; n++) {
		cin >> tmp;
		if (tmp == -1) {
			rootIndex = n;
		}

		nodes[n].num = n;
		nodes[n].parent = tmp;

		if (tmp != -1)
			nodes[tmp].sub.push_back(nodes[n]);
	}

	cin >> deletedNodeIndex;
	if (deletedNodeIndex == rootIndex) {
		cout << '0';
		return 0;
	}

	int parentOfDeletedNode = nodes[deletedNodeIndex].parent;

	for (int i = 0; i < nodes[nodes[deletedNodeIndex].parent].sub.size(); i++) {
		if (nodes[parentOfDeletedNode].sub[i].num == deletedNodeIndex) {
			nodes[parentOfDeletedNode].sub.erase(nodes[parentOfDeletedNode].sub.begin() + i);
		}
	}

	dfs(rootIndex);

	cout << cnt;


	return 0;
}
