#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	vector<int> sona(4);
	for (int& num : sona) {
		scanf("%d", &num);
	}

	if (sona[0] < sona[1] && sona[1] < sona[2] && sona[2] < sona[3]) {
		printf("Fish Rising");
	}
	else if (sona[0] > sona[1] && sona[1] > sona[2] && sona[2] > sona[3]) {
		printf("Fish Diving");
	}
	else if (sona[0] == sona[1] && sona[1] == sona[2] && sona[2] == sona[3]) {
		printf("Fish At Constant Depth");
	}
	else {
		printf("No Fish");
	}

	return 0;
}