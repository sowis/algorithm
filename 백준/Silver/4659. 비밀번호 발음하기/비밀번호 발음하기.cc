#include <iostream>
#include <string>

using namespace std;

int main(void) {
	while (true) {
		string input;
		cin >> input;

		if (input == "end") {
			break;
		}

		bool acceptable = true;
		bool with_vowel = false;
		int last_vowel_count = 0;
		int last_consonant_count = 0;
		char last_char = -1;
		
		for (const char c : input) {
			if (c == last_char && c != 'e' && c != 'o') {
				acceptable = false;
				break;
			}

			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				if (last_vowel_count == 2) {
					acceptable = false;
					break;
				}

				with_vowel = true;

				if (last_consonant_count) {
					last_consonant_count = 0;
					last_vowel_count = 1;
				}
				else {
					++last_vowel_count;
				}
			}
			else {
				if (last_consonant_count == 2) {
					acceptable = false;
					break;
				}


				if (last_consonant_count) {
					++last_consonant_count;
				}
				else {
					last_consonant_count = 1;
					last_vowel_count = 0;
				}
			}

			last_char = c;
		}

		if (with_vowel == false) {
			acceptable = false;
		}

		if (acceptable) {
			cout << '<' << input << "> is acceptable.\n";
		}
		else {
			cout << '<' << input << "> is not acceptable.\n";
		}
	}

	return 0;
}