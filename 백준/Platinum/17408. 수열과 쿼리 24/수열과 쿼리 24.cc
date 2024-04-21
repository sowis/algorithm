#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Segtree {
private:
	int N;
	vector<pair<int, int>> arr;

	pair<int, int> get_max_2(const pair<int, int>& p1, const pair<int, int>& p2) const {
		vector<int> soup;
		soup.push_back(p1.first);
		soup.push_back(p1.second);
		soup.push_back(p2.first);
		soup.push_back(p2.second);

		sort(soup.begin(), soup.end());
		return { soup[3], soup[2] };
	}

	void init(const vector<int>& origin, const int begin, const int end, const int idx) {
		if (end - begin == 1) {
			this->arr[idx].first = origin[begin];
			return;
		}

		const int mid = (begin + end) / 2;
		this->init(origin, begin, mid, idx * 2);
		this->init(origin, mid, end, idx * 2 + 1);
		this->arr[idx] = this->get_max_2(arr[idx * 2], arr[idx * 2 + 1]);
	}

	pair<int, int> update(const int target, const int value, const int begin, const int end, const int idx) {
		if (target < begin || end <= target) {
			return this->arr[idx];
		}

		if (end - begin == 1) {
			this->arr[idx].first = value;
			return this->arr[idx];
		}

		const int mid = (begin + end) / 2;
		const pair<int, int> left = update(target, value, begin, mid, idx * 2);
		const pair<int, int> right = update(target, value, mid, end, idx * 2 + 1);
		this->arr[idx] = this->get_max_2(left, right);
		return this->arr[idx];
	}

	pair<int, int> get_max_sum(const int target_begin, const int target_end, const int begin, const int end, const int idx) const {
		if (target_end <= begin || end <= target_begin) {
			return { numeric_limits<int>::min(), numeric_limits<int>::min() };
		}

		if (target_begin <= begin && end <= target_end) {
			return this->arr[idx];
		}

		const int mid = (begin + end) / 2;
		const pair<int, int> left = this->get_max_sum(target_begin, target_end, begin, mid, idx * 2);
		const pair<int, int> right = this->get_max_sum(target_begin, target_end, mid, end, idx * 2 + 1);
		return this->get_max_2(left, right);
	}

public:
	Segtree(const vector<int>& origin)
		:N((int)origin.size()) {
		this->arr = vector<pair<int, int>>(this->N * 4, { numeric_limits<int>::min(), numeric_limits<int>::min() });
		this->init(origin, 0, this->N, 1);
	}

	void update(const int target, const int value) {
		this->update(target, value, 0, this->N, 1);
	}

	int get_max_sum(const int target_begin, const int target_end) const {
		const pair<int, int> result = this->get_max_sum(target_begin, target_end, 0, this->N, 1);
		return result.first + result.second;
	}
};

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> origin(N);
	for (int& num : origin) {
		scanf("%d", &num);
	}

	Segtree segtree(origin);

	int M;
	scanf("%d", &M);

	for (int k = 0; k < M; ++k) {
		int op;
		scanf("%d", &op);

		if (op == 1) {
			int i, v;
			scanf("%d%d", &i, &v);

			segtree.update(i - 1, v);
		}
		else {
			int l, r;
			scanf("%d%d", &l, &r);

			const int result = segtree.get_max_sum(l - 1, r);
			printf("%d\n", result);
		}
	}

	return 0;
}