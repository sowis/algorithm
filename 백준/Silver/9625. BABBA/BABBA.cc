#include <vector>
#include <cstdio>

using namespace std;

vector<int> cache(50, -1);

int fibo(const int target) {
	if (cache[target] != -1) {
		return cache[target];
	}

	return cache[target] = fibo(target - 1) + fibo(target - 2);
}

int main(void) {
	int K;
	scanf("%d", &K);

	cache[0] = 0;
	cache[1] = 1;

	printf("%d %d\n", fibo(K - 1), fibo(K));
	
	return 0;
}