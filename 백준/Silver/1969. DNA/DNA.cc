#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int hamming_distance(const string& dna_1, const string& dna_2) {
	int result = 0;
	if (dna_1.size() != dna_2.size()) {
		return -1;
	}

	for (int i = 0; i < dna_1.size(); ++i) {
		if (dna_1[i] != dna_2[i]) {
			++result;
		}
	}

	return result;
}

int main(void) {
	int N, M;
	cin >> N >> M;

	vector<string> dnas(N);
	for (string& dna : dnas) {
		cin >> dna;
	}

	vector<vector<int>> dna_counts(M, vector<int>(26, 0));
	string result;
	for (int i = 0; i < M; ++i) {
		for (int k = 0; k < N; ++k) {
			++dna_counts[i][dnas[k][i] - 'A'];
		}

		int max_count = -1;
		char target = 'A';
		for (int k = 0; k < 26; ++k) {
			if (dna_counts[i][k] > max_count) {
				max_count = dna_counts[i][k];
				target = k + 'A';
			}
		}

		result += target;
	}

	int distance_sum = 0;
	for (const string& dna : dnas) {
		distance_sum += hamming_distance(result, dna);
	}

	cout << result << "\n";
	cout << distance_sum << "\n";

	return 0;
}