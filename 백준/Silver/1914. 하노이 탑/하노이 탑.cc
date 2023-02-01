#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int N;

void hanoi(const int master_height, const int master = 0, const int tmp = 1, const int target = 2) {
	if (master_height == 1) {
		cout << master + 1 << " " << target + 1 << "\n";
		return;
	}

	
	hanoi(master_height - 1, master, target, tmp);
	cout << master + 1 << " " << target + 1 << "\n";
	hanoi(master_height - 1, tmp, master, target);
}

int main(void) {
	cin >> N;

	string result = to_string(pow(2, N));
	result = result.substr(0, result.find('.'));
	--result[result.length() - 1];

	cout << result << "\n";

	if (N <= 20) {
		hanoi(N);
	}

	return 0;
}