#include <cstdio>
#include <string>

using namespace std;

int z_count(const string& str) {
	int result = 0;
	for (const char c : str) {
		if (c == '0') {
			++result;
		}
	}

	return result;
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int N, M;
		scanf("%d%d", &N, &M);

		int result = 0;
		for (int i = N; i <= M; ++i) {
			result += z_count(to_string(i));
		}

		printf("%d\n", result);
	}

	return 0;
}