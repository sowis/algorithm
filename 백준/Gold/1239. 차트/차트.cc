#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> numbers;
int result = 0;

void line_count(const vector<int>& dogs) {
	int current_sum = 0;
	int left = 0;
	int right = 0;
	int line = 0;
	int away_sum = 0;

	while (left < N && right < N && away_sum < 50) {
		while (right < N && current_sum < 50 && away_sum < 50) {
			current_sum += dogs[right];
			++right;
		}

		if (current_sum == 50 && away_sum < 50) {
			++line;
			away_sum += dogs[left];
			current_sum -= dogs[left];
			++left;
		}

		while (left < right && current_sum > 50 && away_sum < 50) {
			away_sum += dogs[left];
			current_sum -= dogs[left];
			++left;
		}

		if (current_sum == 50 && away_sum < 50) {
			++line;
			away_sum += dogs[left];
			current_sum -= dogs[left];
			++left;
		}
	}

	result = max(result, line);
}

void suffle(vector<int>& buffer, const int idx, vector<bool>& visit) {
	if (idx == N) {
		line_count(buffer);
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (visit[i]) {
			continue;
		}

		buffer[i] = numbers[idx];
		visit[i] = true;
		suffle(buffer, idx + 1, visit);
		visit[i] = false;
	}
}

int main(void) {
	cin >> N;

	numbers = vector<int>(N);
	for (int& num : numbers) {
		cin >> num;
	}

	vector<bool> visit(N, false);
	vector<int> buffer(N);
	suffle(buffer, 0, visit);

	cout << result;

	return 0;
}