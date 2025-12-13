#include <iostream>
#include <vector>

using namespace std;

typedef struct _data {
	int id;
	int sale;
} Data;

int N;
vector<vector<Data>> sales;
int result = 1987654321;

void solve(vector<int>& current_prices, vector<bool>& visit, const int cost, const int buy_count) {
	if (cost >= result) {
		return;
	}

	if (buy_count == N) {
		result = min(result, cost);
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (visit[i]) {
			continue;
		}

		visit[i] = true;
		for (const Data& d : sales[i]) {
			current_prices[d.id] -= d.sale;
		}

		solve(current_prices, visit, cost + max(1, current_prices[i]), buy_count + 1);

		for (const Data& d : sales[i]) {
			current_prices[d.id] += d.sale;
		}

		visit[i] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	vector<int> prices(N);

	for (int& price : prices) {
		cin >> price;
	}

	sales = vector<vector<Data>>(N);
	for (int i = 0; i < N; ++i) {
		int sale_count;
		cin >> sale_count;

		sales[i] = vector<Data>(sale_count);
		for (int k = 0; k < sale_count; ++k) {
			cin >> sales[i][k].id;
			cin >> sales[i][k].sale;
			--sales[i][k].id; // 0부터 시작하도록
		}
	}

	vector<bool> visit(N, false);
	solve(prices, visit, 0, 0);
	cout << result;

	return 0;
}