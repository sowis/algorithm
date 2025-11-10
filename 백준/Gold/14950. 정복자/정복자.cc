#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct _data {
	int begin;
	int end;
	int dist;

	bool operator<(const struct _data& d) const {
		return this->dist > d.dist;
	}
} Data;

int N, M, t;
vector<int> union_find;

int uf_get_head(const int id) {
	if (union_find[id] == id || union_find[id] == -1) {
		return union_find[id] = id;
	}

	return union_find[id] = uf_get_head(union_find[id]);
}

void uf_merge(const int id_1, const int id_2) {
	const int head_1 = uf_get_head(id_1);
	const int head_2 = uf_get_head(id_2);

	union_find[head_1] = head_2;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> t;

	priority_queue<Data> q;
	for (int i = 0; i < M; ++i) {
		int A, B, C;
		cin >> A >> B >> C;

		q.push({ A, B, C });
	}
	
	union_find = vector<int>(N + 1, -1);
	int result = 0;
	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		if (uf_get_head(d.begin) == uf_get_head(d.end)) {
			continue;
		}

		uf_merge(d.begin, d.end);
		result += d.dist;
	}

	if (N > 1) {
		result += t * (N - 1) * (N - 2) / 2;
	}

	cout << result;

	return 0;
}