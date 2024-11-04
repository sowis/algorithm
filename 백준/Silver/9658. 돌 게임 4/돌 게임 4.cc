#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	vector<bool> can_win(1001);
	can_win[1] = false;
	can_win[2] = true;
	can_win[3] = false;
	can_win[4] = true;

	for (int i = 5; i <= 1000; ++i) {
		can_win[i] = !can_win[i - 1] || !can_win[i - 3] || !can_win[i - 4];
	}

	int N;
	scanf("%d", &N);

	printf("%s\n", can_win[N] ? "SK" : "CY");

	return 0;
}