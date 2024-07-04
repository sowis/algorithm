#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string num;
		cin >> num;

		if (num.size() == 1) {
			cout << num << "\n";
			continue;
		}

		int upper = 0;
		for (int i = num.size() - 1; i > 0; --i) {
			if (num[i] + upper >= '5') {
				++num[i - 1];
				upper = 0;

				if (num[i - 1] > '9') {
					num[i - 1] = '0';
					upper = 1;
				}
			}

			num[i] = '0';
		}

		if (upper == 1) {
			num = '1' + num;
		}

		for (int i = 1; i < num.size(); ++i) {
			num[i] = '0';
		}

		cout << num << "\n";
	}

	return 0;
}