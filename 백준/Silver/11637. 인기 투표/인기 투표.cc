#include <cstdio>

using namespace std;

void test_case(void) {
	int N;
	scanf("%d", &N);

	int all_sum = 0;
	int max_value = 0;
	int max_index = 0;
	int max_count = 0;
	
	for (int i = 0; i < N; ++i) {
		int vote;
		scanf("%d", &vote);

		all_sum += vote;
		if (max_value < vote) {
			max_value = vote;
			max_index = i + 1;
			max_count = 1;
		}
		else if (max_value == vote) {
			++max_count;
		}
	}

	if (max_count > 1) {
		printf("no winner\n");
		return;
	}

	if (max_value * 2 > all_sum) {
		printf("majority winner %d\n", max_index);
		return;
	}

	printf("minority winner %d\n", max_index);
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}