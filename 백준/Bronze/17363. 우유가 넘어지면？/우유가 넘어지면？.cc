#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	unordered_map<char, char> change;
	change['.'] = '.';
	change['O'] = 'O';
	change['-'] = '|';
	change['|'] = '-';
	change['/'] = '\\';
	change['\\'] = '/';
	change['^'] = '<';
	change['<'] = 'v';
	change['v'] = '>';
	change['>'] = '^';

	int N, M;
	cin >> N >> M;

	vector<vector<char>> original(N, vector<char>(M));
	vector<vector<char>> result(M, vector<char>(N));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> original[y][x];
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			result[M - 1 - x][y] = change[original[y][x]];
		}
	}

	for (int y = 0; y < M; ++y) {
		for (int x = 0; x < N; ++x) {
			cout << result[y][x];
		}

		cout << "\n";
	}

	return 0;
}