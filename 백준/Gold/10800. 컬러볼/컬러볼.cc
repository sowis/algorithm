#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _ball {
	int id;
	int color;
	int size;

	bool operator<(const struct _ball& b) const {
		return this->size < b.size;
	}
} Ball;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<vector<Ball>> color_balls(N + 1);
	vector<Ball> all_balls;

	for (int id = 0; id < N; ++id) {
		int color, size;
		scanf("%d%d", &color, &size);

		color_balls[color].push_back({ id, color, size });
		all_balls.push_back({ id, color, size });
	}

	for (vector<Ball>& balls : color_balls) {
		sort(balls.begin(), balls.end());
	}

	sort(all_balls.begin(), all_balls.end());

	vector<vector<int>> color_psum(N + 1);
	for (int color = 1; color <= N; ++color) {
		int psum = 0;
		int last_size = -1;
		int lazy = 0;
		for (const Ball& b : color_balls[color]) {
			if (last_size < b.size) {
				last_size = b.size;
				psum += b.size;
				psum += lazy;
				lazy = 0;
			}
			else {
				lazy += b.size;
			}

			color_psum[color].push_back(psum);
		}
	}

	vector<int> results(N);
	vector<int> psum_indexs(N + 1, 0);
	int psum = 0;
	int last_size = -1;
	int lazy = 0;
	for (const Ball& b : all_balls) {
		if (b.size > last_size) {
			last_size = b.size;
			psum += b.size;
			psum += lazy;
			lazy = 0;
		}
		else {
			lazy += b.size;
		}
		
		results[b.id] = psum - color_psum[b.color][psum_indexs[b.color]];
		++psum_indexs[b.color];
	}

	for (const int r : results) {
		printf("%d\n", r);
	}

	return 0;
}