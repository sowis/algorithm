#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;

	vector<vector<char>> v1(N, vector<char>(M));
	vector<vector<char>> v2(N, vector<char>(2 * M));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> v1[y][x];
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < 2 * M; ++x) {
			cin >> v2[y][x];
		}
	}

	vector<vector<char>> v1_mul(N, vector<char>(2 * M));
	for (int y = 0; y < N; ++y) {
		int mul_x = 0;
		for (int x = 0; x < M; ++x) {
			v1_mul[y][mul_x] = v1[y][x];
			++mul_x;
			v1_mul[y][mul_x] = v1[y][x];
			++mul_x;
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < 2 * M; ++x) {
			if (v1_mul[y][x] != v2[y][x]) {
				cout << "Not Eyfa\n";
				return 0;
			}
		}
	}

	cout << "Eyfa\n";

	return 0;
}