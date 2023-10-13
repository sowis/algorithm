#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void) {
	unordered_map<char, unordered_map<char, char>> board;
	board['A']['A'] = 'A';
	board['A']['G'] = 'C';
	board['A']['C'] = 'A';
	board['A']['T'] = 'G';
	board['G']['A'] = 'C';
	board['G']['G'] = 'G';
	board['G']['C'] = 'T';
	board['G']['T'] = 'A';
	board['C']['A'] = 'A';
	board['C']['G'] = 'T';
	board['C']['C'] = 'C';
	board['C']['T'] = 'G';
	board['T']['A'] = 'G';
	board['T']['G'] = 'A';
	board['T']['C'] = 'G';
	board['T']['T'] = 'T';

	int N;
	cin >> N;

	string input;
	cin >> input;

	if (N == 1) {
		cout << input;
		return 0;
	}

	char cur = input[N - 1];
	for (int i = N - 2; i >= 0; --i) {
		cur = board[input[i]][cur];
	}

	cout << cur;

	return 0;
}