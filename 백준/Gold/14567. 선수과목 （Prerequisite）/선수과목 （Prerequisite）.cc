#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> lines(1001);
vector<int> remain_tasks(1001, 0);
vector<int> end_semesters(1001, 0);

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; ++i) {
		int begin, end;
		scanf("%d%d", &begin, &end);

		lines[begin].push_back(end);
		++remain_tasks[end];
	}

	int semester = 1;
	int end_subject_count = 0;

	while (end_subject_count < N) {
		vector<int> next_remain_tasks = remain_tasks;
		for (int subject = 1; subject <= N; ++subject) {
			if (remain_tasks[subject] != 0) {
				continue;
			}

			++end_subject_count;
			end_semesters[subject] = semester;
			next_remain_tasks[subject] = -1;

			for (const int next_subject : lines[subject]) {
				--next_remain_tasks[next_subject];
			}
		}

		remain_tasks = next_remain_tasks;
		++semester;
	}

	for (int subject = 1; subject <= N; ++subject) {
		printf("%d ", end_semesters[subject]);
	}

	return 0;
}