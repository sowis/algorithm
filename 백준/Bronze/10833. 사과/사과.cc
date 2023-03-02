#include <cstdio>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	
	int result = 0;

	for (int i = 0; i < N; ++i) {
		int student, apple;
		scanf("%d%d", &student, &apple);

		result += apple % student;
	}

	printf("%d\n", result);

	return 0;
}