#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Item {
private:
	const static vector<string> codes;
	string name;
	int value;

public:
	Item(const int value) :value(value) {
		int v = value;
		vector<string> tokens;
		while (v > 0) {
			tokens.push_back(this->codes[v % 10]);
			v /= 10;
		}

		reverse(tokens.begin(), tokens.end());

		for (const string token : tokens) {
			this->name += token;
			this->name += " ";
		}
	}

	int get_value(void) const {
		return this->value;
	}

	bool operator<(const Item& item) const {
		return this->name < item.name;
	}
};

const vector<string> Item::codes{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(void) {
	int M, N;
	cin >> M >> N;

	vector<Item> items;
	for (int i = M; i <= N; ++i) {
		items.push_back(Item(i));
	}

	sort(items.begin(), items.end());

	int c = 0;
	for (const Item& item : items) {
		cout << item.get_value() << " ";

		++c;
		if (c == 10) {
			cout << "\n";
			c = 0;
		}
	}

	return 0;
}