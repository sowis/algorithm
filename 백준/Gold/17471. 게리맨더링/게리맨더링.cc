#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

typedef unsigned int Group;

int N;
vector<int> people(1); // [0] -> buffer
vector<unordered_set<int>> edges(11);
int result = 987654321;

void show(const Group g) {
	for (int i = 1; i <= N; ++i) {
		if (g & (1 << i)) {
			printf("%d ", i);
		}
	}

	printf("\n");
}

bool is_linked(const Group g) {
	int begin = -1;
	for (int i = 1; i <= N; ++i) {
		if (g & (1 << i)) {
			begin = i;
			break;
		}
	}

	if (begin == -1) {
		return false;
	}

	Group visit = 0;
	queue<int> q;
	q.push(begin);
	visit |= (1 << begin);

	while (q.empty() == false) {
		const int current = q.front();
		q.pop();

		for (const int next : edges[current]) {
			if ((g & (1 << next)) == 0) {
				continue;
			}

			if (visit & (1 << next)) {
				continue;
			}

			visit |= (1 << next);
			q.push(next);
		}
	}

	for (int i = 1; i <= N; ++i) {
		if ((g & (1 << i)) == 0) {
			continue;
		}

		if ((visit & (1 << i)) == 0) {
			return false;
		}
	}

	return true;
}

int get_people_sum(const Group g) {
	int result = 0;
	for (int i = 1; i <= N; ++i) {
		if ((g & (1 << i)) == 0) {
			continue;
		}

		result += people[i];
	}

	return result;
}

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int people_num;
		scanf("%d", &people_num);

		people.push_back(people_num);
	}

	for (int i = 1; i <= N; ++i) {
		int edge_num;
		scanf("%d", &edge_num);

		for (int k = 0; k < edge_num; ++k) {
			int link;
			scanf("%d", &link);

			edges[i].insert(link);
			edges[link].insert(i);
		}
	}

	for (Group g = 1; g < (1 << N); ++g) {
		if (is_linked(g << 1) == false) {
			continue;
		}

		const Group another_g = ~g;
		if (is_linked(another_g << 1) == false) {
			continue;
		}

		const int my_sum = get_people_sum(g << 1);
		const int your_sum = get_people_sum(another_g << 1);
		result = min(result, abs(my_sum - your_sum));

		/*
		show(g << 1);
		show(another_g << 1);
		printf("diff: %d\n", abs(my_sum - your_sum));
		printf("\n");
		*/
	}

	if (result == 987654321) {
		printf("-1\n");
	}
	else {
		printf("%d", result);
	}

	return 0;
}