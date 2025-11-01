#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<bool> is_even;
vector<int> press_arr; // 압축 수열 / 짝홀홀짝짝짝홀짝 이면 1 -2 3 -1 1 이 저장되는식.. (짝이면 연속된 짝의 개수를 양수로, 홀이면 연속된 홀의 개수를 음수로 저장)

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;

		is_even.push_back(num % 2 == 0);
	}

	for (int i = 0; i < N; ) {
		const bool cur_is_even = is_even[i];
		int count = 1;
		++i;

		while (i < N && is_even[i] == cur_is_even) {
			++count;
			++i;
		}

		if (cur_is_even) {
			press_arr.push_back(count);
		}
		else {
			press_arr.push_back(-1 * count);
		}
	}

	int left = 0;
	int right = 0;
	int remove_count = 0;
	int even_arr_len = 0;
	int result = 0;
	
	while (right < press_arr.size() && left < press_arr.size()) {
		while (right < press_arr.size()) {
			if (press_arr[right] > 0) {
				even_arr_len += press_arr[right];
				++right;
				break;
			}
			else {
				remove_count += -1 * press_arr[right];
				++right;
			}
		}

		while (left < press_arr.size() && K < remove_count) {
			if (press_arr[left] > 0) {
				even_arr_len -= press_arr[left];
				++left;
			}
			else {
				remove_count -= -1 * press_arr[left];
				++left;
			}
		}

		result = max(result, even_arr_len);
	}

	cout << result;

	return 0;
}