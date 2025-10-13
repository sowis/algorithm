#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<pair<string, string>, string> dictionary;

int main(void) {
	ios_base::sync_with_stdio;
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string word;
		cin >> word;

		string sorted_word = word;
		sort(sorted_word.begin(), sorted_word.end());
		string key;
		key += word[0];
		key += word[word.size() - 1];
		dictionary[{key, sorted_word}] = word;
	}

	int S;
	cin >> S;

	for (int i = 0; i < S; ++i) {
		string word;
		cin >> word;

		string sorted_word = word;
		sort(sorted_word.begin(), sorted_word.end());
		string key;
		key += word[0];
		key += word[word.size() - 1];
		cout << dictionary[{key, sorted_word}] << " ";
	}

	return 0;
}