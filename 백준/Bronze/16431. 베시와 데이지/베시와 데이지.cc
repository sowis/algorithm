#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int By, Bx;
	int Dy, Dx;
	int Jy, Jx;

	scanf("%d%d", &By, &Bx);
	scanf("%d%d", &Dy, &Dx);
	scanf("%d%d", &Jy, &Jx);

	const int B_distance = max(abs(Bx - Jx), abs(By - Jy));
	const int D_distance = abs(Dy - Jy) + abs(Dx - Jx);

	if (B_distance == D_distance) {
		printf("tie\n");
	}
	else if (B_distance < D_distance) {
		printf("bessie\n");
	}
	else {
		printf("daisy\n");
	}

	return 0;
}