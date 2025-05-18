#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

typedef struct _data {
	char color;
	int size;
} Data;

int main(void) {
	int N;
	cin >> N;

	vector<Data> mass;
	char cur_color = -1;
	int cur_size = 0;
	int red_count = 0, blue_count = 0;
	for (int i = 0; i < N; ++i) {
		char color;
		cin >> color;

		if (cur_color == -1) {
			cur_color = color;
			cur_size = 1;
			continue;
		}

		if (color == cur_color) {
			++cur_size;
			continue;
		}

		mass.push_back({ cur_color, cur_size });
		if (cur_color == 'R') {
			red_count += cur_size;
		}
		else {
			blue_count += cur_size;
		}

		cur_color = color;
		cur_size = 1;
	}

	mass.push_back({ cur_color, cur_size });
	if (cur_color == 'R') {
		red_count += cur_size;
	}
	else {
		blue_count += cur_size;
	}

	int result = numeric_limits<int>::max();

	if (mass[0].color == 'R') {
		result = min(result, red_count - mass[0].size); // 빨강을 왼쪽으로
		result = min(result, blue_count); // 파랑을 왼쪽으로
	}
	else {
		result = min(result, blue_count - mass[0].size); // 파랑을 왼쪽으로
		result = min(result, red_count); // 빨강을 왼쪽으로
	}

	if (mass[mass.size() - 1].color == 'R') {
		result = min(result, red_count - mass[mass.size() - 1].size); // 빨강을 오른쪽으로
		result = min(result, blue_count); // 파랑을 오른쪽으로
	}
	else {
		result = min(result, blue_count - mass[mass.size() - 1].size); // 파랑을 오른쪽으로
		result = min(result, red_count); // 빨강을 오른쪽으로
	}
	
	cout << result;

	return 0;
}