#include <iostream>

using namespace std;

int main(void) {
	int num;
	char br;

	cin >> num;
	int sum = num;

	while (cin >> br) {
		cin >> num;
		sum += num;
	}

	cout << sum;

	return 0;
}