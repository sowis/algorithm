#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> cows(N);
	for (pair<int, int>& cow : cows) {
		scanf("%d%d", &cow.first, &cow.second);
	}

	sort(cows.begin(), cows.end());

	int time = 0;
	for (const pair<int, int>& cow : cows) {
		time = max(time, cow.first);
		time += cow.second;
	}

	printf("%d\n", time);

	return 0;
}