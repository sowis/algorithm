#include <cstdio>
#include <vector>

using namespace std;

class Segtree {
private:
	int N;
	vector<int> arr;

	void insert(const int num, const int begin, const int end, const int idx) {
		if (num < begin || end <= num) {
			return;
		}

		++arr[idx];

		if (end - begin == 1) {
			return;
		}

		const int mid = (begin + end) / 2;
		this->insert(num, begin, mid, idx * 2);
		this->insert(num, mid, end, idx * 2 + 1);
	}

	int get(const int target_begin, const int target_end, const int begin, const int end, const int idx) const {
		if (target_end <= begin || end <= target_begin) {
			return 0;
		}

		if (target_begin <= begin && end <= target_end) {
			return this->arr[idx];
		}

		const int mid = (begin + end) / 2;
		return this->get(target_begin, target_end, begin, mid, idx * 2) 
			+ this->get(target_begin, target_end, mid, end, idx * 2 + 1);
	}

public:
	Segtree(const int N)
		:N(N + 1), arr(vector<int>(N * 4, 0)) {}

	void insert(const int num) {
		this->insert(num, 0, this->N, 1);
	}

	int get(const int target_begin, const int target_end) const {
		return this->get(target_begin, target_end, 0, this->N, 1);
	}
};

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> numbers(N);
	for (int& n : numbers) {
		scanf("%d", &n);
	}

	Segtree segtree(N);

	long long reverse_count = 0;
	for (const int num : numbers) {
		reverse_count += segtree.get(num, N + 1);
		segtree.insert(num);
	}

	printf("%lld\n", reverse_count);

	return 0;
}