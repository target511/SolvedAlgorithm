#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> direction = vector<int>{ 0, 4, 3, 1, 2 };
vector<int> lengths = vector<int>(6, 0);
int main() {
	cin >> N;

	int tmp1, tmp2;
	int cornerIndex = 0;
	cin >> tmp1 >> lengths[0];
	for (int i = 1; i < 6; i++) {
		cin >> tmp2 >> lengths[i];
		if (tmp2 != direction[tmp1]) {
			cornerIndex = i;
		}
		tmp1 = tmp2;
	}

	int a = cornerIndex + 2 > 5 ? cornerIndex - 4 : cornerIndex + 2;
	int b = cornerIndex + 3 > 5 ? cornerIndex - 3 : cornerIndex + 3;
	int c = cornerIndex - 1 < 0 ? cornerIndex + 5 : cornerIndex - 1;
	int d = cornerIndex;
	int size = lengths[a] * lengths[b] - lengths[c] * lengths[d];

	cout << N * size;
	

	return 0;
}

// ��ȸ�� �ؾ��ϴ� ���� ������ direction�� ���� ���� ��ġ���� �ʴ´ٸ�
// cornerIndex�� �ڳ� ��ġ�� ����
// �ڳ� ��ġ �������� ���� ���� �� ����� ����