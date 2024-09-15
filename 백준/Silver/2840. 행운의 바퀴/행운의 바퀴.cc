#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;

	vector<char> board(N, -1);
	int cur = 0;
	unordered_set<char> s;

	for (int i = 0; i < K; ++i) {
		int move;
		char c;

		cin >> move >> c;

		cur = (cur + move) % N;
		if (board[cur] != -1 && board[cur] != c) {
			cout << "!";
			return 0;
		}

		if (s.find(c) != s.end() && board[cur] != c) {
			cout << "!";
			return 0;
		}

		s.insert(c);
		board[cur] = c;
	}

	for (int i = cur; i >= 0; --i) {
		if (board[i] == -1) {
			cout << "?";
		}
		else {
			cout << board[i];
		}
	}

	for (int i = N - 1; i > cur; --i) {
		if (board[i] == -1) {
			cout << "?";
		}
		else {
			cout << board[i];
		}
	}

	return 0;
}