#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<string> decode_words{"000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010"};

int diff_count(const string& w1, const string& w2) {
	int result = 0;
	for (int i = 0; i < w1.size(); ++i) {
		if (w1[i] != w2[i]) {
			++result;
		}
	}

	return result;
}

char decode(const string& word) {
	for (int i = 0; i < decode_words.size(); ++i) {
		if (diff_count(decode_words[i], word) <= 1) {
			return 'A' + i;
		}
	}

	return -1;
}

int main(void) {
	int N;
	cin >> N;

	vector<string> words(N);
	for (string& word : words) {
		for (int i = 0; i < 6; ++i) {
			char c;
			cin >> c;
			word += c;
		}
	}

	string result;
	for (int i = 0; i < N; ++i) {
		const char decoded = decode(words[i]);
		if (decoded == -1) {
			cout << i + 1 << "\n";
			return 0;
		}

		result += decoded;
	}

	cout << result << "\n";

	return 0;
}