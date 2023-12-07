#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	int result = 0;
	for (int i = 1; i <= K; ++i) {
		string str = to_string(N * i);
		reverse(str.begin(), str.end());
		result = max(result, stoi(str));
	}

	printf("%d\n", result);

	return 0;
}