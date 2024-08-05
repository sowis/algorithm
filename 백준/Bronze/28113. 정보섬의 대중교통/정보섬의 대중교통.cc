#include <cstdio>

using namespace std;

int main(void) {
	int N, A, B;
	scanf("%d%d%d", &N, &A, &B);
	
	if (A == B) {
		printf("Anything\n");
	}
	else if (A < B) {
		printf("Bus\n");
	}
	else {
		printf("Subway\n");
	}

	return 0;
}