#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Segtree {
private:
	const static int N = 1000001;
	vector<int> max_value;
	vector<int> counts;

	void insert(const int target, const int begin, const int end, const int idx) {
		if (target < begin || end <= target) {
			return;
		}

		if (end - begin == 1) {
			++this->counts[idx];
			this->max_value[idx] = target;
			return;
		}

		const int mid = (begin + end) / 2;
		this->insert(target, begin, mid, idx * 2);
		this->insert(target, mid, end, idx * 2 + 1);
		this->max_value[idx] = max(this->max_value[idx * 2], this->max_value[idx * 2 + 1]);
	}

	void remove(const int target, const int begin, const int end, const int idx) {
		if (target < begin || end <= target) {
			return;
		}

		if (end - begin == 1) {
			--this->counts[idx];

			if (this->counts[idx] == 0) {
				this->max_value[idx] = 0;
			}

			return;
		}

		const int mid = (begin + end) / 2;
		this->remove(target, begin, mid, idx * 2);
		this->remove(target, mid, end, idx * 2 + 1);
		this->max_value[idx] = max(this->max_value[idx * 2], this->max_value[idx * 2 + 1]);
	}

public:
	Segtree(void)
		:max_value(vector<int>(this->N * 4, 0)), counts(vector<int>(this->N * 4, 0)) {}

	void insert(const int target) {
		this->insert(target, 0, this->N, 1);
	}

	void remove(const int target) {
		this->remove(target, 0, this->N, 1);
	}

	int get_max(void) {
		return this->max_value[1];
	}
};

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> lights(N);
	for (int& light : lights) {
		scanf("%d", &light);
	}

	Segtree segtree;
	for (int i = 0; i < 2 * (M - 1); ++i) {
		segtree.insert(lights[i]);
	}

	for (int i = 2 * (M - 1); i < N; ++i) {
		segtree.insert(lights[i]);
		printf("%d ", segtree.get_max());
		segtree.remove(lights[i - 2 * (M - 1)]);
	}

	return 0;
}