#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> union_find;

int uf_get_head(const int id) {
	if (union_find[id] == -1 || union_find[id] == id) {
		return union_find[id] = id;
	}

	return union_find[id] = uf_get_head(union_find[id]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	union_find = vector<int>(N, -1);
	int line_count = 0;
	int cycle_count = 0;
	for (int i = 0; i < M; ++i) {
		int node_1, node_2;
		cin >> node_1 >> node_2;

		--node_1; // 0부터 시작하도록..
		--node_2;

		const int head_1 = uf_get_head(node_1);
		const int head_2 = uf_get_head(node_2);

		if (head_1 == head_2) { // 사이클
			++cycle_count;
			continue;
		}

		union_find[head_1] = head_2; // merge
		++line_count;
	}

	cout << (N - 1) - line_count + cycle_count; // 트리에 필요한 경로 수 - 이미 있는 경로 수 + 사이클 수

	return 0;
}