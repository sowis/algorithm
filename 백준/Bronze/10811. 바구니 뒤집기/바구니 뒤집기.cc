#include <cstdio>
#include <algorithm>

using namespace std;

int arr[101];

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < 101; ++i) {
		arr[i] = i;
	}

	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		reverse(&arr[a], &arr[b + 1]);
	}

	for (int i = 1; i <= N; ++i) {
		printf("%d ", arr[i]);
	}

	return 0;
}