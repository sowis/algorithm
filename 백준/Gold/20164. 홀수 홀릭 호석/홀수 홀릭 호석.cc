#include <iostream>
#include <string>

using namespace std;

int min_result = 1987654321;
int max_result = -1987654321;

int odd_count(const string& num) {
	int result = 0;
	for (const char c : num) {
		if ((c - '0') % 2) {
			++result;
		}
	}

	return result;
}

string str_cut(const string& origin, const int begin, const int end) {
	string str;
	for (int i = begin; i < end; ++i) {
		str += origin[i];
	}

	return str;
}

void solve(const string& num, const int last_odd_count) {
	const int current_odd_count = odd_count(num) + last_odd_count;
	if (num.size() == 1) {
		max_result = max(max_result, current_odd_count);
		min_result = min(min_result, current_odd_count);
		return;
	}

	if (num.size() == 2) {
		solve(to_string(num[0] - '0' + num[1] - '0'), current_odd_count);
		return;
	}

	for (int left_cut = 1; left_cut < num.size() - 1; ++left_cut) {
		for (int right_cut = left_cut + 1; right_cut < num.size(); ++right_cut) {
			string left = str_cut(num, 0, left_cut);
			string mid = str_cut(num, left_cut, right_cut);
			string right = str_cut(num, right_cut, (int)num.size());
			
			const string next = to_string(stoi(left) + stoi(mid) + stoi(right));
			solve(next, current_odd_count);
		}
	}
}

int main(void) {
	string num;
	cin >> num;

	solve(num, 0);
	cout << min_result << " " << max_result;

	return 0;
}