#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool is_end(const vector<int>& v) {
	for (int i = 1; i < v.size(); ++i) {
		if (v[i - 1] > v[i]) {
			return false;
		}
	}

	return true;
}

void show(const vector<int>& v) {
	for (const int num : v) {
		printf("%d ", num);
	}

	printf("\n");
}

int main(void) {
	vector<int> v(5);

	for (int i = 0; i < 5; ++i) {
		scanf("%d", &v[i]);
	}

	while (true) {
		for (int i = 1; i < 5; ++i) {
			if (v[i - 1] > v[i]) {
				swap(v[i - 1], v[i]);
				show(v);
			}
		}
		
		if (is_end(v)) {
			break;
		}
	}

	return 0;
}