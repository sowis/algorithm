#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	int student_num;
	int chu;
	int old;

	bool operator<(const _data& d) const {
		if (this->chu != d.chu) {
			return this->chu > d.chu;
		}

		return this->old > d.old;
	}
} Data;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	priority_queue<Data> q;
	vector<bool> q_inside(101, false);

	for (int i = 0; i < M; ++i) {
		int chu_target;
		scanf("%d", &chu_target);

		if (q_inside[chu_target]) {
			priority_queue<Data> new_q;
			while (q.empty() == false) {
				const Data d = q.top();
				q.pop();

				if (d.student_num == chu_target) {
					new_q.push({ chu_target, d.chu + 1, d.old });
				}
				else {
					new_q.push(d);
				}
			}

			q = new_q;
		}
		else {
			if (q.size() >= N) {
				q_inside[q.top().student_num] = false;
				q.pop();
			}

			q.push({ chu_target, 1, i });
			q_inside[chu_target] = true;
		}
	}

	vector<int> results;
	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();
		results.push_back(d.student_num);
	}

	sort(results.begin(), results.end());

	for (const int r : results) {
		printf("%d ", r);
	}

	return 0;
}