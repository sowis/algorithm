#include <iostream>
#include <string>

using namespace std;

string ROT13(const string& s) {
	string result = s;
	for (char& c : result) {
		if ('a' <= c && c <= 'z') {
			c -= 'a';
			c += 13;
			c %= ('z' - 'a' + 1);
			c += 'a';
		}
		else if ('A' <= c && c <= 'Z') {
			c -= 'A';
			c += 13;
			c %= ('Z' - 'A' + 1);
			c += 'A';
		}
	}

	return result;
}

int main(void) {
	string input;

	getline(cin, input);
	cout << ROT13(input);

	return 0;
}