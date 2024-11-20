#include <cstdio>
#include <vector>

using namespace std;

void print(const vector<int>& v) {
	for (const int i : v) {
		printf("%d ", i);
	}

	printf("\n");
}

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	vector<int> v(N);
	for (int& item : v) {
		scanf("%d", &item);
	}

	int store = 0;
	for (int i = 1; i < N; ++i) {
		int loc = i - 1;
		int newitem = v[i];

		while (loc >= 0 && newitem < v[loc]) {
			v[loc + 1] = v[loc];
			--loc;
			++store;

			if (store == K) {
				printf("%d\n", v[loc + 1]);
				return 0;
			}
		}

		if (loc + 1 != i) {
			v[loc + 1] = newitem;
			++store;
		}

		if (store == K) {
			printf("%d\n", newitem);
			return 0;
		}
	}

	printf("-1\n");

	return 0;
}