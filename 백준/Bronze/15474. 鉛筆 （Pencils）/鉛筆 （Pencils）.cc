#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N, A, B, C, D;
	scanf("%d%d%d%d%d", &N, &A, &B, &C, &D);

	const int a_count = (N % A == 0) ? N / A : N / A + 1;
	const int c_count = (N % C == 0) ? N / C : N / C + 1;

	const int result = (a_count * B < c_count * D) ? a_count * B : c_count * D;
	printf("%d\n", result);

	return 0;
}