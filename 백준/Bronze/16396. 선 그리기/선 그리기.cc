#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> lines(N);
	for (pair<int, int>& p : lines) {
		scanf("%d%d", &p.first, &p.second);
	}

	sort(lines.begin(), lines.end());

	int begin = lines[0].first;
	int end = lines[0].first;

	int result = 0;
	for (const pair<int, int>& p : lines) {
		if (p.first <= end) {
			end = max(end, p.second);
		}
		else {
			result += end - begin;
			begin = p.first;
			end = p.second;
		}
	}

	result += end - begin;
	printf("%d\n", result);


	return 0;
}