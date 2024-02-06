#include <cstdio>
#include <vector>

using namespace std;

constexpr int LEFT = 1;
constexpr int RIGHT = 2;
constexpr int EMPTY = 0;

typedef struct _data {
	int pos;
	int sum;

	bool operator==(const struct _data &d) const {
		return (pos == d.pos) && (sum == d.sum);
	}

	bool operator!= (const struct _data& d) const {
		return !this->operator==(d);
	}
} Data;

const Data empty_data{ EMPTY, EMPTY };

int N;
vector<int> scores;
vector<vector<Data>> cache;

Data best(const int begin, const int end) {
	Data& c = cache[begin][end];
	if (c != empty_data) {
		return c;
	}
	
	if (end - begin <= 2) {
		if (scores[begin] < scores[end - 1]) {
			c = { RIGHT, scores[end - 1] };
		}
		else {
			c = { LEFT, scores[begin] };
		}

		return c;
	}

	const int left_choice = scores[begin] + 
		((best(begin + 1, end).pos == LEFT) ? best(begin + 2, end).sum : best(begin + 1, end - 1).sum);

	const int right_choice = scores[end - 1] + 
		((best(begin, end - 1).pos == LEFT) ? best(begin + 1, end - 1).sum : best(begin, end - 2).sum);

	c = (left_choice < right_choice) ? Data{ RIGHT, right_choice } : Data{ LEFT, left_choice };
	return c;
}

void test_case(void) {
	scanf("%d", &N);

	scores = vector<int>(N);
	cache = vector<vector<Data>>(N, vector<Data>(N + 1));

	for (int& score : scores) {
		scanf("%d", &score);
	}

	const int result = best(0, N).sum;
	printf("%d\n", result);
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}