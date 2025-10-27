#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	int s; // 마감시간
	int t; // 걸리는시간

	bool operator< (const struct _data& d) const {
		if (this->s != d.s) {
			return this->s > d.s;
		}

		return this->t < d.t;
	}
} Data;

int main(void) {
	int N;
	cin >> N;

	vector<Data> jobs(N);
	for (Data& job : jobs) {
		cin >> job.t >> job.s;
	}

	sort(jobs.begin(), jobs.end());

	int cur_time = jobs[0].s;
	for (const Data& job : jobs) {
		cur_time = min(cur_time, job.s);
		cur_time -= job.t;
	}

	if (cur_time < 0) {
		cout << "-1\n";
	}
	else {
		cout << cur_time;
	}

	return 0;
}