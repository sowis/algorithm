#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int N, K;
int store_count = 0;
vector<int> arr;
vector<int> tmp;

void merge(vector<int>& v, int p, int q, int r) {
	int i = p;
	int j = q + 1;
	int t = 1;

	while (i <= q && j <= r) {
		if (v[i] <= v[j]) {
			tmp[t++] = v[i++];
		}
		else {
			tmp[t++] = v[j++];
		}
	}

	while (i <= q) {
		tmp[t++] = v[i++];
	}

	while (j <= r) {
		tmp[t++] = v[j++];
	}

	i = p;
	t = 1;

	while (i <= r) {
		++store_count;
		if (store_count == K) {
			printf("%d\n", tmp[t]);
			exit(0);
		}

		v[i++] = tmp[t++];
	}
}

void merge_sort(vector<int>& v, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(v, p, q);
		merge_sort(v, q + 1, r);
		merge(v, p, q, r);
	}
}

int main(void) {
	scanf("%d%d", &N, &K);

	arr = vector<int>(N);
	tmp = vector<int>(N + 1);

	for (int& num : arr) {
		scanf("%d", &num);
	}

	merge_sort(arr, 0, N - 1);

	printf("-1\n");

	return 0;
}