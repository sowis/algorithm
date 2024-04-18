#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Segtree {
private:
	int N;
	vector<int> origin;
	vector<int> arr;

	void init(const int begin, const int end, const int idx) {
		if (end - begin == 1) {
			this->arr[idx] = begin;
			return;
		}

		const int mid = (begin + end) / 2;
		this->init(begin, mid, idx * 2);
		this->init(mid, end, idx * 2 + 1);
		this->arr[idx] = (origin[this->arr[idx * 2]] < origin[this->arr[idx * 2 + 1]]) ? this->arr[idx * 2] : this->arr[idx * 2 + 1];
	}

	int get_min_idx(const int target_begin, const int target_end, const int begin, const int end, const int idx) const {
		if (target_end <= begin || end <= target_begin) {
			return numeric_limits<int>::max();
		}

		if (target_begin <= begin && end <= target_end) {
			return this->arr[idx];
		}

		const int mid = (begin + end) / 2;
		const int left_min_idx = this->get_min_idx(target_begin, target_end, begin, mid, idx * 2);
		const int right_min_idx = this->get_min_idx(target_begin, target_end, mid, end, idx * 2 + 1);
		if (left_min_idx == numeric_limits<int>::max()) {
			return right_min_idx;
		}
		else if (right_min_idx == numeric_limits<int>::max()) {
			return left_min_idx;
		}
		else {
			return (this->origin[left_min_idx] < this->origin[right_min_idx]) ? left_min_idx : right_min_idx;
		}
	}

public:
	Segtree(const vector<int>& origin)
		:N((int)origin.size()) {
		this->origin = origin;
		this->arr = vector<int>(this->N * 4, 0);
		this->init(0, this->N, 1);
	}

	int get_min_idx(const int target_begin, const int target_end) const {
		return this->get_min_idx(target_begin, target_end, 0, this->N, 1);
	}
};

int max_salary(const vector<int> &salaries, const Segtree& tree, const int begin, const int end) {
	if (end - begin <= 1) {
		return salaries[begin];
	}

	const int min_idx = tree.get_min_idx(begin, end);
	int result = salaries[min_idx] * (end - begin);
	result = max(result, max_salary(salaries, tree, begin, min_idx));

	if (min_idx != salaries.size() - 1) {
		result = max(result, max_salary(salaries, tree, min_idx + 1, end));
	}
	
	return result;
}

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> salaries(N);
	for (int& salary : salaries) {
		scanf("%d", &salary);
	}

	Segtree segtree(salaries);
	const int result = max_salary(salaries, segtree, 0, N);

	printf("%d\n", result);

	return 0;
}