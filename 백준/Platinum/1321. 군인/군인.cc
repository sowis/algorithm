#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Segtree {
private:
	int N;
	vector<int> arr;

	void init(const vector<int>& origin, const int begin, const int end, const int idx) {
		if (end - begin == 1) {
			this->arr[idx] = origin[begin];
			return;
		}

		const int mid = (begin + end) / 2;
		this->init(origin, begin, mid, idx * 2);
		this->init(origin, mid, end, idx * 2 + 1);
		this->arr[idx] = this->arr[idx * 2] + this->arr[idx * 2 + 1];
	}

	void update(const int target, const int value, const int begin, const int end, const int idx) {
		if (target < begin || end <= target) {
			return;
		}

		this->arr[idx] += value;

		if (end - begin == 1) {
			return;
		}

		const int mid = (begin + end) / 2;
		this->update(target, value, begin, mid, idx * 2);
		this->update(target, value, mid, end, idx * 2 + 1);
	}

	int get(const int target_begin, const int target_end, const int begin, const int end, const int idx) const {
		if (target_end <= begin || end <= target_begin) {
			return 0;
		}

		if (target_begin <= begin && end <= target_end) {
			return this->arr[idx];
		}

		const int mid = (begin + end) / 2;
		return this->get(target_begin, target_end, begin, mid, idx * 2) + this->get(target_begin, target_end, mid, end, idx * 2 + 1);
	}

public:
	Segtree(const vector<int>& origin)
		:N((int)origin.size()) {
		this->arr = vector<int>(this->N * 4, 0);
		this->init(origin, 0, this->N, 1);
	}

	void update(const int target, const int value) {
		this->update(target, value, 0, this->N, 1);
	}

	int get(const int target_begin, const int target_end) const {
		return this->get(target_begin, target_end, 0, this->N, 1);
	}
};

int binary_search(const int N, const Segtree& segtree, const int target) {
	int begin = 0;
	int end = N - 1;
	int result = N;

	while (begin <= end) {
		const int mid = (begin + end) / 2;
		const int psum = segtree.get(0, mid);

		if (target <= psum) {
			result = min(result, mid);
			end = mid - 1;
		}
		else {
			begin = mid + 1;
		}
	}

	return result;
}

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
			int i, a;
			scanf("%d%d", &i, &a);

			segtree.update(i - 1, a);
		}
		else {
			int i;
			scanf("%d", &i);

			const int result = binary_search(N, segtree, i);
			printf("%d\n", result);
		}
	}

	return 0;
}