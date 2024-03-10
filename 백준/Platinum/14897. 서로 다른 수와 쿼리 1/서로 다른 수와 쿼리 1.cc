#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int sqrt_n;

typedef struct _query {
	int l;
	int r;
	int idx;

	bool operator< (const struct _query& q) const {
		if (this->l / sqrt_n != q.l / sqrt_n) {
			return this->l / sqrt_n < q.l / sqrt_n;
		}

		return this->r < q.r;
	}
} Query;

typedef struct _data {
	int origin_number;
	int compressed_number;
	int origin_index;

	bool operator< (const struct _data& d) const {
		return this->origin_number < d.origin_number;
	}
} Data;

class Counter {
private:
	vector<int> number_count;
	int diff_count;

public:
	Counter(void)
		:number_count(vector<int>(1000001, 0)), diff_count(0) {}

	void insert(const int num) {
		if (this->number_count[num] == 0) {
			++this->diff_count;
		}

		++this->number_count[num];
	}

	void remove(const int num) {
		--this->number_count[num];
		if (this->number_count[num] == 0) {
			--this->diff_count;
		}
	}

	int get_diff(void) const {
		return this->diff_count;
	}
};

vector<int> compress(const vector<int>& origins) {
	vector<Data> datas(origins.size());
	for (int i = 0; i < datas.size(); ++i) {
		datas[i].origin_number = origins[i];
		datas[i].origin_index = i;
	}

	sort(datas.begin(), datas.end());

	int comp = 1;
	datas[0].compressed_number = 1;
	for (int i = 1; i < datas.size(); ++i) {
		if (datas[i - 1].origin_number < datas[i].origin_number) {
			++comp;
		}

		datas[i].compressed_number = comp;
	}

	vector<int> result(origins.size());
	for (const Data& d : datas) {
		result[d.origin_index] = d.compressed_number;
	}

	return result;
}

int main(void) {
	int N;
	scanf("%d", &N);

	sqrt_n = (int)sqrt(N);

	vector<int> origins(N);
	for (int& num : origins) {
		scanf("%d", &num);
	}

	int Q;
	scanf("%d", &Q);

	vector<Query> queries(Q);
	for (int i = 0; i < Q; ++i) {
		scanf("%d%d", &queries[i].l, &queries[i].r);
		--queries[i].l;
		queries[i].idx = i;
	}

	sort(queries.begin(), queries.end());
	vector<int> results(Q);
	vector<int> compressed = compress(origins);
	int begin = 0;
	int end = 0;
	Counter counter;

	for (const Query& q : queries) {
		while (end < q.r) {
			counter.insert(compressed[end]);
			++end;
		}

		while (q.l < begin) {
			counter.insert(compressed[begin - 1]);
			--begin;
		}

		while (q.r < end) {
			counter.remove(compressed[end - 1]);
			--end;
		}

		while (begin < q.l) {
			counter.remove(compressed[begin]);
			++begin;
		}

		results[q.idx] = counter.get_diff();
	}

	for (const int result : results) {
		printf("%d\n", result);
	}

	return 0;
}