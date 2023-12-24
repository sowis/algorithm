#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

int years[] = { 1, 3, 5 };
double muls[] = { 1.05, 1.2, 1.35 };

using namespace std;

int main(void) {
	int H, Y;
	scanf("%d%d", &H, &Y);

	vector<int> moneies(Y + 1, -1);
	moneies[0] = H;

	for (int i = 0; i < Y; ++i) {
		for (int k = 0; k < 3; ++k) {
			if (i + years[k] > Y) {
				continue;
			}

			moneies[i + years[k]] = max(moneies[i + years[k]], (int)floor(moneies[i] * muls[k]));
		}
	}

	printf("%d\n", moneies[Y]);

	return 0;
}