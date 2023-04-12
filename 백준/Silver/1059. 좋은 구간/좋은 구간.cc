#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int L;
	scanf("%d", &L);

	vector<int> arr(L);
	for (int& number : arr) {
		scanf("%d", &number);
	}

	int N;
	scanf("%d", &N);

	sort(arr.begin(), arr.end());

	int result = 0;
	for (int A = 1; A < 999; ++A) {
		for (int B = A + 1; B <= 1000; ++B) {
			if (N < A || B < N) {
				continue;
			}

			if (*lower_bound(arr.begin(), arr.end(), A) <= B) {
				continue;
			}
			
			++result;
		}
	}
	
	printf("%d\n", result);


	return 0;
}