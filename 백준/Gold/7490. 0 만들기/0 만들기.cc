#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

constexpr int PLUS = -1;
constexpr int MINUS = -2;
constexpr int GLUE = -3;

vector<string> results;

string line_to_str(const vector<int>& line) {
	string result;
	for (const int token : line) {
		if (token == PLUS) {
			result += '+';
		}
		else if (token == MINUS) {
			result += '-';
		}
		else if (token == GLUE) {
			result += ' ';
		}
		else {
			result += (token + '0');
		}
	}

	return result;
}

void brute_force(vector<int>& line, const int N, const int cur = 1, const int calc = 0, const int last_op = PLUS, const int glued = 1) {
	if (line.empty()) {
		line.push_back(cur);
		brute_force(line, N, cur + 1, 1, PLUS, 1);
		line.pop_back();
		return;
	}

	if (cur > N) {
		if (calc != 0) {
			return;
		}

		const string str_line = line_to_str(line);
		results.push_back(str_line);
		return;
	}

	line.push_back(PLUS);
	line.push_back(cur);
	brute_force(line, N, cur + 1, calc + cur, PLUS, cur);

	line[line.size() - 2] = MINUS;
	brute_force(line, N, cur + 1, calc - cur, MINUS, cur);

	line[line.size() - 2] = GLUE;
	if (last_op == PLUS) {
		brute_force(line, N, cur + 1, (calc - glued) + (glued * 10 + cur), last_op, glued * 10 + cur);
	}
	else if (last_op == MINUS) {
		brute_force(line, N, cur + 1, (calc + glued) - (glued * 10 + cur), last_op, glued * 10 + cur);
	}

	line.pop_back();
	line.pop_back();
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		int N;
		cin >> N;

		results.clear();
		vector<int> line;
		brute_force(line, N);
		sort(results.begin(), results.end());

		for (const string& str : results) {
			cout << str << "\n";
		}

		cout << "\n";
	}

	return 0;
}