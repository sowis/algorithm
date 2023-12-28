#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	vector<int> va(9), vb(9);
	for (int i = 0; i < 9; ++i) {
		scanf("%d", &va[i]);
	}

	for (int i = 0; i < 9; ++i) {
		scanf("%d", &vb[i]);
	}

	int a = 0, b = 0;
	int is_win = false;
	for (int i = 0; i < 9; ++i) {
		a += va[i];
		if (a > b) {
			is_win = true;
		}

		b += vb[i];
		if (a > b) {
			is_win = true;
		}
	}

	if (a < b && is_win) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	return 0;
}