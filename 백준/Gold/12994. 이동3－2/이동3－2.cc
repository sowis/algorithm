#include <iostream>
#include <vector>

using namespace std;

vector<int> num_to_base3_reverse(long long num) {
	long long n = abs(num);
	vector<int> result;
	while (n > 0) {
		result.push_back(n % 3);
		n /= 3;
	}

	return result;
}

vector<int> base_3_reverse_to_add(vector<int>& base_3_reverse) {
	vector<int> result;
	for (int i = 0; i < base_3_reverse.size(); ++i) {
		const int next_add = base_3_reverse[i] / 3;
		base_3_reverse[i] %= 3;

		if (next_add > 0) {
			if (i == base_3_reverse.size() - 1) {
				base_3_reverse.push_back(next_add);
			}
			else {
				base_3_reverse[i + 1] += next_add;
			}
		}

		if (base_3_reverse[i] < 2) {
			result.push_back(base_3_reverse[i]);
		}
		else if (base_3_reverse[i] == 2) {
			result.push_back(1); // 뺀것
			
			if (i == base_3_reverse.size() - 1) {
				base_3_reverse.push_back(1);
			}
			else {
				++base_3_reverse[i + 1];
			}
		}
	}

	return result;
}

int main(void) {
	long long x, y;
	cin >> x >> y;

	vector<int> base_3_x = num_to_base3_reverse(x);
	vector<int> is_add_x = base_3_reverse_to_add(base_3_x);

	vector<int> base_3_y = num_to_base3_reverse(y);
	vector<int> is_add_y = base_3_reverse_to_add(base_3_y);

	if (is_add_x.size() < is_add_y.size()) {
		swap(is_add_x, is_add_y);
	}

	for (int i = 0; i < is_add_x.size(); ++i) {
		const int left = is_add_x[i];
		const int right = (is_add_y.size() <= i) ? 0 : is_add_y[i];

		if (left + right != 1) {
			cout << 0;
			return 0;
		}
	}

	cout << 1;

	return 0;
}