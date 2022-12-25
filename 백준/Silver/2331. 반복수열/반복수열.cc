#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

int A, P;

int get_next(const int number) {
	const string str = to_string(number);
	int pow_sum = 0;
	for (const char c : str) {
		const int c_num = c - '0';
		pow_sum += (int)pow(c_num, P);
	}

	return pow_sum;
}

int main(void) {
	cin >> A >> P;

	unordered_map<int, int> numbers;
	numbers[A] = 1;

	int order = 2;
	int next_num = get_next(A);
	while (numbers.find(next_num) == numbers.end()) {
		numbers[next_num] = order;
		next_num = get_next(next_num);
		++order;
	}

	cout << numbers[next_num] - 1 << "\n";

	return 0;
}