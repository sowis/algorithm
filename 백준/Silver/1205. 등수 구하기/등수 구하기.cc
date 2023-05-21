#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, score, P;
	scanf("%d%d%d", &N, &score, &P);

	vector<int> scores(N);
	for (int& s : scores) {
		scanf("%d", &s);
	}

	sort(scores.begin(), scores.end());
	const int rank = N - (upper_bound(scores.begin(), scores.end(), score) - scores.begin()) + 1;
	const int lower_rank = N - (lower_bound(scores.begin(), scores.end(), score) - scores.begin()) + 1;

	if (lower_rank > P) {
		printf("-1\n");
	}
	else {
		printf("%d\n", rank);
	}

	return 0;
}