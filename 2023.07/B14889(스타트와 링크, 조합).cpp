#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> synergy;
vector<int> team1, team2;
int result = 987654321;

int balance() {
	int synergy1 = 0, synergy2 = 0;
	for (int i = 0; i < team1.size(); i++) {
		for (int j = i + 1; j < team1.size(); j++) {
			synergy1 += synergy[team1[i]][team1[j]];
			synergy2 += synergy[team2[i]][team2[j]];
		}
	}

	return abs(synergy1 - synergy2);
}

void makeTeam2() {
	vector<bool> isTeam1 = vector<bool>(N + 1, false);
	team2.clear();
	for (int i = 0; i < team1.size(); i++) {
		isTeam1[team1[i]] = true;
	}

	for (int i = 1; i <= N; i++) {
		if (!isTeam1[i])
			team2.push_back(i);
	}
}

void combination(int d, int iter) {
	if (d == N / 2) {
		makeTeam2();
		
		int bal = balance();
		if (result > bal)
			result = bal;

		return;
	}

	for (int i = iter; i <= N; i++) {
		team1[d] = i;
		combination(d + 1, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	synergy = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	team1 = vector<int>(N / 2, 0);

	int tmp;
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= N; m++) {
			cin >> tmp;
			if (n < m) {
				synergy[n][m] += tmp;
			}
			else if (n > m) {
				synergy[m][n] += tmp;
			}
		}
	}

	combination(0, 1);
	cout << result;


	return 0;
}