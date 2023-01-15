#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
	int N, B;
	scanf("%d%d", &N, &B);

	vector<char> result;
	while (N > 0) {
		const int remain = N % B;
		if (0 <= remain && remain < 10) {
			result.push_back('0' + remain);
		}
		else {
			result.push_back('A' + remain - 10);
		}

		N /= B;
	}

	reverse(result.begin(), result.end());

	for (const char c : result) {
		printf("%c", c);
	}

	return 0;
}