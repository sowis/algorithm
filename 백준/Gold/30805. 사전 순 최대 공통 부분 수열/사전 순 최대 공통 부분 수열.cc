#include <iostream>
#include <vector>

using namespace std;

vector<int> number_begin(const vector<int>& arr, const int begin) {
	vector<int> result(101, -1);
	for (int i = begin; i < arr.size(); ++i) {
		if (result[arr[i]] != -1) {
			continue;
		}

		result[arr[i]] = i;
	}

	return result;
}

int main(void) {
	int N;
	cin >> N;

	vector<int> A(N);
	for (int& a : A) {
		cin >> a;
	}

	int M;
	cin >> M;

	vector<int> B(M);
	for (int& b : B) {
		cin >> b;
	}

	vector<int> result;
	int a_idx = 0;
	int b_idx = 0;

	while (a_idx < N && b_idx < M) {
		const vector<int> a_numbers = number_begin(A, a_idx);
		const vector<int> b_numbers = number_begin(B, b_idx);

		int target = -1;
		for (int i = 100; i >= 0; --i) {
			if (a_numbers[i] == -1) {
				continue;
			}

			if (b_numbers[i] == -1) {
				continue;
			}

			target = i;
			a_idx = a_numbers[i] + 1;
			b_idx = b_numbers[i] + 1;
			break;
		}

		if (target == -1) {
			break;
		}

		result.push_back(target);
	}

	cout << result.size() << "\n";

	if (result.size() != 0) {
		for (const int r : result) {
			cout << r << " ";
		}
	}

	return 0;
}