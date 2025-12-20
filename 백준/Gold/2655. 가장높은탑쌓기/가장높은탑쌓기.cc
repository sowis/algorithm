#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _block {
	int width;
	int height;
	int weight;
} Block;

int N;
vector<Block> blocks;
vector<vector<int>> upper_availables;
vector<int> cache; // 이 블록부터 시작해서 쌓을 수 있는 가장 높은 높이
vector<int> upper_id; // 이 블록부터 시작해서 가장 높게 쌓을 때, 이 블록 위에 오는 블록 id

int solve(const int block_id) {
	int& c = cache[block_id];
	if (c != -1) {
		return c;
	}

	int upper_max_height = 0;
	for (const int upper_block_id : upper_availables[block_id]) {
		const int upper_height = solve(upper_block_id);
		if (upper_max_height < upper_height) {
			upper_max_height = upper_height;
			upper_id[block_id] = upper_block_id;
		}
	}

	return c = blocks[block_id].height + upper_max_height;
}

int main(void) {
	cin >> N;

	blocks = vector<Block>(N);
	for (Block& block : blocks) {
		cin >> block.width >> block.height >> block.weight;
	}

	upper_availables = vector<vector<int>>(N);
	for (int cur = 0; cur < N; ++cur) {
		for (int next = 0; next < N; ++next) {
			if (blocks[cur].width > blocks[next].width && blocks[cur].weight > blocks[next].weight) {
				upper_availables[cur].push_back(next);
			}
		}
	}

	cache = vector<int>(N, -1);
	upper_id = vector<int>(N, -1);
	int max_height = -1;
	int base_id = -1;
	for (int i = 0; i < N; ++i) {
		const int cur_height = solve(i);
		if (max_height < cur_height) {
			max_height = cur_height;
			base_id = i;
		}
	}

	vector<int> trace;
	int cur_id = base_id;
	while (cur_id != -1) {
		trace.push_back(cur_id);
		cur_id = upper_id[cur_id];
	}

	reverse(trace.begin(), trace.end());

	cout << trace.size() << "\n";
	for (const int id : trace) {
		cout << id + 1 << "\n";
	}

	return 0;
}