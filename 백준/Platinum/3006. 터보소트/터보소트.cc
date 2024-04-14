#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	int value;
	int index;

	bool operator< (const struct _data& d) const {
		return this->value < d.value;
	}
} Data;

class Segtree {
private:
	int N;
	vector<int> arr;
	
	void init(const int begin, const int end, const int idx) {
		if (end - begin == 1) {
			this->arr[idx] = 1;
			return;
		}

		const int mid = (begin + end) / 2;
		this->init(begin, mid, idx * 2);
		this->init(mid, end, idx * 2 + 1);
		this->arr[idx] = this->arr[idx * 2] + this->arr[idx * 2 + 1];
	}

	void update(const int target, const int add, const int begin, const int end, const int idx) {
		if (target < begin || end <= target) {
			return;
		}

		this->arr[idx] += add;

		if (end - begin == 1) {
			return;
		}

		const int mid = (begin + end) / 2;
		this->update(target, add, begin, mid, idx * 2);
		this->update(target, add, mid, end, idx * 2 + 1);
		this->arr[idx] = this->arr[idx * 2] + this->arr[idx * 2 + 1];
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
		this->init(0, this->N, 1);
	}

	void update(const int target, const int add) {
		this->update(target, add, 0, this->N, 1);
	}

	int get(const int target_begin, const int target_end) const {
		return this->get(target_begin, target_end, 0, this->N, 1);
	}
};

int main(void) {
	int N;
	scanf("%d", &N);

	vector<Data> sorted(N);
	vector<int> origin(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &sorted[i].value);
		--sorted[i].value;
		sorted[i].index = i;
		origin[i] = sorted[i].value;
	}

	sort(sorted.begin(), sorted.end());
	vector<int> finder(N);
	for (int i = 0; i < N; ++i) {
		finder[sorted[i].value] = sorted[i].index;
	}

	Segtree segtree(origin);
	
	bool upper = true;
	int left = 0;
	int right = N - 1;
	while (left <= right) {
		if (upper) {
			const int result = segtree.get(0, finder[left]);
			segtree.update(finder[left], -1);
			++left;
			printf("%d\n", result);
		}
		else {
			const int result = segtree.get(finder[right] + 1, N);
			segtree.update(finder[right], -1);
			--right;
			printf("%d\n", result);
		}

		upper = !upper;
	}

	return 0;
}