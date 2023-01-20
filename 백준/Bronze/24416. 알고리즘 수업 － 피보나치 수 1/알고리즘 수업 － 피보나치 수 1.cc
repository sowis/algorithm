#include <cstdio>
#include <vector>

using namespace std;

vector<int> visit(41, -1);

int code_1(const int n) {
	int& c = visit[n];
	if (n == 1 || n == 2) {
		return c = 1;
	}

	if (c != -1) {
		return c;
	}

	return c = code_1(n - 2) + code_1(n - 1);
}

int code_2(const int n) {
	if (n == 1 || n == 2) {
		return 1;
	}

	return n - 2;
}

int main(void) {
	int N;
	scanf("%d", &N);

	printf("%d\n", code_1(N));
	printf("%d\n", code_2(N));

	return 0;
}