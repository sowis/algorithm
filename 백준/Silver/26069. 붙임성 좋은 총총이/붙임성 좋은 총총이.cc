#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	unordered_set<string> dance;
	dance.insert("ChongChong");

	for (int i = 0; i < N; ++i) {
		string a, b;
		cin >> a >> b;

		if (dance.find(a) != dance.end() || dance.find(b) != dance.end()) {
			dance.insert(a);
			dance.insert(b);
		}
	}

	cout << dance.size();

	return 0;
}