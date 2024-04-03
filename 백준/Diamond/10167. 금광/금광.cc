#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Segtree {
private:
	int N;
	vector<long long> sum;
	vector<long long> left_max;
	vector<long long> right_max;
	vector<long long> total_max;

	void insert(const int target, const long long value, const int begin, const int end, const int idx) {
		if (target < begin || end <= target) {
			return;
		}

		if (end - begin == 1) {
			this->sum[idx] += value;
			this->left_max[idx] += value;
			this->right_max[idx] += value;
			this->total_max[idx] = max(0LL, this->sum[idx]);
			return;
		}

		const int mid = (begin + end) / 2;
		this->insert(target, value, begin, mid, idx * 2);
		this->insert(target, value, mid, end, idx * 2 + 1);

		this->sum[idx] = this->sum[idx * 2] + this->sum[idx * 2 + 1];
		this->left_max[idx] = max(this->left_max[idx * 2], this->sum[idx * 2] + this->left_max[idx * 2 + 1]);
		this->right_max[idx] = max(this->right_max[idx * 2 + 1], this->right_max[idx * 2] + this->sum[idx * 2 + 1]);
		this->total_max[idx] = max(this->total_max[idx * 2], this->total_max[idx * 2 + 1]);
		this->total_max[idx] = max(this->total_max[idx], this->right_max[idx * 2] + this->left_max[idx * 2 + 1]);
	}

public:
	Segtree(const int max_value) 
		: N(max_value) {
		this->sum = vector<long long>(this->N * 4, 0);
		this->left_max = vector<long long>(this->N * 4, 0);
		this->right_max = vector<long long>(this->N * 4, 0);
		this->total_max = vector<long long>(this->N * 4, 0);
	}

	void insert(const int target, const long long value) {
		this->insert(target, value, 0, this->N, 1);
	}

	long long get_max(void) const {
		return this->total_max[1];
	}
};

vector<int> compress(const vector<int>& v) {
	vector<int> result(v.size());
	vector<pair<int, int>> arr;
	for (int i = 0; i < v.size(); ++i) {
		arr.push_back({ v[i], i });
	}

	sort(arr.begin(), arr.end());

	int compressed = -1;
	int last = -1;
	for (const pair<int, int>& p : arr) {		
		if (p.first != last) {
			++compressed;
			last = p.first;
		}

		result[p.second] = compressed;
	}

	return result;
}

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> origin_y, origin_x;
	vector<long long> weights;
	for (int i = 0; i < N; ++i) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);

		origin_y.push_back(y);
		origin_x.push_back(x);
		weights.push_back(w);
	}

	const vector<int> compressed_y = compress(origin_y);
	const vector<int> compressed_x = compress(origin_x);

	const int compressed_y_max = *max_element(compressed_y.begin(), compressed_y.end());
	const int compressed_x_max = *max_element(compressed_x.begin(), compressed_x.end());
	const int compressed_x_min = *min_element(compressed_x.begin(), compressed_x.end());

	vector<vector<pair<int, long long>>> plane(compressed_x_max + 1);
	for (int i = 0; i < N; ++i) {
		plane[compressed_x[i]].push_back({ compressed_y[i], weights[i] });
	}

	long long result = 0;
	for (int x_begin = compressed_x_min; x_begin <= compressed_x_max; ++x_begin) {
		Segtree segtree(compressed_y_max + 1);
		for (int x_end = x_begin; x_end <= compressed_x_max; ++x_end) {
			for (const pair<int, long long>& p : plane[x_end]) {
				segtree.insert(p.first, p.second);
			}

			result = max(result, segtree.get_max());
		}
	}

	printf("%lld\n", result);

	return 0;
}