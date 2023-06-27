#include <cstdio>

using namespace std;

int main(void) {
	int T, S;
	scanf("%d%d", &T, &S);

	if (((12 <= T) && (T <= 16)) && (S == 0)) {
		printf("320\n");
	}
	else {
		printf("280\n");
	}

	return 0;
}