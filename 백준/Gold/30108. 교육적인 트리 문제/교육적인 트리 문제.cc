#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct _data {
	int id;
	long long number;

	bool operator<(const struct _data& d) const {
		return this->number < d.number;
	}
} Data;

int N;
vector<vector<int>> childs;
vector<int> numbers;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	childs = vector<vector<int>>(N + 1);
	numbers = vector<int>(N + 1);

	for (int i = 2; i <= N; ++i) {
		int parent;
		cin >> parent;

		childs[parent].push_back(i);
	}

	for (int i = 1; i <= N; ++i) {
		cin >> numbers[i];
	}

	long long cur_sum = 0;
	priority_queue<Data> q;
	q.push({ 1, numbers[1] });

	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		cur_sum += d.number;
		cout << cur_sum << "\n";

		for (const int next : childs[d.id]) {
			q.push({ next, numbers[next] });
		}
	}

	return 0;
}