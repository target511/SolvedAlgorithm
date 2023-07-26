#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> infos;
vector<int> ranking;

void makeRank() {
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < N; m++) {
			if (n == m)
				continue;

			if (infos[n][0] > infos[m][0] && infos[n][1] > infos[m][1]) {
				ranking[m]++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	infos = vector<vector<int>>(N, vector<int>(2, 0));
	for (int n = 0; n < N; n++) {
		cin >> infos[n][0] >> infos[n][1];
	}

	ranking = vector<int>(N, 1);
	makeRank();

	for (int n = 0; n < N; n++) {
		cout << ranking[n] << ' ';
	}

	return 0;
}

/*
모든 인원이 등수 1로 시작하여
나머지 모든 인원을 탐색하며
자신보다 덩치가 큰 인원이 존재한다면 +1 한다.
*/