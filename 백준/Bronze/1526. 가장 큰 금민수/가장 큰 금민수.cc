#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> targets;

void fill_kuminsu(const string& number) {
	if (stoi(number) > 1000000) {
		return;
	}

	targets.push_back(stoi(number));
	fill_kuminsu(number + "4");
	fill_kuminsu(number + "7");
}

int main(void) {
	fill_kuminsu("4");
	fill_kuminsu("7");

	sort(targets.begin(), targets.end());

	int N;
	scanf("%d", &N);
	const int result = *(--upper_bound(targets.begin(), targets.end(), N));

	printf("%d\n", result);

	return 0;
}