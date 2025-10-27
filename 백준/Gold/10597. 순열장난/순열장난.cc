#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solve(const int N, const string& str, const int idx, vector<int>& result, vector<bool>& visit) {
	if (idx >= str.size()) { // 다 찾았는지 체크
		for (int i = 1; i <= N; ++i) {
			if (visit[i] == false) {
				return false;
			}
		}

		for (const int num : result) { // 다 찾았으면 결과 표시
			cout << num << " ";
		}

		return true;
	}

	/* 두 자리 숫자로 보는 경우 */
	if (idx + 1 < str.size()) {
		string str_s;
		str_s = str_s + str[idx] + str[idx + 1];
		const int num = stoi(str_s);

		if (num <= N && visit[num] == false) {
			visit[num] = true;
			result.push_back(num);

			if (solve(N, str, idx + 2, result, visit)) {
				return true;
			}

			result.pop_back();
			visit[num] = false;
		}
	}
	/*****************************/

	/* 한자리 숫자로 보는 경우 */
	string str_s;
	str_s = str_s + str[idx];
	const int num = stoi(str_s);

	if (visit[num] == false) {
		visit[num] = true;
		result.push_back(num);

		if (solve(N, str, idx + 1, result, visit)) {
			return true;
		}

		result.pop_back();
		visit[num] = false;
	}
	/*************************/

	return false;
}

int main(void) {
	string str;
	cin >> str;

	const int N = (str.size() < 10) ? (int)str.size() : ((int)str.size() + 9) / 2;

	vector<bool> visit(N + 1, false);
	vector<int> result;

	solve(N, str, 0, result, visit);

	return 0;
}