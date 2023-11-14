#include <cstdio>

int main(void) {
	int p1, s1, s2, p2;
	scanf("%d%d%d%d", &p1, &s1, &s2, &p2);

	if (p1 + p2 > s1 + s2) {
		printf("Persepolis\n");
	}
	else if (p1 + p2 < s1 + s2) {
		printf("Esteghlal\n");
	}
	else {
		if (s1 > p2) {
			printf("Esteghlal\n");
		}
		else if (s1 < p2) {
			printf("Persepolis\n");
		}
		else {
			printf("Penalty");
		}
	}

	return 0;
}