#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<vector<int>> board;
typedef vector<vector<bool>> checklist;

typedef struct {
	int i;
	int y;
	int x;
} POS;

vector<vector<POS>> ball_positions(91);

bool have_bingo(const checklist& list) {
	/* 가로 빙고 확인 */
	for (int y = 0; y < 5; ++y) {
		bool is_bingo = true;

		for (int x = 0; x < 5; ++x) {
			if (list[y][x] == false) {
				is_bingo = false;
				break;
			}
		}

		if (is_bingo) {
			return true;
		}
	}
	/******************/

	/* 세로 빙고 확인 */
	for (int x = 0; x < 5; ++x) {
		bool is_bingo = true;

		for (int y = 0; y < 5; ++y) {
			if (list[y][x] == false) {
				is_bingo = false;
				break;
			}
		}

		if (is_bingo) {
			return true;
		}
	}
	/*****************/

	/* \ 방향 빙고 확인 */
	bool is_bingo = true;
	for (int i = 0; i < 5; ++i) {
		if (list[i][i] == false) {
			is_bingo = false;
			break;
		}
	}

	if (is_bingo) {
		return true;
	}
	/*********************/

	/* / 방향 빙고 확인 */
	is_bingo = true;
	for (int i = 0; i < 5; ++i) {
		if (list[i][4 - i] == false) {
			is_bingo = false;
			break;
		}
	}

	if (is_bingo) {
		return true;
	}
	/*********************/

	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<string> names(N);
	vector<board> boards(vector<vector<vector<int>>>(N, vector<vector<int>>(5, vector<int>(5))));

	/* 사용자 정보 저장 */
	for (int i = 0; i < N; ++i) {
		cin >> names[i];

		for (int y = 0; y < 5; ++y) {
			for (int x = 0; x < 5; ++x) {
				cin >> boards[i][y][x];
				ball_positions[boards[i][y][x]].push_back({ i, y, x });
			}
		}
	}
	/******************/

	/* 뽑힌 공 체크 */
	int m;
	cin >> m;

	vector<checklist> checklists(vector<vector<vector<bool>>>(N, vector<vector<bool>>(5, vector<bool>(5, false))));
	for (int i = 0; i < m; ++i) {
		int ball;
		cin >> ball;

		for (const POS pos : ball_positions[ball]) {
			checklists[pos.i][pos.y][pos.x] = true;
		}
	}
	/***************/
	
	/* 빙고인지 확인후 출력 */
	vector<string> results;
	for (int i = 0; i < N; ++i) {
		if (have_bingo(checklists[i])) {
			results.push_back(names[i]);
		}
	}

	cout << results.size() << "\n";
	for (const string& name : results) {
		cout << name << "\n";
	}
	/***********************/

	return 0;
}