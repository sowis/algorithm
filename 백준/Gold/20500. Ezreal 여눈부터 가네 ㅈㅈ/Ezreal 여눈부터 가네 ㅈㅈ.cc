#include <iostream>
#include <vector>

using namespace std;

constexpr int DIV = 1000000007;

int N;
vector<vector<int>> cache; // [자릿수][1과 5로만 구성되어있고 1의 자리가 5이고 자릿수마다 수를 다 더한 후 3으로 나누었을때 나머지가 이 수인 수의 개수]

int main(void) {
	cin >> N;

	cache = vector<vector<int>>(N + 1, vector<int>(3, 0));
	cache[1][2] = 1; // 5

	for (int digit = 1; digit < N; ++digit) {
		for (int cur_div = 0; cur_div < 3; ++cur_div) {
			cache[digit + 1][(cur_div + 1) % 3] += cache[digit][cur_div]; // 맨앞자리에 1을 추가하는경우
			cache[digit + 1][(cur_div + 1) % 3] %= DIV;
			cache[digit + 1][(cur_div + 5) % 3] += cache[digit][cur_div]; // 맨앞자리에 5를 추가하는경우
			cache[digit + 1][(cur_div + 5) % 3] %= DIV;
		}
	}

	cout << cache[N][0];

	return 0;
}