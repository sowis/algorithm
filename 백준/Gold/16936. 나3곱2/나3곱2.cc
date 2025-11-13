#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	long long num;
	long long two_count;
	long long three_count;

	bool operator< (const struct _data& d) const {
		if (this->three_count == d.three_count) {
			return this->two_count < d.two_count;
		}

		return this->three_count > d.three_count;
	}
} Data;

Data number_analyze(const long long num) {
	long long n = num;
	int two_count = 0;
	while (true) {
		if (n % 2) {
			break;
		}

		++two_count;
		n /= 2;
	}

	int three_count = 0;
	while (true) {
		if (n % 3) {
			break;
		}

		++three_count;
		n /= 3;
	}

	return { num, two_count, three_count };
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<Data> arr;
	for (int i = 0; i < N; ++i) {
		long long num;
		cin >> num;

		arr.push_back(number_analyze(num));
	}

	sort(arr.begin(), arr.end());

	for (const Data& d : arr) {
		cout << d.num << " ";
	}

	return 0;
}