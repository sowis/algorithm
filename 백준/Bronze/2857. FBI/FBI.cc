#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	vector<int> result;
	string str;
	int idx = 0;

	while (cin >> str) {
		++idx;

		if (str.find("FBI") == string::npos) {
			continue;
		}

		result.push_back(idx);
	}
	
	if (result.size() == 0) {
		cout << "HE GOT AWAY!\n";
	}
	else {
		for (const int i : result) {
			cout << i << " ";
		}
	}

	return 0;
}