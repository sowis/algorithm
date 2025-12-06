#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

int N;
vector<int> S;
int K;
unordered_set<int> numbers;

bool id_valid_number(int num) {
	while (num > 0) {
		if (numbers.find(num % 10) == numbers.end()) {
			return false;
		}

		num /= 10;
	}

	return true;
}

int vector_to_number(const vector<int>& v) {
	int result = 0;
	for (int i = 0; i < v.size(); ++i) {
		result += v[v.size() - 1 - i] * (int)pow(10, i);
	}

	return result;
}

int number_digit(int num) {
	int result = 0;
	while (num > 0) {
		++result;
		num /= 10;
	}

	return result;
}

void create_number(vector<int> &created, vector<int> &number, const int idx) {
	if (idx == number.size()) {
		created.push_back(vector_to_number(number));
		return;
	}

	for (const int num : numbers) {
		number[idx] = num;
		create_number(created, number, idx + 1);
	}
}

bool case_validate(const int s1, const int s2) {
	for (int i = 0; i < S[1]; ++i) {
		const int line_digit = S[i + 2];
		const int mul = s1 * ((s2 / (int)pow(10, i)) % 10);
		if (number_digit(mul) != line_digit) {
			return false;
		}
		
		if (id_valid_number(mul) == false) {
			return false;
		}
	}

	const int mul = s1 * s2;
	const int line_digit = S[S.size() - 1];
	if (number_digit(mul) != line_digit) {
		return false;
	}

	if (id_valid_number(mul) == false) {
		return false;
	}

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	S = vector<int>(N);
	for (int& s : S) {
		cin >> s;
	}

	cin >> K;
	for (int i = 0; i < K; ++i) {
		int num;
		cin >> num;
		numbers.insert(num);
	}

	vector<int> s1s;
	vector<int> s1_number(S[0]);
	create_number(s1s, s1_number, 0);

	vector<int> s2s;
	vector<int> s2_number(S[1]);
	create_number(s2s, s2_number, 0);

	int result = 0;
	for (const int s1 : s1s) {
		for (const int s2 : s2s) {
			if (case_validate(s1, s2)) {
				++result;
			}
		}
	}

	cout << result;

	return 0;
}