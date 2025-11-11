#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <unordered_map>

using namespace std;

typedef struct _change {
	int pos_1;
	int pos_2;
	int cost;
} Change;

typedef struct _data {
	vector<int> arr;
	int cost_sum;

	bool operator< (const struct _data &d) const {
		return this->cost_sum > d.cost_sum;
	}
} Data;

int N;
int result = 1987654321;
vector<Change> changes;
unordered_map<int, int> min_dist;

int v_to_pos(const vector<int>& arr) {
	int result = 0;
	for (int i = 0; i < N; ++i) {
		result += arr[i] * (int)pow(10, N - 1 - i);
	}

	return result;
}

bool finish(const vector<int> &arr) {
	int last = -1;
	for (const int num : arr) {
		if (num < last) {
			return false;
		}

		last = num;
	}

	return true;
}

int main(void) {
	cin >> N;

	vector<int> arr(N);
	for (int& num : arr) {
		cin >> num;
		--num; // 0 ~ 9로 변환
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; ++i) {
		int l, r, c;
		cin >> l >> r >> c;

		changes.push_back({ l, r, c });
	}

	if (finish(arr)) {
		cout << 0;
		return 0;
	}

	priority_queue<Data> q;
	for (const Change& c : changes) {
		swap(arr[c.pos_1 -1], arr[c.pos_2 - 1]);
		min_dist[v_to_pos(arr)] = c.cost;
		q.push({ arr, c.cost });
		swap(arr[c.pos_1 - 1], arr[c.pos_2 - 1]);
	}

	while (q.empty() == false) {
		Data d = q.top();
		q.pop();

		if (finish(d.arr)) {
			result = min(result, d.cost_sum);
			continue;
		}

		for (const Change& c : changes) {
			swap(d.arr[c.pos_1 - 1], d.arr[c.pos_2 - 1]);
			const int pos = v_to_pos(d.arr);
			if (min_dist[pos] != 0 && min_dist[pos] <= d.cost_sum + c.cost) {
				swap(d.arr[c.pos_1 - 1], d.arr[c.pos_2 - 1]);
				continue;
			}

			if (d.cost_sum + c.cost >= result) {
				swap(d.arr[c.pos_1 - 1], d.arr[c.pos_2 - 1]);
				continue;
			}

			min_dist[pos] = d.cost_sum + c.cost;
			q.push({ d.arr, d.cost_sum + c.cost });
			swap(d.arr[c.pos_1 - 1], d.arr[c.pos_2 - 1]);
		}
	}

	if (result == 1987654321) {
		result = -1;
	}

	cout << result;

	return 0;
}