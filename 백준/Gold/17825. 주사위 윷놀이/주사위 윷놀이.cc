#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int END = 32;

int nexts[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 32, 22, 23, 24, 30, 26, 24, 28, 29, 24, 31, 20, -1 };
int scores[] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 13, 16, 19, 25, 22, 24, 28, 27, 26, 30, 35, 0 };
vector<int> blue(35, -1);
int result = 0;
int mals[4] = { 0, 0, 0, 0 };
vector<int> inputs(10);

int next_index(int current_index, int step) {
	if (current_index == END) {
		return END;
	}

	/* 시작지점이 파란칸이면 파란화살표쪽으로 이동 */
	if (blue[current_index] != -1) {
		current_index = blue[current_index];
		--step;
	}
	/**********************************************/
	
	for (int i = 0; i < step; ++i) {
		current_index = nexts[current_index];

		if (current_index == END) {
			return END;
		}
	}

	return current_index;
}

bool mal_exist(const int index) {
	for (int i = 0; i < 4; ++i) {
		if (mals[i] == index) {
			return true;
		}
	}

	return false;
}

void solve(const int input_idx = 0, const int current_score = 0) {
	if (input_idx == 10) {
		result = max(result, current_score);
		return;
	}

	const int step = inputs[input_idx];

	for (int i = 0; i < 4; ++i) {
		/* 이미 도착한 말이면 이동하지 않음 */
		if (mals[i] == END) {
			continue;
		}
		/************************************/

		const int mal_next_index = next_index(mals[i], step);

		/* 도착예정지점에 다른 말이 있으면 이동하지 않음 */
		if (mal_next_index != END && mal_exist(mal_next_index)) {
			continue;
		}
		/*************************************************/

		/* 말 이동 */
		const int mal_last_index = mals[i]; // 말 위치 세이브
		mals[i] = mal_next_index;
		/***********/

		solve(input_idx + 1, current_score + scores[mal_next_index]);

		/* 말 위치 복구 */
		mals[i] = mal_last_index;
		/****************/
	}
}

int main(void) {
	blue[5] = 21;
	blue[10] = 25;
	blue[15] = 27;

	for (int& number : inputs) {
		scanf("%d", &number);
	}

	solve();

	printf("%d\n", result);

	return 0;
}