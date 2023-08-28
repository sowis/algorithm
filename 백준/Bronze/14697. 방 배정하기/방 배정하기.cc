#include <cstdio>

using namespace std;

int main(void) {
	int bed_1, bed_2, bed_3, n;
	scanf("%d%d%d%d", &bed_1, &bed_2, &bed_3, &n);

	for (int c1 = 0; bed_1 * c1 <= n; ++c1) {
		const int room_1_in = bed_1 * c1;
		if (room_1_in == n) {
			printf("1\n");
			return 0;
		}

		for (int c2 = 0; bed_2 * c2 <= n - room_1_in; ++c2) {
			const int room_2_in = bed_2 * c2;
			if (room_1_in + room_2_in == n) {
				printf("1\n");
				return 0;
			}

			if ((n - room_1_in - room_2_in) % bed_3 == 0) {
				printf("1\n");
				return 0;
			}
		}
	}

	printf("0\n");

	return 0;
}