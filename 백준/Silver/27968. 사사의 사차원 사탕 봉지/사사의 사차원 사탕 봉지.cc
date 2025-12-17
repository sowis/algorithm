#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<long long> candies(M);
	vector<long long> candy_psum;
	long long psum = 0;
	for (long long& candy : candies) {
		cin >> candy;
		psum += candy;
		candy_psum.push_back(psum);
	}

	for (int i = 0; i < N; ++i) {
		long long b;
		cin >> b;

		const int psum_idx = (int)(lower_bound(candy_psum.begin(), candy_psum.end(), b) - candy_psum.begin());
		if (psum_idx == M) {
			cout << "Go away!\n";
		}
		else {
			cout << psum_idx + 1 << "\n";
		}
	}


	return 0;
}