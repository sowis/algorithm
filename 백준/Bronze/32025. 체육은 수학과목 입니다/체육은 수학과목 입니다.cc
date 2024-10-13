#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int H, W;
	scanf("%d%d", &H, &W);

	const int result = min(H, W) * 50;
	printf("%d\n", result);

	return 0;
}