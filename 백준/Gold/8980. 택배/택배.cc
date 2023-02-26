#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	int source;
	int target;
	int box;

	bool operator<(const struct _data& d) const {
		if (target != d.target) {
			return target < d.target;
		}

		return source > d.source;
	}
} Data;

int N, C;
int M;
vector<Data> datas;

int main(void) {
	scanf("%d%d", &N, &C);
	scanf("%d", &M);

	datas = vector<Data>(M);
	for (Data& data : datas) {
		scanf("%d%d%d", &data.source, &data.target, &data.box);
	}

	sort(datas.begin(), datas.end());

	int result = 0;
	vector<int> truck(N + 1, 0);
	for (const Data& data : datas) {
		int remain_space = C;
		for (int i = data.source; i < data.target; ++i) {
			remain_space = min(remain_space, C - truck[i]);
		}

		const int move = min(remain_space, data.box);

		for (int i = data.source; i < data.target; ++i) {
			truck[i] += move;
		}

		result += move;
	}

	printf("%d\n", result);

	return 0;
}