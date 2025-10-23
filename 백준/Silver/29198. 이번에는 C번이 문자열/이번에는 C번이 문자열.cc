#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;

	vector<string> strs;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;

		sort(str.begin(), str.end());
		strs.push_back(str);
	}

	sort(strs.begin(), strs.end());

	string result;
	for (int i = 0; i < K; ++i) {
		result += strs[i];
	}

	sort(result.begin(), result.end());

	cout << result;


	return 0;
}