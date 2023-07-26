#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> infos;
vector<vector<int>> memo;

void dp() {
	if (infos[N - 1].first - 1 > 0) {
		memo[N - 1][0] = 0;
		memo[N - 1][1] = 0;
	}
	else {
		memo[N - 1][0] = 0;
		memo[N - 1][1] = infos[N - 1].second;
	}


	for (int i = N - 2; i >= 0; i--) {
		if (i + infos[i].first > N) {
			memo[i][0] = memo[i + 1][0] > memo[i + 1][1] ? memo[i + 1][0] : memo[i + 1][1];
			memo[i][1] = memo[i + 1][0] > memo[i + 1][1] ? memo[i + 1][0] : memo[i + 1][1];
			continue;
		}

		memo[i][0] = memo[i + 1][0] > memo[i + 1][1] ? memo[i + 1][0] : memo[i + 1][1];
		memo[i][1] = memo[i + infos[i].first - 1][0] + infos[i].second;
	}
}

int main() {
	cin >> N;
	int tmp1, tmp2;
	for (int n = 0; n < N; n++) {
		cin >> tmp1 >> tmp2;
		infos.push_back(make_pair(tmp1, tmp2));
	}
	memo = vector<vector<int>>(N, vector<int>(2));
	
	dp();
	int result = memo[0][0] > memo[0][1] ? memo[0][0] : memo[0][1];
	cout << result;

	return 0;
}