#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

double s(const vector<int>& numbers, const int begin, const int end) {
	double cur_sum = 0;
	for (int i = begin; i < end; ++i) {
		cur_sum += numbers[i];
	}

	const double avg = cur_sum / (end - begin);
	double pow_sum = 0;
	for (int i = begin; i < end; ++i) {
		pow_sum += pow((numbers[i] - avg), 2);
	}

	return sqrt(pow_sum / (end - begin));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<int> numbers(N);
	for (int& num : numbers) {
		cin >> num;
	}

	double result = numeric_limits<double>::max();
	for (int begin = 0; begin <= N - K; ++begin) {
		for (int end = begin + K; end <= N; ++end) {
			result = min(result, s(numbers, begin, end));
		}
	}

	cout.fixed;
	cout.precision(10);
	cout << result;

	return 0;
}