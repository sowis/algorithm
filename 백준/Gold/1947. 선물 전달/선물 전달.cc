#include <iostream>
#include <vector>

using namespace std;

constexpr long long DIV = 1000000000;

vector<long long> cache(1000001, -1);

int main(void) {
	int N;
	cin >> N;

	cache[1] = 0;
	cache[2] = 1;

	for (int i = 3; i <= 1000000; ++i) {
		cache[i] = (i - 1) * ((cache[i - 1] + cache[i - 2]) % DIV) % DIV;
	}

	cout << cache[N];

	return 0;
}