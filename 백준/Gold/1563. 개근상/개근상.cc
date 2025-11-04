#include <iostream>
#include <vector>

using namespace std;

constexpr int DIV = 1000000;

int main(void) {
	int N;
	cin >> N;

	vector<vector<vector<int>>> cache(N, vector<vector<int>>(2, vector<int>(3, 0))); // 현재 인덱스, 지각수, 연속결석수
	cache[0][0][0] = 1;
	cache[0][1][0] = 1;
	cache[0][0][1] = 1;

	for (int i = 0; i < N - 1; ++i) {
		for (int k = 0; k < 2; ++k) {
			for (int j = 0; j < 3; ++j) {
				cache[i + 1][k][0] += cache[i][k][j]; // 다음날 출석일 경우
				cache[i + 1][k][0] %= DIV;

				if (k < 1) { // 다음날 지각일 경우
					cache[i + 1][k + 1][0] += cache[i][k][j];
					cache[i + 1][k + 1][0] %= DIV;
				}

				if (j < 2) { // 다음날 결석일 경우
					cache[i + 1][k][j + 1] += cache[i][k][j];
					cache[i + 1][k][j + 1] %= DIV;
				}
			}
		}
	}

	int result = 0;
	for (int k = 0; k < 2; ++k) {
		for (int j = 0; j < 3; ++j) {
			result += cache[N - 1][k][j];
			result %= DIV;
		}
	}

	cout << result;

	return 0;
}