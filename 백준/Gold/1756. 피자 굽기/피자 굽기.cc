#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int D, N;
vector<int> widths;
vector<int> max_widths;

int get_insert_max(const int num) {
	return (int)(upper_bound(max_widths.begin(), max_widths.end(), num, greater<int>()) - max_widths.begin());
}

int main(void) {
	cin >> D >> N;

	widths = vector<int>(D);
	int max_width = 1987654321;
	for (int& width : widths) {
		cin >> width;

		max_width = min(max_width, width);
		max_widths.push_back(max_width);
	}
	
	int top = D + 1;
	for (int i = 0; i < N; ++i) {
		int width;
		cin >> width;

		const int insert_pos = get_insert_max(width);
		if (top <= insert_pos) {
			--top;
		}
		else {
			top = insert_pos;
		}

		if (top == 0) {
			cout << 0;
			return 0;
		}
	}
	
	cout << top;

	return 0;
}