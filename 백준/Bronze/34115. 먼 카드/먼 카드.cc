#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector<int> numbers(2 * N);
	vector<bool> visit(N + 1, false);
	vector<int> second_index(N + 1);
	for (int i = 0; i < 2 * N; ++i) {
		cin >> numbers[i];

		if (visit[numbers[i]]) {
			second_index[numbers[i]] = i;
		}
		
		visit[numbers[i]] = true;
	}

	int result = 0;
	for (int i = 0; i < 2 * N; ++i) {
		result = max(result, second_index[numbers[i]] - i - 1);
	}

	cout << result;

	return 0;
}