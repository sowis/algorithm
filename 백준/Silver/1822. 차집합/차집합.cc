#include <cstdio>
#include <set>

using namespace std;

int main(void) {
	int na, nb;
	scanf("%d%d", &na, &nb);

	set<int> result;
	for (int i = 0; i < na; ++i) {
		int a;
		scanf("%d", &a);
		result.insert(a);
	}

	for (int i = 0; i < nb; ++i) {
		int b;
		scanf("%d", &b);
		
		result.erase(b);
	}

	printf("%zd\n", result.size());
	for (const int r : result) {
		printf("%d ", r);
	}

	return 0;
}