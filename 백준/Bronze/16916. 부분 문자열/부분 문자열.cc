#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string S, P;
	cin >> S >> P;

	cout << (strstr(S.c_str(), P.c_str()) != nullptr) ? 1 : 0;

	return 0;
}