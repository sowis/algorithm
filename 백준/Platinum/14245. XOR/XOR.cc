#include <cstdio>
#include <vector>

using namespace std;

class Segtree {
private:
	int N;
	vector<int> arr;
	vector<int> lazy;

	void init(const vector<int>& origin, const int begin, const int end, const int idx) {
		if (end - begin == 1) {
			this->arr[idx] = origin[begin];
			return;
		}

		const int mid = (begin + end) / 2;
		this->init(origin, begin, mid, idx * 2);
		this->init(origin, mid, end, idx * 2 + 1);
	}

	void lazy_progress(const int begin, const int end, const int idx) {
		this->arr[idx] ^= this->lazy[idx];

		if (end - begin != 1) {
			this->lazy[idx * 2] ^= this->lazy[idx];
			this->lazy[idx * 2 + 1] ^= this->lazy[idx];
		}

		this->lazy[idx] = 0;
	}

	void update(const int target_begin, const int target_end, const int value, const int begin, const int end, const int idx) {
		if (target_end <= begin || end <= target_begin) {
			this->lazy_progress(begin, end, idx);
			return;
		}

		if (target_begin <= begin && end <= target_end) {
			this->lazy[idx] ^= value;
			this->lazy_progress(begin, end, idx);
			return;
		}

		this->lazy_progress(begin, end, idx);
		
		const int mid = (begin + end) / 2;
		this->update(target_begin, target_end, value, begin, mid, idx * 2);
		this->update(target_begin, target_end, value, mid, end, idx * 2 + 1);
	}

	int get(const int target, const int begin, const int end, const int idx) {
		this->lazy_progress(begin, end, idx);

		if (target < begin || end <= target) {
			return 0;
		}

		if (end - begin == 1) {
			return this->arr[idx];
		}

		const int mid = (begin + end) / 2;
		return this->get(target, begin, mid, idx * 2) + this->get(target, mid, end, idx * 2 + 1);
	}

public:
	Segtree(const vector<int>& origin)
		:N((int)origin.size()) {
		this->arr = vector<int>(this->N * 4, 0);
		this->lazy = vector<int>(this->N * 4, 0);
		this->init(origin, 0, this->N, 1);
	}

	void update(const int target_begin, const int target_end, const int value) {
		this->update(target_begin, target_end, value, 0, this->N, 1);
	}

	int get(const int target) {
		return this->get(target, 0, this->N, 1);
	}
};

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> arr(N);
	for (int& n : arr) {
		scanf("%d", &n);
	}

	Segtree segtree(arr);

	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; ++i) {
		int t;
		scanf("%d", &t);

		if (t == 1) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);

			segtree.update(a, b + 1, c);
		}
		else {
			int a;
			scanf("%d", &a);

			printf("%d\n", segtree.get(a));
		}
	}

	return 0;
}