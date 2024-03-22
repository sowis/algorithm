#include <cstdio>
#include <vector>

using namespace std;

class SegmentTree {
private:
	int N;
	vector<int> arr;
	vector<int> lazy;

	void init(const int begin, const int end, const int idx, const vector<int>& origin) {
		if (end - begin == 1) {
			this->arr[idx] = origin[begin];
			return;
		}

		const int mid = (begin + end) / 2;
		init(begin, mid, idx * 2, origin);
		init(mid, end, idx * 2 + 1, origin);
		this->arr[idx] = this->arr[idx * 2] ^ this->arr[idx * 2 + 1];
	}

	void lazy_process(const int begin, const int end, const int idx) {
		if (end - begin != 1) {
			this->lazy[idx * 2] ^= this->lazy[idx];
			this->lazy[idx * 2 + 1] ^= this->lazy[idx];
		}

		if ((end - begin) % 2) {
			this->arr[idx] ^= this->lazy[idx];
		}
	
		this->lazy[idx] = 0;
	}

	void op_1(const int target_begin, const int target_end, const int k, const int begin, const int end, const int idx) {
		this->lazy_process(begin, end, idx);

		if (target_end <= begin || end <= target_begin) {
			return;
		}

		if (target_begin <= begin && end <= target_end) {
			this->lazy[idx] ^= k;
			this->lazy_process(begin, end, idx);
			return;
		}

		const int mid = (begin + end) / 2;
		this->op_1(target_begin, target_end, k, begin, mid, idx * 2);
		this->op_1(target_begin, target_end, k, mid, end, idx * 2 + 1);
		this->arr[idx] = this->arr[idx * 2] ^ this->arr[idx * 2 + 1];
	}

	int op_2(const int target_begin, const int target_end, const int begin, const int end, const int idx) {
		this->lazy_process(begin, end, idx);

		if (target_end <= begin || end <= target_begin) {
			return 0;
		}

		if (target_begin <= begin && end <= target_end) {
			return this->arr[idx];
		}

		const int mid = (begin + end) / 2;
		return this->op_2(target_begin, target_end, begin, mid, idx * 2) ^ this->op_2(target_begin, target_end, mid, end, idx * 2 + 1);
	}

public:
	SegmentTree(const vector<int>& origin)
		:N((int)origin.size()) {
		this->arr = vector<int>(N * 4);
		this->lazy = vector<int>(N * 4, 0);
		this->init(0, this->N, 1, origin);
	}

	void op_1(const int target_begin, const int target_end, const int k) {
		this->op_1(target_begin, target_end, k, 0, this->N, 1);
	}

	void op_2(const int target_begin, const int target_end) {
		const int result = this->op_2(target_begin, target_end, 0, this->N, 1);
		printf("%d\n", result);
	}
};

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> A(N);
	for (int& a : A) {
		scanf("%d", &a);
	}

	SegmentTree segtree(A);

	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; ++i) {
		int op;
		scanf("%d", &op);

		if (op == 1) {
			int i, j, k;
			scanf("%d%d%d", &i, &j, &k);

			segtree.op_1(i, j + 1, k);
		}
		else {
			int i, j;
			scanf("%d%d", &i, &j);

			segtree.op_2(i, j + 1);
		}
	}

	return 0;
}