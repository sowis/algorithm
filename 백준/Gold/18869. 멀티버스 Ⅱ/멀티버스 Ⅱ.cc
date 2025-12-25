#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int M, N;
vector<vector<int>> datas(M, vector<int>(N));

bool same(const int space_id_1, const int space_id_2) {
	for (int i = 0; i < N; ++i) {
		if (datas[space_id_1][i] != datas[space_id_2][i]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	cin >> M >> N;

	datas = vector<vector<int>>(M, vector<int>(N));
	for (int i = 0; i < M; ++i) {
		set<int> sizes;

		for (int k = 0; k < N; ++k) {
			cin >> datas[i][k];
			sizes.insert(datas[i][k]);
		}

		unordered_map<int, int> mapping;
		int zip = 0;
		for (const int size : sizes) {
			mapping[size] = zip;
			++zip;
		}

		for (int k = 0; k < N; ++k) {
			datas[i][k] = mapping[datas[i][k]];
		}
	}

	int result = 0;
	for (int space_id_1 = 0; space_id_1 < M; ++space_id_1) {
		for (int space_id_2 = space_id_1 + 1; space_id_2 < M; ++space_id_2) {
			if (same(space_id_1, space_id_2)) {
				++result;
			}
		}
	}

	cout << result;

	return 0;
}