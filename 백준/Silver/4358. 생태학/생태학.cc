#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<string, double> dick;

	string str;
	double count = 0;
	while (getline(cin, str)) {
		++dick[str];
		++count;
	}

	cout << fixed;
	cout.precision(4);
	for (const pair<string, double>& p : dick) {
		cout << p.first << " " << (p.second / count) * 100 << "\n";
	}

	return 0;
}