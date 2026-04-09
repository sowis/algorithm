#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int sqrt_n;
vector<int> A;
vector<int> sorted_A;
vector<pair<int, int>> bucked_range;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	A = vector<int>(N);
	for (int& a : A) {
		cin >> a;
		sorted_A.push_back(a);
	}

	bucked_range = vector<pair<int, int>>(N);
	sqrt_n = (int)sqrt(N);
	for (int begin = 0, end = sqrt_n; begin < N; begin += sqrt_n, end = min(end + sqrt_n, N)) {
		sort(&sorted_A[begin], &sorted_A[end - 1] + 1);
		for (int i = begin; i < end; ++i) {
			bucked_range[i] = { begin, end };
		}
	}

	int M;
	cin >> M;

	while (M--) {
		int op;
		cin >> op;

		if (op == 1) {
			int i, v;
			cin >> i >> v;
			--i;

			const int begin = bucked_range[i].first;
			const int end = bucked_range[i].second;
			int sorted_idx = (int)(find(&sorted_A[begin], &sorted_A[end - 1] + 1, A[i]) - &sorted_A[0]);

			A[i] = v;
			sorted_A[sorted_idx] = v;
			
			while (sorted_idx < (end - 1) && sorted_A[sorted_idx] > sorted_A[sorted_idx + 1]) {
				swap(sorted_A[sorted_idx], sorted_A[sorted_idx + 1]);
				++sorted_idx;
			}

			while (sorted_idx > begin && sorted_A[sorted_idx] < sorted_A[sorted_idx - 1]) {
				swap(sorted_A[sorted_idx], sorted_A[sorted_idx - 1]);
				--sorted_idx;
			}
		}
		else if (op == 2) {
			int i, j, k;
			cin >> i >> j >> k;
			--i;

			int begin = i;
			int end = min(bucked_range[i].second, j);
			int result = 0;

			while (begin < j) {
				if (end - begin < sqrt_n) { // 양 끝단 작은 버킷일때
					for (int cur = begin; cur < end; ++cur) { // 직접 세기
						if (k < A[cur]) {
							++result;
						}
					}
				}
				else { // 중간 버킷일떄
					const int current_bucket_size = end - begin;
					result += current_bucket_size - ((int)(upper_bound(&sorted_A[begin], &sorted_A[end], k) - &sorted_A[begin])); // 이분탐색으로 세기
				}

				begin = end;
				end = min(min(end + sqrt_n, N), j);
			}

			cout << result << "\n";
		}
	}


	return 0;
}