#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef struct _data {
	int y;
	int x;
	int cost;

	bool operator<(const struct _data& d) const {
		return this->cost > d.cost;
	}
} Data;

int N;
vector<int> uf;

int uf_get_head(const int current) {
	if (uf[current] == -1 || uf[current] == current) {
		return uf[current] = current;
	}

	return uf[current] = uf_get_head(uf[current]);
}

void uf_merge(const int node_1, const int node_2) {
	const int head_1 = uf_get_head(node_1);
	const int head_2 = uf_get_head(node_2);

	uf[head_1] = head_2;
}

bool uf_same(const int node_1, const int node_2) {
	const int head_1 = uf_get_head(node_1);
	const int head_2 = uf_get_head(node_2);

	return head_1 == head_2;
}

int main(void) {
	scanf("%d", &N);

	priority_queue<Data> q;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			int cost;
			scanf("%d", &cost);

			if (y == x) {
				continue;
			}

			q.push({ y, x, cost });
		}
	}

	uf = vector<int>(N, -1);
	long long result = 0;

	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		if (uf_same(d.y, d.x)) {
			continue;
		}

		uf_merge(d.y, d.x);
		result += d.cost;
	}

	printf("%lld\n", result);

	return 0;
}