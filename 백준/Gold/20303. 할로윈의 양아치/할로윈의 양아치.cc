#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	int sz;
	int candy;

	bool operator< (const _data& d) const {
		if (sz == d.sz) {
			return candy > d.candy;
		}

		return sz < d.sz;
	}
} Data;

int N, M, K;
vector<int> candies;
vector<vector<int>> tomodachi(30002);
vector<int> colors;
vector<Data> datas;

int knapsack(vector<vector<int>>& cache, int remain, int index) {
	int& c = cache[remain][index];
	if (c != -1) {
		return c;
	}

	if (index == datas.size()) {
		return c = 0;
	}

	if (datas[index].sz > remain) {
		return c = 0;
	}

	const int on = datas[index].candy + knapsack(cache, remain - datas[index].sz, index + 1);
	const int off = knapsack(cache, remain, index + 1);
	return c = max(on, off);
}

int dfs(const int current, const int color, int &sz) {
	colors[current] = color;
	++sz;

	int candy_sum = candies[current];
	for (const int next : tomodachi[current]) {
		if (colors[next] != -1) {
			continue;
		}

		candy_sum += dfs(next, color, sz);
	}

	return candy_sum;
}

int main(void) {
	scanf("%d%d%d", &N, &M, &K);

	candies = vector<int>(N);
	for (int& candy : candies) {
		scanf("%d", &candy);
	}

	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		tomodachi[a - 1].push_back(b - 1);
		tomodachi[b - 1].push_back(a - 1);
	}
	
	colors = vector<int>(N, -1);
	int color = 0;
	for (int i = 0; i < N; ++i) {
		if (colors[i] != -1) {
			continue;
		}

		int sz = 0;
		const int candy_sum = dfs(i, color, sz);
		datas.push_back({ sz, candy_sum });

		++color;
	}

	sort(datas.begin(), datas.end());
	vector<vector<int>> cache(K + 1, vector<int>(datas.size() + 1, -1));
	const int result = knapsack(cache, K - 1, 0);

	printf("%d\n", result);

	return 0;
}