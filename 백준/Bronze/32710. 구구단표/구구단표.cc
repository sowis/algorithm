#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> s;

int main(void) {
	for (int base = 1; base <= 9; ++base) {
		for (int mul = 1; mul <= 9; ++mul) {
			s.insert(base);
			s.insert(mul);
			s.insert(base * mul);
		}
	}

	int N;
	cin >> N;

	if (s.find(N) == s.end()) {
		cout << 0;
	}
	else {
		cout << 1;
	}

	return 0;
}