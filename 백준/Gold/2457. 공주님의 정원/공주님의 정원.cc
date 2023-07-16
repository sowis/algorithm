#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
vector<int> day_psum;

inline int day_serialize(const int month, const int day) {
	return day_psum[month - 1] + day;
}

pair<int, int> block_scan(const vector<pair<int, int>>& flowers, const int begin_idx, const int max_begin) {
	int next_begin_index = (int)flowers.size();
	int max_end = -1;
	for (int i = begin_idx; i < flowers.size(); ++i) {
		if (flowers[i].first > max_begin) {
			next_begin_index = min(next_begin_index, i);
			break;
		}

		if (flowers[i].second > max_end) {
			max_end = flowers[i].second;
		}
	}

	return { next_begin_index, max_end };
}

int main(void) {
	int psum = 0;
	day_psum.push_back(psum);
	for (int i = 0; i < 12; ++i) {
		psum += days[i];
		day_psum.push_back(psum);
	}

	int N;
	scanf("%d", &N);

	vector<pair<int, int>> flowers;
	for (int i = 0; i < N; ++i) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);

		const int birth = day_serialize(a, b);
		const int die = day_serialize(c, d) - 1;

		flowers.push_back({ birth, die });
	}

	sort(flowers.begin(), flowers.end());

	const int begin = day_serialize(3, 1);
	const int end = day_serialize(11, 30);

	if (flowers[0].first > begin) {
		printf("0\n");
		return 0;
	}

	int idx = 0;
	int bound = begin - 1;
	int max_bound = begin - 1;
	int result = 0;

	while (bound != -1) {
		const pair<int, int> p = block_scan(flowers, idx, bound + 1);
		idx = p.first;
		bound = p.second;
		max_bound = max(max_bound, p.second);
		++result;

		if (max_bound >= end) {
			break;
		}
	}

	if (max_bound < end) {
		printf("0\n");
		return 0;
	}

	printf("%d\n", result);

	return 0;
}