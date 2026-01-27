#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	long long N, M;
	cin >> N >> M;

	vector<long long> arr(N);
	for (long long& num : arr) {
		cin >> num;
	}

	unordered_map<long long, long long> add_d_count;
	unordered_map<long long, long long> mul_d_count;

	for (long long i = 1; i < N; ++i) {
		++add_d_count[arr[i] - arr[i - 1]];

		if (arr[i] % arr[i - 1] == 0) {
			++mul_d_count[arr[i] / arr[i - 1]];
		}
	}

	while  (M--) {
		long long i, x;
		cin >> i >> x;

		--i;
		
		if (i != 0) {
			--add_d_count[arr[i] - arr[i - 1]];
			++add_d_count[x - arr[i - 1]];

			if (arr[i] % arr[i - 1] == 0) {
				--mul_d_count[arr[i] / arr[i - 1]];
			}
			
			if (x % arr[i - 1] == 0) {
				++mul_d_count[x / arr[i - 1]];
			}
		}
		
		if (i != N - 1) {
			--add_d_count[arr[i + 1] - arr[i]];
			++add_d_count[arr[i + 1] - x];

			if (arr[i + 1] % arr[i] == 0) {
				--mul_d_count[arr[i + 1] / arr[i]];
			}

			if (arr[i + 1] % x == 0) {
				++mul_d_count[arr[i + 1] / x];
			}
		}

		arr[i] = x;

		if (arr[1] - arr[0] > 0 && add_d_count[arr[1] - arr[0]] == N - 1) {
			cout << "+\n";
		}
		else if (arr[1] % arr[0] == 0 && mul_d_count[arr[1] / arr[0]] == N - 1) {
			cout << "*\n";
		}
		else {
			cout << "?\n";
		}
	}

	return 0;
}