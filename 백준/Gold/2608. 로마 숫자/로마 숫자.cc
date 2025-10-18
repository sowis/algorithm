#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

unordered_map<char, int> rom_to_arab;
vector<pair<int, string>> arab_to_rom;

int rtoa(const string& str) {
	int result = 0;

	for (int i = 0; i < str.size(); ++i) {
		if (i + 1 < str.size() && rom_to_arab[str[i]] < rom_to_arab[str[i + 1]]) {
			result += rom_to_arab[str[i + 1]] - rom_to_arab[str[i]];
			++i;
		}
		else {
			result += rom_to_arab[str[i]];
		}
	}

	return result;
}

string ator(int num) {
	string result;
	for (int i = 0; i < arab_to_rom.size(); ++i) {
		if (arab_to_rom[i].second.size() == 1) {
			const int count = min(num / arab_to_rom[i].first, 3);
			num -= count * arab_to_rom[i].first;

			for (int k = 0; k < count; ++k) {
				result += arab_to_rom[i].second;
			}
		}
		else {
			const int count = min(num / arab_to_rom[i].first, 1);
			num -= count * arab_to_rom[i].first;

			for (int k = 0; k < count; ++k) {
				result += arab_to_rom[i].second;
			}
		}
	}

	return result;
}

int main(void) {
	rom_to_arab['I'] = 1;
	rom_to_arab['V'] = 5;
	rom_to_arab['X'] = 10;
	rom_to_arab['L'] = 50;
	rom_to_arab['C'] = 100;
	rom_to_arab['D'] = 500;
	rom_to_arab['M'] = 1000;

	arab_to_rom.push_back({ 1000, "M"});
	arab_to_rom.push_back({ 900, "CM" });
	arab_to_rom.push_back({ 500, "D"});
	arab_to_rom.push_back({ 400, "CD" });
	arab_to_rom.push_back({ 100, "C"});
	arab_to_rom.push_back({ 90, "XC" });
	arab_to_rom.push_back({ 50, "L"});
	arab_to_rom.push_back({ 40, "XL" });
	arab_to_rom.push_back({ 10, "X"});
	arab_to_rom.push_back({ 9, "IX" });
	arab_to_rom.push_back({ 5, "V" });
	arab_to_rom.push_back({ 4, "IV" });
	arab_to_rom.push_back({ 1, "I" });

	string s1, s2;
	cin >> s1 >> s2;

	const int n1 = rtoa(s1);
	const int n2 = rtoa(s2);

	cout << n1 + n2 << "\n";
	cout << ator(n1 + n2);

	return 0;
}