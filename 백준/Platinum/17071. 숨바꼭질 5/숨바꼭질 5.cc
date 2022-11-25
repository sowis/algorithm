#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> psum{ 0 };

int N, K;

inline int K_next(const int time) {
	return K + psum[time];
}

int main(void) {
	for (int i = 1; psum[i - 1] <= 500000; ++i) {
		psum.push_back(psum[i - 1] + i);
	}

	scanf("%d%d", &N, &K);

	vector<int> visit_odd(500001, -1);
	vector<int> visit_even(500001, -1);
	vector<int> currents{ N };
	visit_even[N] = 0;

	for (int time = 1; time <= psum.size(); ++time) {
		vector<int> nexts;
		vector<int>& visit = (time % 2) ? visit_odd : visit_even;

		if (currents.empty()) {
			break;
		}

		for (const int current : currents) {
			if (current - 1 >= 0 && visit[current - 1] == -1) {
				visit[current - 1] = time;
				nexts.push_back(current - 1);
			}

			if (current + 1 <= 500000 && visit[current + 1] == -1) {
				visit[current + 1] = time;
				nexts.push_back(current + 1);
			}

			if (current * 2 <= 500000 && visit[current * 2] == -1) {
				visit[current * 2] = time;
				nexts.push_back(current * 2);
			}
		}

		currents = nexts;
	}

	for (int time = 0; K_next(time) <= 500000; ++time) {
		const int pos = K_next(time);
		vector<int>& visit = (time % 2) ? visit_odd : visit_even;

		if (visit[pos] == -1) {
			continue;
		}

		if (visit[pos] > time) {
			continue;
		}

		if (visit[pos] == time) {
			printf("%d\n", time);
			return 0;
		}

		if (visit[pos] < time) {
			if ((time - visit[pos]) % 2 == 0) {
				printf("%d\n", time);
				return 0;
			}
		}
	}

	printf("-1\n");

	return 0;
}