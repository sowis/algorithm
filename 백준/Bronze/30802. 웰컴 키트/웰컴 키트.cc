#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> sizes(6);
	for (int& sz : sizes) {
		scanf("%d", &sz);
	}

	int T, P;
	scanf("%d%d", &T, &P);

	int t_count = 0;
	for (const int num : sizes) {
		t_count += (num % T) ? 1 : 0;
		t_count += num / T;
	}

	printf("%d\n", t_count);
	printf("%d %d\n", N / P, N % P);

	return 0;
}