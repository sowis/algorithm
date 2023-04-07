#include <cstdio>
#include <vector>

using namespace std;

bool ok(const vector<int>& vote) {
	for (int i = 1; i < vote.size(); ++i) {
		if (vote[0] <= vote[i]) {
			return false;
		}
	}

	return true;
}

int find_max(const vector<int>& vote) {
	int result = 0;
	int value = vote[0];
	for (int i = 1; i < vote.size(); ++i) {
		if (vote[i] >= vote[result]) {
			result = i;
			value = vote[i];
		}
	}

	return result;
}

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> vote(N);
	for (int& v : vote) {
		scanf("%d", &v);
	}

	int result = 0;
	while (ok(vote) == false) {
		const int target = find_max(vote);
		++vote[0];
		--vote[target];
		++result;
	}

	printf("%d\n", result);

	return 0;
}