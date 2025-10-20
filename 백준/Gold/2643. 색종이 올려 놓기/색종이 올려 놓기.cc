#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	int width;
	int height;

	bool operator<(const struct _data& d) const {
		return (this->width * this->height) < (d.width * d.height);
	}
} Data;

int N;
vector<Data> papers;
vector<int> cache;

bool can_insert(const Data& parent, const Data& child) {
	if (child.width <= parent.width && child.height <= parent.height) {
		return true;
	}
	else if (child.height <= parent.width && child.width <= parent.height) {
		return true;
	}

	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		int width, height;
		cin >> width >> height;

		if (width < height) {
			swap(width, height);
		}

		papers.push_back({ width, height });
	}

	sort(papers.begin(), papers.end());

	cache = vector<int>(N, 1);

	for (int i = 0; i < N; ++i) {
		const Data& cur = papers[i];
		for (int k = 0; k < i; ++k) {
			const Data& target = papers[k];
			if (can_insert(cur, target)) {
				cache[i] = max(cache[i], cache[k] + 1);
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; ++i) {
		result = max(result, cache[i]);
	}

	cout << result;

	return 0;
}