#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
	int id;
	long long release_time;
	long long penalty;
} Data;

struct time_sort {
	bool operator()(const Data& d1, const Data& d2) const {
		return d1.release_time > d2.release_time;
	}
}; // 공개시간이 빠른순으로 정렬

struct penalty_sort {
	bool operator()(const Data& d1, const Data& d2) const {
		return d1.penalty < d2.penalty;
	}
}; // 패널티가 큰 순서로 정렬

void test_case(void) {
	int N, S;
	cin >> N >> S;

	vector<long long> t(N);
	for (long long&time : t) {
		cin >> time;
	}

	vector<long long> v(N);
	for (long long&penalty : v) {
		cin >> penalty;
	}
	
	priority_queue<Data, vector<Data>, struct time_sort> release_q;
	priority_queue<Data, vector<Data>, struct penalty_sort> penalty_q;

	for (int i = 0; i < N; ++i) {
		release_q.push({ i + 1, t[i], v[i] });
	}

	long long current_time = S;
	long long result = 0;
	
	for (int i = 0; i < N; ++i) {
		if (penalty_q.empty()) {
			current_time = max(current_time, release_q.top().release_time);
		}

		while (release_q.empty() == false && release_q.top().release_time <= current_time) {
			penalty_q.push(release_q.top());
			release_q.pop();
		}
		
		const Data d = penalty_q.top();
		penalty_q.pop();

		const long long penalty = d.penalty * max(0LL, current_time - d.release_time);
		result += penalty;

		++current_time;
	}

	cout << result << "\n";
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}