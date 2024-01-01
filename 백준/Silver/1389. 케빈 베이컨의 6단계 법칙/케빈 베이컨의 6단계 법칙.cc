#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

int N, M;
vector<unordered_set<int>> edges;

int bacon(const int me) {
	vector<int> distance(N + 1, -1);
	queue<pair<int, int>> q;

	q.push({me, 0});
	distance[me] = 0;

	while (q.empty() == false) {
		const pair<int, int> person = q.front();
		q.pop();

		for (const int next_person : edges[person.first]) {
			if (distance[next_person] != -1) {
				continue;
			}

			distance[next_person] = person.second + 1;
			q.push({next_person, person.second + 1});
		}
	}

	int result = 0;
	for (int i = 1; i <= N; ++i) {
		result += distance[i];
	}

	return result;
}

int main(void) {
	scanf("%d%d", &N, &M);

	edges = vector<unordered_set<int>>(N + 1);
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		edges[a].insert(b);
		edges[b].insert(a);
	}

	int min_bacon = 987654321;
	int min_person;

	for (int person = 1; person <= N; ++person) {
		const int b = bacon(person);
		if (b < min_bacon) {
			min_bacon = b;
			min_person = person;
		}
	}

	printf("%d\n", min_person);

	return 0;
}