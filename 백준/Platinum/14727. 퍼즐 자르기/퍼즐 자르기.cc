#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Segtree {
private:
	int N;
	vector<long long> origin;
	vector<int> min_idx;

	void init(const int begin, const int end, const int idx) {
		if (end - begin == 1) {
			this->min_idx[idx] = begin;
			return;
		}

		const int mid = (begin + end) / 2;
		this->init(begin, mid, idx * 2);
		this->init(mid, end, idx * 2 + 1);
		this->min_idx[idx] = (this->origin[this->min_idx[idx * 2]] < this->origin[this->min_idx[idx * 2 + 1]]) ? this->min_idx[idx * 2] : this->min_idx[idx * 2 + 1];
	}

	int get_min_idx(const int target_begin, const int target_end, const int begin, const int end, const int idx) const {
		if (target_end <= begin || end <= target_begin) {
			return -1;
		}

		if (target_begin <= begin && end <= target_end) {
			return this->min_idx[idx];
		}

		const int mid = (begin + end) / 2;
		const int left_min_idx = this->get_min_idx(target_begin, target_end, begin, mid, idx * 2);
		const int right_min_idx = this->get_min_idx(target_begin, target_end, mid, end, idx * 2 + 1);
		if (left_min_idx == -1) {
			return right_min_idx;
		}
		else if (right_min_idx == -1) {
			return left_min_idx;
		}
		else {
			return (this->origin[left_min_idx] < this->origin[right_min_idx]) ? left_min_idx : right_min_idx;
		}
	}
	
public:
	Segtree(const vector<long long>& origin)
		:N((int)origin.size()) {
		this->origin = origin;
		this->min_idx = vector<int>(this->N * 4);
		this->init(0, this->N, 1);
	}

	int get_min_idx(const int target_begin, const int target_end) const {
		return this->get_min_idx(target_begin, target_end, 0, this->N, 1);
	}
};

long long divide_and_quanquer(const Segtree &segtree, const vector<long long> &heights, const int begin, const int end) {
	if (end - begin == 1) {
		return heights[segtree.get_min_idx(begin, end)];
	}

	const int min_idx = segtree.get_min_idx(begin, end);
	long long result = heights[min_idx] * (end - begin);
	if (min_idx != begin) {
		result = max(result, divide_and_quanquer(segtree, heights, begin, min_idx));
	}

	if (min_idx != end - 1) {
		result = max(result, divide_and_quanquer(segtree, heights, min_idx + 1, end));
	}

	return result;
}

int main(void) {
	int N;
	scanf("%d", &N);

	vector<long long> heights(N);
	for (long long& height : heights) {
		scanf("%lld", &height);
	}

	Segtree segtree(heights);
	const long long result = divide_and_quanquer(segtree, heights, 0, N);

	printf("%lld\n", result);

	return 0;
}