#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> cache;

int main(void) {
	cin >> N >> K;

	cache = vector<int>(N + 1, 1987654321); // [위치] = 여기까지 오는데 걸리는 가장 짧은 횟수
	cache[0] = 0; // 0에서 시작

	for (int i = 0; i < N; ++i) {
		if (cache[i] == 1987654321) {
			continue;
		}

		if (cache[i] + 1 < cache[i + 1]) {
			cache[i + 1] = cache[i] + 1;
		}

		if ((i + (i / 2)) <= N && cache[i] + 1 < cache[i + (i / 2)]) {
			cache[i + (i / 2)] = cache[i] + 1;
		}
	}

	if (K < cache[N]) {
		cout << "water";
	}
	else {
		cout << "minigimbob";
	}

	return 0;
}