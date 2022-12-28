#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<long long> lectures;

bool can_make(const long long blue_ray_size) {
	long long current_size = 0;
	long long current_count = 0;
	for (int i = 0; i < N; ++i) {
		if (lectures[i] > blue_ray_size) {
			return false;
		}

		if (current_size + lectures[i] > blue_ray_size) {
			++current_count;
			current_size = lectures[i];
		}
		else {
			current_size += lectures[i];
		}
	}

	++current_count;
	return current_count <= M;
}

int main(void) {
	scanf("%d%d", &N, &M);

	lectures = vector<long long>(N);
	long long sums = 0;
	for (long long &lecture : lectures) {
		scanf("%lld", &lecture);
		sums += lecture;
	}

	long long begin = 0;
	long long end = sums;
	long long last_ok = sums;

	while (begin <= end) {
		const long long mid = (begin + end) / 2;
		if (can_make(mid)) {
			last_ok = mid;
			end = mid - 1;
		}
		else {
			begin = mid + 1;
		}
	}

	printf("%lld\n", last_ok);

	return 0;
}