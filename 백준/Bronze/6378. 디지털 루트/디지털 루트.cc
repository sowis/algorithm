#include <iostream>
#include <string>

using namespace std;

string num_add(const string &num) {
	int result = 0;
	for (const char c : num) {
		result += c - '0';
	}

	return to_string(result);
}

int main(void) {
	while (true) {
		string N;
		cin >> N;

		if (N == "0") {
			break;
		}

		while (N.size() != 1) {
			N = num_add(N);
		}

		cout << N << "\n";
	}

	return 0;
}