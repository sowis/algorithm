#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		vector<int> A(4, 0);
		int a;
		scanf("%d", &a);

		for (int i = 0; i < a; ++i) {
			int ddak;
			scanf("%d", &ddak);
			++A[ddak - 1];
		}


		vector<int> B(4, 0);
		int b;
		scanf("%d", &b);

		for (int i = 0; i < b; ++i) {
			int ddak;
			scanf("%d", &ddak);
			++B[ddak - 1];
		}

		char result = 'D';
		for (int i = 3; i >= 0; --i) {
			if (A[i] == B[i]) {
				continue;
			}
			
			result = (A[i] < B[i]) ? 'B' : 'A';
			break;
		}

		printf("%c\n", result);
	}

	return 0;
}