#include <cstdio>
#include <vector>

using namespace std;

void test_case(void) {
	int s;
	scanf("%d", &s);

	printf("Pairs for %d: ", s);

	vector<pair<int, int>> v;
	for (int a = 1; a <= s / 2; ++a) {
		const int b = s - a;
		if (a == b) {
			break;
		}

		v.push_back({ a, b });
	}
	
	if (v.size() == 0) {
		printf("\n");
		return;
	}

	for (int i = 0; i < v.size() - 1; ++i) {
		printf("%d %d, ", v[i].first, v[i].second);
	}

	printf("%d %d\n", v[v.size() - 1].first, v[v.size() - 1].second);
}

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		test_case();
	}

	return 0;
}