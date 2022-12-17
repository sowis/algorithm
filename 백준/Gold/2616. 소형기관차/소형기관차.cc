#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int length;
vector<int> passengers;
vector<int> psum;
int cache[4][50001];

int main(void) {
	scanf("%d", &N);

	passengers = vector<int>(N + 1);
	psum = vector<int>(N + 1);

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &passengers[i]);
	}

	scanf("%d", &length);

	psum[1] = passengers[1];
	for (int i = 2; i <= N; ++i) {
		psum[i] = psum[i - 1] + passengers[i];
	}

	for (int train = 1; train <= 3; ++train) {
		for (int car = train * length; car <= N; ++car) {
			cache[train][car] = max(cache[train][car - 1], cache[train - 1][car - length] + psum[car] - psum[car - length]);
		}
	}

	printf("%d\n", cache[3][N]);

	return 0;
}