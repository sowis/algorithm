#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

constexpr int EMPTY = -1;

typedef struct _data {
	int pos;
	int time;

	bool operator<(const struct _data& d) const {
		return this->time > d.time;
	}
} Data;

int N, P, M;
vector<int> X, V;
vector<vector<pair<int, int>>> edges;
vector<vector<int>> min_times;

void dijkstra(const int friend_id) {
	priority_queue<Data> q;
	min_times[friend_id][X[friend_id]] = 0;
	q.push({ X[friend_id], 0});

	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		
		for (const pair<int, int>&p : edges[d.pos]) {
			const int next_pos = p.first;
			const int next_time = d.time + (p.second * V[friend_id]);

			if ((min_times[friend_id][next_pos] == EMPTY) || (next_time < min_times[friend_id][next_pos])) {
				min_times[friend_id][next_pos] = next_time;
				q.push({ next_pos, next_time });
			}
		}
	}
}

void test_case(const int test_num) {
	cin >> N >> P >> M;

	X = vector<int>(P);
	V = vector<int>(P);

	for (int i = 0; i < P; ++i) {
		cin >> X[i] >> V[i];
	}

	edges = vector<vector<pair<int, int>>>(N + 1);
	for (int i = 0; i < M; ++i) {
		int D, L;
		cin >> D >> L;

		vector<int> citys(L);
		for (int& C : citys) {
			cin >> C;
		}

		for (int i = 1; i < L; ++i) {
			const int begin = i - 1;
			const int end = i;

			edges[citys[begin]].push_back({ citys[end], D });
			edges[citys[end]].push_back({ citys[begin], D });
		}
	}

	min_times = vector<vector<int>>(N + 1, vector<int>(N + 1, EMPTY));
	for (int friend_id = 0; friend_id < P; ++friend_id) {
		dijkstra(friend_id);
	}

	int result = EMPTY;
	for (int meet_point = 1; meet_point <= N; ++meet_point) {
		int current_min_time = 0;
		for (int friend_id = 0; friend_id < P; ++friend_id) {
			if (min_times[friend_id][meet_point] == EMPTY) {
				current_min_time = EMPTY;
				break;
			}
			else {
				current_min_time = max(current_min_time, min_times[friend_id][meet_point]);
			}
		}

		if (current_min_time == EMPTY) {
			continue;
		}

		if (result == EMPTY) {
			result = current_min_time;
		}
		else {
			result = min(result, current_min_time);
		}
	}

	if (result == EMPTY) {
		cout << "Case #" << test_num << ": " << -1 << "\n";
	}
	else {
		cout << "Case #" << test_num << ": " << result << "\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case(i + 1);
	}

	return 0;
}