#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
private:
	vector<int> v;
	Node* left;
	Node* right;

public:
	Node(const int begin, const int end, const vector<int>& arr) 
		:left(nullptr), right(nullptr) {
		this->v = vector<int>(end - begin);
		if (end - begin == 1) {
			v[0] = arr[begin];
			return;
		}

		const int mid = (begin + end) / 2;
		this->left = new Node(begin, mid, arr);
		this->right = new Node(mid, end, arr);

		merge(this->left->v.begin(), this->left->v.end(), this->right->v.begin(), this->right->v.end(), this->v.begin());
	}

	~Node(void) {
		if (this->left != nullptr) {
			delete this->left;
		}

		if (this->right != nullptr) {
			delete this->right;
		}
	}

	int search(const int target_begin, const int target_end, const int bigger, const int begin, const int end) const {
		if (end <= target_begin || target_end <= begin) {
			return 0;
		}

		if (target_begin <= begin && end <= target_end) {
			return this->v.end() - upper_bound(this->v.begin(), this->v.end(), bigger);
		}

		const int mid = (begin + end) / 2;
		return this->left->search(target_begin, target_end, bigger, begin, mid)
			+ this->right->search(target_begin, target_end, bigger, mid, end);
	}
};

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> arr(N);
	for (int& number : arr) {
		scanf("%d", &number);
	}

	Node merge_sort_tree(0, N, arr);

	int M;
	scanf("%d", &M);

	unsigned int last_ans = 0;
	for (int t = 0; t < M; ++t) {
		unsigned int a, b, c;
		scanf("%u%u%u", &a, &b, &c);

		const int target_begin = (a ^ last_ans) - 1;
		const int target_end = b ^ last_ans;
		const int bigger = c ^ last_ans;
		
		const int result = merge_sort_tree.search(target_begin, target_end, bigger, 0, N);
		printf("%d\n", result);
		last_ans = result;
	}

	return 0;
}