#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct _data {
	int pos;
	int dist;
} Data;

int N;
vector<int> edges[200001];

bool is_valid_root(const int root) {
	if (edges[root].size() != 3) {
		return false;
	}

	queue<Data> q;
	q.push({ root, 0 });
	vector<bool> visit(N + 1, false);
	visit[root] = true;
	vector<int> degree_1_distances;

	while (q.empty() == false) {
		const Data d = q.front();
		q.pop();

		if (edges[d.pos].size() == 1) {
			degree_1_distances.push_back(d.dist);
		}

		for (const int next_pos : edges[d.pos]) {
			const int next_dist = d.dist + 1;

			if (visit[next_pos]) {
				continue;
			}

			visit[next_pos] = true;
			q.push({ next_pos, next_dist });
		}
	}

	for (int i = 1; i < degree_1_distances.size(); ++i) {
		if (degree_1_distances[0] != degree_1_distances[i]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	
	for (int i = 1; i < N; ++i) {
		int begin, end;
		cin >> begin >> end;

		edges[begin].push_back(end);
		edges[end].push_back(begin);
	}

	bool degree_3_exist = false;
	for (int i = 1; i <= N; ++i) {
		if (edges[i].size() == 3) {
			degree_3_exist = true;
		}
		else if (edges[i].size() != 1) { // 차수가 1, 3이 아닌 노드가 있으면 풍성한 트리 불가능
			cout << "-1\n";
			return 0;
		}
	}

	if (degree_3_exist == false) { // 차수가 3인 노드가 없으면 풍성한 트리 불가능 (이 경우는 없을듯..)
		cout << "-1\n";
		return 0;
	}

	queue<Data> q;
	q.push({ 1, 0 });
	vector<int> min_distances(N + 1, 1987654321);
	min_distances[1] = 0;
	int max_dist = 0;
	int max_dist_node = 0;

	while (q.empty() == false) { // 1번노드에서부터 bfs로 다른 노드들까지의 거리 구하기
		const Data d = q.front();
		q.pop();

		if (max_dist < d.dist) {
			max_dist = d.dist;
			max_dist_node = d.pos;
		}

		for (const int next_pos : edges[d.pos]) {
			const int next_dist = d.dist + 1;

			if (min_distances[next_pos] <= next_dist) {
				continue;
			}

			min_distances[next_pos] = next_dist;
			q.push({ next_pos, next_dist });
		}
	}

	q.push({ max_dist_node, 0 });
	min_distances = vector<int>(N + 1, 1987654321);
	max_dist = 0;
	vector<int> parents(N + 1, 0);

	while (q.empty() == false) { // 1번노드에서 가장 먼 노드로부터 bfs로 다른 노드들까지의 거리 구하기 (트리의 지름)
		const Data d = q.front();
		q.pop();

		if (max_dist < d.dist) {
			max_dist = d.dist;
			max_dist_node = d.pos;
		}

		for (const int next_pos : edges[d.pos]) {
			const int next_dist = d.dist + 1;

			if (min_distances[next_pos] <= next_dist) {
				continue;
			}

			parents[next_pos] = d.pos;
			min_distances[next_pos] = next_dist;
			q.push({ next_pos, next_dist });
		}
	}

	if (max_dist % 2) { // 트리의 지름이 홀수면 풍성한 트리 불가능
		cout << "-1\n";
		return 0;
	}

	int mid_node = max_dist_node;
	for (int i = 0; i < max_dist / 2; ++i) {
		mid_node = parents[mid_node];
	}

	if (is_valid_root(mid_node) == false) {
		cout << "-1\n";
		return 0;
	}

	cout << 1 << "\n";
	cout << mid_node;

	return 0;
}