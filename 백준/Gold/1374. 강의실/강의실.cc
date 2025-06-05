#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> starts;
	vector<int> ends;

	for (int i = 0; i < N; ++i) {
		int id, start, end;
		scanf("%d%d%d", &id, &start, &end);

		starts.push_back(start);
		ends.push_back(end);
	}

	sort(starts.begin(), starts.end());
	sort(ends.begin(), ends.end());

	int result = 0;
	int current = 0;
	int end_count = 0;

	for (int start_count = 0; start_count < N; ++start_count) {
		while (ends[end_count] <= starts[start_count]) {
			--current;
			++end_count;
		}

		++current;
		result = max(result, current);
	}

	printf("%d\n", result);

	return 0;
}