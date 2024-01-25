#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<bool> is_q(N);
	for (int i = 0; i < N; ++i) {
		int a;
		scanf("%d", &a);

		if (a == 0) {
			is_q[i] = true;
		}
	}

	vector<int> q_items;
	for (int i = 0; i < N; ++i) {
		int b;
		scanf("%d", &b);

		if (is_q[i]) {
			q_items.push_back(b);
		}
	}

	queue<int> q;
	for (int i = q_items.size() - 1; i >= 0; --i) {
		q.push(q_items[i]);
	}

	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; ++i) {
		int c;
		scanf("%d", &c);

		q.push(c);
		printf("%d ", q.front());
		q.pop();
	}

	return 0;
}