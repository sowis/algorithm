#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> W(10), K(10);
	for (int& num : W) {
		scanf("%d", &num);
	}

	for (int& num : K) {
		scanf("%d", &num);
	}

	sort(W.begin(), W.end());
	sort(K.begin(), K.end());

	printf("%d %d\n", W[7] + W[8] + W[9], K[7] + K[8] + K[9]);

	return 0;
}