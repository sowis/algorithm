#include <cstdio>
#include <vector>

using namespace std;

typedef struct _subject {
	int time;
	int score;
} Subject;

int N, T;
vector<Subject> subjects;
vector<vector<int>> cache(101, vector<int>(10001, -987654321)); // idx, 사용한 시간 = 최대 점수

int main(void) {
	scanf("%d%d", &N, &T);

	subjects = vector<Subject>(N);
	for (Subject& subject : subjects) {
		scanf("%d%d", &subject.time, &subject.score);
	}

	cache[0][0] = 0;
	
	for (int idx = 0; idx < N; ++idx) {
		for (int use_time = 0; use_time <= T; ++use_time) {
			if (cache[idx][use_time] == -987654321) {
				continue;
			}

			cache[idx + 1][use_time] = max(cache[idx + 1][use_time], cache[idx][use_time]);
			if (use_time + subjects[idx].time <= T) {
				cache[idx + 1][use_time + subjects[idx].time] = 
					max(cache[idx + 1][use_time + subjects[idx].time], cache[idx][use_time] + subjects[idx].score);
			}
		}
	}

	int result = 0;
	for (int use_time = 0; use_time <= T; ++use_time) {
		result = max(result, cache[N][use_time]);
	}

	printf("%d\n", result);

	return 0;
}