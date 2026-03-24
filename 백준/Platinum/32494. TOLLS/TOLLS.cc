#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef struct _data {
	long long pos_1;
	long long pos_2;
	long long dist;

	bool operator< (const struct _data& d) const {
		return this->dist < d.dist;
	}
} Data;

long long N, Q;
vector<long long> union_find(100002, -1);
vector<long long> union_find_size(100002, 1);
map<long long, long long> dist_count;

long long uf_head(const long long id) {
	if (union_find[id] == -1 || union_find[id] == id) {
		return union_find[id] = id;
	}

	const long long new_head = uf_head(union_find[id]);
	union_find_size[id] = union_find_size[new_head];
	return union_find[id] = new_head;
}

void uf_merge(const long long id_1, const long long id_2) {
	const long long head_1 = uf_head(id_1);
	const long long head_2 = uf_head(id_2);

	union_find[head_2] = head_1;
	union_find_size[head_1] += union_find_size[head_2];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> Q;

	vector<Data> edges;
	for (long long i = 1; i < N; ++i) {
		long long v1, v2, w;
		cin >> v1 >> v2 >> w;

		edges.push_back({ v1, v2, w });
	}

	sort(edges.begin(), edges.end());

	for (const Data& edge : edges) {
		if (dist_count.find(edge.dist) == dist_count.end()) {
			dist_count.insert({ edge.dist, union_find_size[uf_head(edge.pos_1)] * union_find_size[uf_head(edge.pos_2)]});
		}
		else {
			dist_count[edge.dist] += union_find_size[uf_head(edge.pos_1)] * union_find_size[uf_head(edge.pos_2)];
		}

		uf_merge(edge.pos_1, edge.pos_2);
	}

	vector<long long> distances{ 0 };
	vector<long long> psum{ 0 };

	for (const pair<long long, long long>& p : dist_count) {
		distances.push_back(p.first);
		psum.push_back(psum[psum.size() - 1] + p.first * (long long)p.second);
	}

	for (long long i = 0; i < Q; ++i) {
		long long l, r;
		cin >> l >> r;

		const long long right_idx = (upper_bound(distances.begin(), distances.end(), r) - distances.begin()) - 1;
		const long long left_idx = (lower_bound(distances.begin(), distances.end(), l) - distances.begin()) - 1;
		cout << psum[right_idx] - psum[left_idx] << "\n";
	}

	return 0;
}