#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int > v(N);
	for (int& n : v) {
		scanf("%d", &n);
	}

	int k;
	scanf("%d", &k);

	const int term = N / k;
	for (int i = 0; i < k; ++i) {
		sort(v.begin() + i * term, v.begin() + (i + 1) * term);
	}
	
	for (const int n : v) {
		printf("%d ", n);
	}

	return 0;
}