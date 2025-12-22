#include <iostream>
#include <vector>

using namespace std;

vector<int> union_find;

int uf_get_head(const int id) {
	if (union_find[id] == -1 || union_find[id] == id) {
		return union_find[id] = id;
	}

	return union_find[id] = uf_get_head(union_find[id]);
}

void uf_merge(const int id_1, const int id_2) {
	const int head_1 = uf_get_head(id_1);
	const int head_2 = uf_get_head(id_2);

	union_find[head_1] = head_2;
}

void test_case(const int id) {
	int N;
	cin >> N;

	union_find = vector<int>(N, -1);

	int K;
	cin >> K;

	for (int i = 0; i < K; ++i) {
		int a, b;
		cin >> a >> b;

		uf_merge(a, b);
	}

	int M;
	cin >> M;

	cout << "Scenario " << id << ":\n";
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;

		if (uf_get_head(u) == uf_get_head(v)) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

	cout << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case(i + 1);
	}

	return 0;
}