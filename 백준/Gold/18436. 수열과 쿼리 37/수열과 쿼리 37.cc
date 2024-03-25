#include <cstdio>
#include <vector>

using namespace std;

class Segtree {
private:
	constexpr static int EVEN = 0;
	constexpr static int ODD = 1;

	int N;
	vector<int> counts[2];

	void init(const vector<int>& origin, const int begin, const int end, const int idx) {
		if (end - begin == 1) {
			++this->counts[origin[begin] % 2][idx];
			return;
		}

		const int mid = (begin + end) / 2;
		init(origin, begin, mid, idx * 2);
		init(origin, mid, end, idx * 2 + 1);
		for (int i = 0; i < 2; ++i) {
			this->counts[i][idx] = this->counts[i][idx * 2] + this->counts[i][idx * 2 + 1];
		}
	}

	void update(const int target, const int value, const int begin, const int end, const int idx) {
		if (target < begin || end <= target) {
			return;
		}

		if (end - begin == 1) {
			for (int i = 0; i < 2; ++i) {
				this->counts[i][idx] = 0;
			}

			++this->counts[value % 2][idx];
			return;
		}

		const int mid = (begin + end) / 2;
		update(target, value, begin, mid, idx * 2);
		update(target, value, mid, end, idx * 2 + 1);
		for (int i = 0; i < 2; ++i) {
			this->counts[i][idx] = this->counts[i][idx * 2] + this->counts[i][idx * 2 + 1];
		}
	}

	int get(const int odd, const int target_begin, const int target_end, const int begin, const int end, const int idx) const {
		if (target_end <= begin || end <= target_begin) {
			return 0;
		}

		if (target_begin <= begin && end <= target_end) {
			return this->counts[odd][idx];
		}

		const int mid = (begin + end) / 2;
		return this->get(odd, target_begin, target_end, begin, mid, idx * 2) + this->get(odd, target_begin, target_end, mid, end, idx * 2 + 1);
	}

public:
	Segtree(const vector<int> &origin)
		:N((int)origin.size()) {
		for (int i = 0; i < 2; ++i) {
			this->counts[i] = vector<int>(this->N * 4);
		}

		this->init(origin, 0, this->N, 1);
	}

	void update(const int i, const int x) {
		this->update(i - 1, x, 0, N, 1);
	}

	int get(const int l, const int r, const bool odd) const {
		return this->get(odd ? 1 : 0, l - 1, r, 0, N, 1);
	}
};

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> A(N);
	for (int& num : A) {
		scanf("%d", &num);
	}

	Segtree segtree(A);

	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; ++i) {
		int op, a, b;
		scanf("%d%d%d", &op, &a, &b);

		if (op == 1) {
			segtree.update(a, b);
		}
		else {
			printf("%d\n", segtree.get(a, b, op == 3));
		}
	}

	return 0;
}