#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Data {
private:
	vector<int> numbers;
	Data* left;
	Data* right;

public:
	Data(const int begin, const int end, const vector<int>& arr) {
		this->numbers = vector<int>(end - begin);

		if (begin + 1 == end) {
			this->left = nullptr;
			this->right = nullptr;
			this->numbers[0] = arr[begin];
			return;
		}

		const int mid = (begin + end) / 2;
		this->left = new Data(begin, mid, arr);
		this->right = new Data(mid, end, arr);

		const vector<int>& left_numbers = this->left->get_numbers();
		const vector<int>& right_numbers = this->right->get_numbers();
		merge(left_numbers.begin(), left_numbers.end(), right_numbers.begin(), right_numbers.end(), this->numbers.begin());
	}

	~Data() {
		delete this->left;
		delete this->right;
	}

	const vector<int>& get_numbers(void) const {
		return this->numbers;
	}

	int count(const int target_begin, const int target_end, const int target, const int begin, const int end) const {
		if (end <= target_begin || target_end <= begin) {
			return 0;
		}

		if (target_begin <= begin && end <= target_end) {
			return this->numbers.end() - upper_bound(this->numbers.begin(), this->numbers.end(), target);
		}

		const int mid = (begin + end) / 2;
		const int result = this->left->count(target_begin, target_end, target, begin, mid) +
							this->right->count(target_begin, target_end, target, mid, end);

		return result;
	}
};

int main(void) {
	int N;
	scanf("%d", &N);
	
	vector<int> arr(N);
	for (int& num : arr) {
		scanf("%d", &num);
	}

	Data merge_sort_tree(0, N, arr);

	int M;
	scanf("%d", &M);

	for (int a = 0; a < M; ++a) {
		int i, k, j;
		scanf("%d%d%d", &i, &k, &j);

		const int result = merge_sort_tree.count(i - 1, k, j, 0, N);
		printf("%d\n", result);
	}

	return 0;
}