#include <iostream>
#include <vector>

using namespace std;

vector<int> union_find;
vector<int> union_find_size;

int uf_get_head(const int id) {
	if (union_find[id] == -1 || union_find[id] == id) {
		return union_find[id] = id;
	}

	union_find[id] = uf_get_head(union_find[id]);
	union_find_size[id] = union_find_size[union_find[id]];
	return union_find[id];
}

void uf_merge(const int id_1, const int id_2) {
	const int head_1 = uf_get_head(id_1);
	const int head_2 = uf_get_head(id_2);

	if (head_1 == head_2) {
		return;
	}

	union_find[head_1] = head_2;
	union_find_size[head_2] = union_find_size[head_1] + union_find_size[head_2];
}

inline int uf_get_size(const int id) {
	return union_find_size[uf_get_head(id)];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N;
	cin >> N;

	union_find = vector<int>(1000001, -1);
	union_find_size = vector<int>(1000001, 1);

	for (int i = 0; i < N; ++i) {
		char op;
		cin >> op;

		if (op == 'I') {
			int a, b;
			cin >> a >> b;

			uf_merge(a, b);
		}
		else {
			int c;
			cin >> c;

			cout << uf_get_size(c) << "\n";
		}
	}

	return 0;
}