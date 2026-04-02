#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

int N;
vector<int> A;
vector<int> A_psum;
deque<int> deques[200003]; // deques[현재 범위 안에 있는 값] = { 이 값이 등장한 인덱스, 인덱스, ... } (오름차순)
int cur_max_dist = 0;
int distance_count[200003]; // distance_count[dist] = 현재 범위 안에 있는 거리가 dist 인 쌍의 개수

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

bool compare_by_order(const Query& q1, const Query& q2) {
	return q1.order < q2.order;
}

void add(const int idx, const bool left) {
	if (deques[A_psum[idx]].size() >= 2) {
		const int dist = deques[A_psum[idx]].back() - deques[A_psum[idx]].front();
		--distance_count[dist];
	}

	if (left) {
		deques[A_psum[idx]].push_front(idx);
	}
	else {
		deques[A_psum[idx]].push_back(idx);
	}

	if (deques[A_psum[idx]].size() >= 2) {
		const int dist = deques[A_psum[idx]].back() - deques[A_psum[idx]].front();
		++distance_count[dist];
		cur_max_dist = max(cur_max_dist, dist);
	}
}

void remove(const int idx, const bool left) {
	if (deques[A_psum[idx]].size() >= 2) {
		const int dist = deques[A_psum[idx]].back() - deques[A_psum[idx]].front();
		--distance_count[dist];
	}

	if (left) {
		deques[A_psum[idx]].pop_front();
	}
	else {
		deques[A_psum[idx]].pop_back();
	}

	if (deques[A_psum[idx]].size() >= 2) {
		const int dist = deques[A_psum[idx]].back() - deques[A_psum[idx]].front();
		++distance_count[dist];
		cur_max_dist = max(cur_max_dist, dist);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	A = vector<int>(N);

	for (int& a : A) {
		cin >> a;
	}

	A_psum.push_back(0);
	for (const int a : A) {
		A_psum.push_back(A_psum.back() + a);
	}

	for (int& a_psum : A_psum) {
		a_psum += 100000;
	}

	int M;
	cin >> M;
	vector<Query> queries(M);

	for (int i = 0; i < M; ++i) {
		cin >> queries[i].begin >> queries[i].end;
		queries[i].order = i;
		--queries[i].begin; // psum 배열 맨 앞에 0 패딩을 위해...
	}

	sort(queries.begin(), queries.end());

	int left = 0, right = -1;
	for (Query& query : queries) {
		while (right < query.end) {
			++right;
			add(right, false);
		}

		while (query.begin < left) {
			--left;
			add(left, true);
		}

		while (query.end < right) {
			remove(right, false);
			--right;
		}

		while (left < query.begin) {
			remove(left, true);
			++left;
		}

		while (cur_max_dist > 0 && distance_count[cur_max_dist] == 0) {
			--cur_max_dist;
		}

		query.result = cur_max_dist;
	}

	sort(queries.begin(), queries.end(), compare_by_order);
	for (const Query& query : queries) {
		cout << query.result << "\n";
	}

	return 0;
}