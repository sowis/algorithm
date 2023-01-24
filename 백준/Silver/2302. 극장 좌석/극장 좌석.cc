#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<int> cache(41, -1);

int get_count(const int num) {
	int& c = cache[num];
	if (c != -1) {
		return c;
	}

	if (num == 0 || num == 1) {
		return c = 1;
	}

	if (num == 2) {
		return c = 2;
	}

	return c = get_count(num - 1) + get_count(num - 2);
}

int main(void) {
	scanf("%d", &N);

	int vip_count;
	scanf("%d", &vip_count);

	int hole = 1;
	vector<int> hole_size;

	for (int i = 0; i < vip_count; ++i) {
		int vip_pos;
		scanf("%d", &vip_pos);
		
		hole_size.push_back(vip_pos - hole);
		hole = vip_pos + 1;
	}

	hole_size.push_back(N + 1 - hole);

	int result = 1;
	for (const int hole : hole_size) {
		result *= get_count(hole);
	}

	printf("%d\n", result);

	return 0;
}