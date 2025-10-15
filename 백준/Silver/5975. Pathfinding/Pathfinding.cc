#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct _data {
	int pos;
	int dist;

	bool operator< (const struct _data& data) const {
		return this->dist > data.dist;
	}
} Data;

int N, M;
vector<int> edges[101];

int main(void) {
	cin >> N >> M;
	--M;

	for (int begin = 0; begin < N; ++begin) {
		for (int end = 0; end < N; ++end) {
			int dist;
			cin >> dist;

			if (dist == 0) {
				continue;
			}

			edges[begin].push_back(end);
		}
	}

	priority_queue<Data> pq;
	vector<int> distances(N, 987654321);
	pq.push({ M, 0 });
	distances[M] = 0;

	while (pq.empty() == false) {
		const Data d = pq.top();
		pq.pop();

		if (distances[d.pos] < d.dist) {
			continue;
		}

		for (const int next : edges[d.pos]) {
			const int next_dist = d.dist + 1;
			if (distances[next] <= next_dist) {
				continue;
			}

			distances[next] = next_dist;
			pq.push({ next, next_dist });
		}
	}

	for (int dist = 0; dist < N; ++dist) {
		bool printed = false;
		for (int pos = 0; pos < N; ++pos) {
			if (distances[pos] == dist) {
				cout << pos + 1 << " ";
				printed = true;
			}
		}

		if (printed) {
			cout << "\n";
		}
	}

	return 0;
}