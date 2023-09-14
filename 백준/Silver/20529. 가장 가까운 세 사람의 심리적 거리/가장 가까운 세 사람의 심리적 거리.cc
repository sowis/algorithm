#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

int get_diff(const string& s1, const string& s2) {
	int result = 0;
	for (int i = 0; i < 4; ++i) {
		if (s1[i] != s2[i]) {
			++result;
		}
	}

	return result;
}

void test_case(void) {
	int N;
	cin >> N;

	unordered_map<string, int> mbti_set;
	for (int i = 0; i < N; ++i) {
		string mbti;
		cin >> mbti;
		
		++mbti_set[mbti];
	}

	vector<string> mbtis;
	vector<string> two_mbtis;
	for (const pair<string, int>& mbti : mbti_set) {
		mbtis.push_back(mbti.first);

		if (mbti.second >= 3) {
			cout << "0\n";
			return;
		}

		if (mbti.second == 2) {
			two_mbtis.push_back(mbti.first);
		}
	}

	if (mbtis.size() == 1) {
		cout << "0\n";
		return;
	}

	if (mbtis.size() == 2) {
		cout << 2 * get_diff(mbtis[0], mbtis[1]) << "\n";
		return;
	}
	
	int result = 987654321;
	for (int a = 0; a < mbtis.size() - 2; ++a) {
		for (int b = a + 1; b < mbtis.size() - 1; ++b) {
			for (int c = b + 1; c < mbtis.size(); ++c) {
				result = min(result, get_diff(mbtis[a], mbtis[b]) + get_diff(mbtis[b], mbtis[c]) + get_diff(mbtis[a], mbtis[c]));
			}
		}
	}

	for (const string& mbti : two_mbtis) {
		for (const string& another : mbtis) {
			if (mbti == another) {
				continue;
			}

			result = min(result, 2 * get_diff(mbti, another));
		}
	}

	cout << result << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}