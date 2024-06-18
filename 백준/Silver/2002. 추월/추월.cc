#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	unordered_map<string, unordered_set<string>> front;
	unordered_set<string> cars;
	string car;
	cin >> car;
	cars.insert(car);

	for (int i = 1; i < N; ++i) {
		string cur;
		cin >> cur;

		front[cur] = cars;
		cars.insert(cur);
	}

	int result = 0;
	unordered_set<string> new_cars;
	cin >> car;
	for (const string& before_front : front[car]) {
		if (new_cars.find(before_front) == new_cars.end()) {
			++result;
			break;
		}
	}

	new_cars.insert(car);

	for (int i = 1; i < N; ++i) {
		cin >> car;

		for (const string& before_front : front[car]) {
			if (new_cars.find(before_front) == new_cars.end()) {
				++result;
				break;
			}
		}

		new_cars.insert(car);
	}

	cout << result << "\n";

	return 0;
}