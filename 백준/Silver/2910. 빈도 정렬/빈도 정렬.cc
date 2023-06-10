#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef struct _data {
	int number;
	int appear_count;
	int first_appear_index;

	bool operator< (const struct _data& d) const {
		if (this->appear_count != d.appear_count) {
			return this->appear_count > d.appear_count;
		}

		return this->first_appear_index < d.first_appear_index;
	}
} Data;

int main(void) {
	int N, C;
	scanf("%d%d", &N, &C);

	unordered_map<int, int> first_appear_indexs;
	unordered_map<int, int> appear_counts;
	vector<Data> datas(N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &datas[i].number);

		if (first_appear_indexs.find(datas[i].number) == first_appear_indexs.end()) {
			first_appear_indexs[datas[i].number] = i;
		}
		
		datas[i].first_appear_index = first_appear_indexs[datas[i].number];
		++appear_counts[datas[i].number];
	}

	for (Data& d : datas) {
		d.appear_count = appear_counts[d.number];
	}

	sort(datas.begin(), datas.end());

	for (const Data& d : datas) {
		printf("%d ", d.number);
	}

	return 0;
}