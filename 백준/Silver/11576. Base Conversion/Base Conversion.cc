#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
	int A, B;
	cin >> A >> B;

	int M;
	cin >> M;

	vector<int> numbers_A(M);
	for (int& number : numbers_A) {
		cin >> number;
	}

	reverse(numbers_A.begin(), numbers_A.end());
	long long number_10 = 0;
	for (int i = 0; i < numbers_A.size(); ++i) {
		number_10 += numbers_A[i] * (long long)pow(A, i);
	}

	vector<int> result;
	for (int i = 0; number_10 > 0; ++i) {
		result.push_back(number_10 % B);
		number_10 /= B;
	}

	reverse(result.begin(), result.end());

	for (const int r : result) {
		cout << r << " ";
	}

	return 0;
}