#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <set>
#include <unordered_map>

using namespace std;

int N, K;
vector<int> A, A_psum;
vector<deque<int>> inside_indexes;
int distances[100002];
int current_max_distance = 0;

typedef struct _query {
	int begin;
	int end;
	int order;
	int result;

	bool operator< (const struct _query& q) const {
		if (floor(this->begin / sqrt(N)) != floor(q.begin / sqrt(N))) {
			return this->begin / sqrt(N) < q.begin / sqrt(N);
		}

		return this->end < q.end;
	}
} Query;

bool compare_by_order(const struct _query& q1, const struct _query& q2) {
	return q1.order < q2.order;
}

void add(const int idx, const bool left) {
	if (inside_indexes[A_psum[idx]].size() >= 2) {
		--distances[inside_indexes[A_psum[idx]].back() - inside_indexes[A_psum[idx]].front()];
	}

	if (left) {
		inside_indexes[A_psum[idx]].push_front(idx);
	}
	else {
		inside_indexes[A_psum[idx]].push_back(idx);
	}

	if (inside_indexes[A_psum[idx]].size() >= 2) {
		const int new_dist = inside_indexes[A_psum[idx]].back() - inside_indexes[A_psum[idx]].front();
		++distances[new_dist];
		current_max_distance = max(current_max_distance, new_dist);
	}
}

void remove(const int idx, const bool left) {
	if (inside_indexes[A_psum[idx]].size() >= 2) {
		--distances[inside_indexes[A_psum[idx]].back() - inside_indexes[A_psum[idx]].front()];
	}

	if (left) {
		inside_indexes[A_psum[idx]].pop_front();
	}
	else {
		inside_indexes[A_psum[idx]].pop_back();
	}

	if (inside_indexes[A_psum[idx]].size() >= 2) {
		const int new_dist = inside_indexes[A_psum[idx]].back() - inside_indexes[A_psum[idx]].front();
		++distances[new_dist];
		current_max_distance = max(current_max_distance, new_dist);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	A = vector<int>(N);
	for (int& a : A) {
		cin >> a;
	}

	A_psum.push_back(0); // 0패딩
	for (const int a : A) {
		A_psum.push_back((A_psum.back() + a) % K);
	}

	set<int> A_psum_set;
	for (const int a_psum : A_psum) {
		A_psum_set.insert(a_psum);
	}

	unordered_map<int, int> A_psum_map;
	int psum_compress = 0;
	for (const int& a_psum_set : A_psum_set) {
		A_psum_map[a_psum_set] = psum_compress;
		++psum_compress;
	}

	for (int& a_psum : A_psum) {
		a_psum = A_psum_map[a_psum];
	}

	inside_indexes = vector<deque<int>>((int)A_psum_set.size() + 2);

	int M;
	cin >> M;

	vector<Query> queries(M);
	for (int i = 0; i < M; ++i) {
		cin >> queries[i].begin >> queries[i].end;
		--queries[i].begin; // A_psum배열의 0패딩과 맞추기 위해
		queries[i].order = i;
	}

	sort(queries.begin(), queries.end());

	int left = 0, right = -1;
	for (Query& query : queries) {
		while (query.begin < left) {
			--left;
			add(left, true);
		}

		while (right < query.end) {
			++right;
			add(right, false);
		}

		while (left < query.begin) {
			remove(left, true);
			++left;
		}

		while (query.end < right) {
			remove(right, false);
			--right;
		}

		while (current_max_distance > 0 && distances[current_max_distance] == 0) {
			--current_max_distance;
		}

		query.result = current_max_distance;
	}

	sort(queries.begin(), queries.end(), compare_by_order);
	for (const Query& query : queries) {
		cout << query.result << "\n";
	}

	return 0;
}