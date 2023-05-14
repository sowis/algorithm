#include <cstdio>
#include <vector>

using namespace std;

constexpr int adds[3] = { 1, 3, 4 };

vector<int> cache(1001, -1);

bool is_win(const int remain) {
	int& c = cache[remain];
	if (c != -1) {
		return c;
	}

	c = !is_win(remain - 1) || !is_win(remain - 3) || !is_win(remain - 4);
	return c;
}

int main(void) {
	cache[1] = 1;
	cache[2] = 0;
	cache[3] = 1;
	cache[4] = 1;

	int N;
	scanf("%d", &N);

	if (is_win(N)) {
		printf("SK\n");
	}
	else {
		printf("CY\n");
	}

	return 0;
}