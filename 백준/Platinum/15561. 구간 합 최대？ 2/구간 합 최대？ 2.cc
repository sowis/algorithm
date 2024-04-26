#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Segtree {
private:
	typedef struct _data {
		bool valid;
		int sum;
		int left_sum;
		int right_sum;
		int total_sum;
	} Data;

	int N;
	vector<int> sums;
	vector<int> left_sums;
	vector<int> right_sums;
	vector<int> total_sums;

	void init(const vector<int> &origin, const int begin, const int end, const int idx) {
		if (end - begin == 1) {
			this->sums[idx] = origin[begin];
			this->left_sums[idx] = origin[begin];
			this->right_sums[idx] = origin[begin];
			this->total_sums[idx] = origin[begin];
			return;
		}

		const int mid = (begin + end) / 2;
		this->init(origin, begin, mid, idx * 2);
		this->init(origin, mid, end, idx * 2 + 1);

		this->sums[idx] = this->sums[idx * 2] + this->sums[idx * 2 + 1];
		this->left_sums[idx] = max(this->left_sums[idx * 2], this->sums[idx * 2] + this->left_sums[idx * 2 + 1]);
		this->right_sums[idx] = max(this->right_sums[idx * 2] + this->sums[idx * 2 + 1], this->right_sums[idx * 2 + 1]);
		this->total_sums[idx] = max(this->total_sums[idx * 2], this->total_sums[idx * 2 + 1]);
		this->total_sums[idx] = max(this->total_sums[idx], this->right_sums[idx * 2] + this->left_sums[idx * 2 + 1]);
	}

	void update(const int target, const int value, const int begin, const int end, const int idx) {
		if (target < begin || end <= target) {
			return;
		}

		if (end - begin == 1) {
			this->sums[idx] = value;
			this->left_sums[idx] = value;
			this->right_sums[idx] = value;
			this->total_sums[idx] = value;
			return;
		}

		const int mid = (begin + end) / 2;
		this->update(target, value, begin, mid, idx * 2);
		this->update(target, value, mid, end, idx * 2 + 1);

		this->sums[idx] = this->sums[idx * 2] + this->sums[idx * 2 + 1];
		this->left_sums[idx] = max(this->left_sums[idx * 2], this->sums[idx * 2] + this->left_sums[idx * 2 + 1]);
		this->right_sums[idx] = max(this->right_sums[idx * 2] + this->sums[idx * 2 + 1], this->right_sums[idx * 2 + 1]);
		this->total_sums[idx] = max(this->total_sums[idx * 2], this->total_sums[idx * 2 + 1]);
		this->total_sums[idx] = max(this->total_sums[idx], this->right_sums[idx * 2] + this->left_sums[idx * 2 + 1]);
	}

	Data get_max(const int target_begin, const int target_end, const int begin, const int end, const int idx) const {
		if (target_end <= begin || end <= target_begin) {
			return { false, 0, 0, 0, 0 };
		}

		if (target_begin <= begin && end <= target_end) {
			return { true, this->sums[idx], this->left_sums[idx], this->right_sums[idx], this->total_sums[idx] };
		}

		const int mid = (begin + end) / 2;
		const Data left_data = this->get_max(target_begin, target_end, begin, mid, idx * 2);
		const Data right_data = this->get_max(target_begin, target_end, mid, end, idx * 2 + 1);

		if (left_data.valid == false) {
			return right_data;
		}

		if (right_data.valid == false) {
			return left_data;
		}

		const int sum = left_data.sum + right_data.sum;
		const int left_sum = max(left_data.left_sum, left_data.sum + right_data.left_sum);
		const int right_sum = max(left_data.right_sum + right_data.sum, right_data.right_sum);
		int total_sum = max(left_data.total_sum, right_data.total_sum);
		total_sum = max(total_sum, left_data.right_sum + right_data.left_sum);
		return { true, sum, left_sum, right_sum, total_sum };
	}

public:
	Segtree(const vector<int>& origin)
		:N((int)origin.size()) {
		this->sums = vector<int>(this->N * 4, 0);
		this->left_sums = vector<int>(this->N * 4, 0);
		this->right_sums = vector<int>(this->N * 4, 0);
		this->total_sums = vector<int>(this->N * 4, 0);
		
		this->init(origin, 0, this->N, 1);
	}

	void update(const int target, const int value) {
		this->update(target, value, 0, this->N, 1);
	}

	int get_max(const int target_begin, const int target_end) const {
		return this->get_max(target_begin, target_end, 0, this->N, 1).total_sum;
	}
};

int main(void) {
	int N, Q, U, V;
	scanf("%d%d%d%d", &N, &Q, &U, &V);

	vector<int> origin(N);
	for (int& num : origin) {
		scanf("%d", &num);
		num = U * num + V;
	}

	Segtree segtree(origin);

	for (int i = 0; i < Q; ++i) {
		int C, A, B;
		scanf("%d%d%d", &C, &A, &B);

		if (C == 0) {
			const int result = segtree.get_max(A - 1, B) - V;
			printf("%d\n", result);
		}
		else {
			segtree.update(A - 1, U * B + V);
		}
	}

	return 0;
}