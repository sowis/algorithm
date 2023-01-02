#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	vector<int> numbers(10);
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &numbers[i]);
	}

	vector<int> psum(10);
	psum[0] = numbers[0];
	for (int i = 1; i < 10; ++i) {
		psum[i] = psum[i - 1] + numbers[i];
	}

	int score = 0;
	int diff = 100;
	for (int i = 0; i < 10; ++i) {
		if (abs(psum[i] - 100) <= diff) {
			diff = abs(psum[i] - 100);
			score = psum[i];
		}
	}

	printf("%d\n", score);

	return 0;
}