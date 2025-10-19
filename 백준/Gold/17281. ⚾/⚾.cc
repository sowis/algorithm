#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int result = 0;
vector<vector<int>> innings;

int cal_inning_score(const vector<int>& inning, const vector<int>& order, int &idx) {
	int out_count = 0;
	int score = 0;
	vector<bool> base_status(3, false);
	for (; out_count < 3; idx = (idx + 1) % 9) {
		const int cur = order[idx] - 1;
		switch (inning[cur]) {
		case 0: // 아웃
			++out_count;
			break;
		case 1: // 안타
			if (base_status[2]) {
				++score;
			}

			base_status[2] = base_status[1];
			base_status[1] = base_status[0];
			base_status[0] = true;
			break;
		case 2: // 2루타
			if (base_status[2]) {
				++score;
			}

			if (base_status[1]) {
				++score;
			}

			base_status[2] = base_status[0];
			base_status[1] = true;
			base_status[0] = false;
			break;
		case 3: // 3루타
			if (base_status[2]) {
				++score;
			}

			if (base_status[1]) {
				++score;
			}

			if (base_status[0]) {
				++score;
			}

			base_status[2] = true;
			base_status[1] = false;
			base_status[0] = false;
			break;
		case 4: // 홈런
			if (base_status[2]) {
				++score;
			}

			if (base_status[1]) {
				++score;
			}

			if (base_status[0]) {
				++score;
			}
			
			++score;

			base_status[2] = false;
			base_status[1] = false;
			base_status[0] = false;
			break;
		}
	}

	return score;
}

void cal_result(const vector<int>& order) {
	int score = 0;
	int idx = 0;
	for (const vector<int>& inning : innings) {
		score += cal_inning_score(inning, order, idx);
	}

	result = max(result, score);
}

void create_orders(vector<int>& order, vector<bool> &visit, int num) {
	if (num == 10) {
		cal_result(order);
		return;
	}

	if (num == 1) {
		order[3] = num;
		visit[3] = true;
		create_orders(order, visit, num + 1);
		return;
	}
	
	for (int i = 0; i < 9; ++i) {
		if (visit[i]) {
			continue;
		}

		order[i] = num;
		visit[i] = true;
		create_orders(order, visit, num + 1);
		visit[i] = false;
	}
}

int main(void) {
	cin >> N;

	innings = vector<vector<int>>(N, vector<int>(9));
	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < 9; ++k) {
			cin >> innings[i][k];
		}
	}

	vector<int> order(9);
	vector<bool> visit(9, false);
	create_orders(order, visit, 1);

	cout << result;

	return 0;
}