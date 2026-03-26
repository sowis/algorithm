#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int begins[] = { 0, 2, 4, 5, 7, 9, 11 };
constexpr bool keys[] = { true, false, true, false, true, true, false, true, false, true, false, true };
constexpr char alphas[] = { 'C', ' ', 'D', ' ', 'E', 'F', ' ', 'G', ' ', 'A', ' ', 'B' };

int N;
vector<int> score;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		int sc;
		cin >> sc;

		score.push_back(sc);
	}

	vector<pair<char, char>> results;
	for (int begin : begins) {
		bool valid = true;
		int cur = begin;
		for (int i = 0; i < N; ++i) {
			cur = (cur + score[i] + 24) % 12;
			if (keys[cur] == false) {
				valid = false;
				break;
			}
		}

		if (valid) {
			results.push_back({ alphas[begin], alphas[cur] });
		}
	}

	sort(results.begin(), results.end());

	for (const pair<char, char>& result : results) {
		cout << result.first << " " << result.second << "\n";
	}

	return 0;
}