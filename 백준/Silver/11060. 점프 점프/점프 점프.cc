#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> maze(N, -1);
	vector<int> jump(N);
	maze[0] = 0;

	for (int& j : jump) {
		scanf("%d", &j);
	}

	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	while (q.empty() == false) {
		const pair<int, int> data = q.front();
		q.pop();

		for (int i = 1; i <= jump[data.first]; ++i) {
			const int next_pos = data.first + i;
			
			if (next_pos >= N) {
				continue;
			}

			if (maze[next_pos] != -1) {
				continue;
			}

			maze[next_pos] = data.second + 1;
			q.push({ next_pos, data.second + 1 });
		}
	}

	printf("%d\n", maze[N - 1]);

	return 0;
}