#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int remocon[2] = { -1, 1 };

int main(void) {
	int A, B;
	scanf("%d%d", &A, &B);

	int N;
	scanf("%d", &N);
	
	vector<int> distance(1001, 987654321);
	queue<pair<int, int>> q;
	q.push({ A, 0 });
	
	for (int i = 0; i < N; ++i) {
		int m;
		scanf("%d", &m);

		distance[m] = 1;
		q.push({ m, 1 });
	}

	distance[A] = 0;

	while (q.empty() == false) {
		const pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 2; ++i) {
			const int next = p.first + remocon[i];
			if (next < 0 || next > 1000) {
				continue;
			}

			if (distance[next] <= p.second + 1) {
				continue;
			}

			distance[next] = p.second + 1;
			q.push({ next, p.second + 1 });
		}
	}

	printf("%d\n", distance[B]);

	return 0;
}