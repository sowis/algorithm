#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	int time;
	int price;
	
	bool operator< (const struct _data& d) const {
		return (double)this->price / this->time > (double)d.price / d.time;
	}
} Data;

int main(void) {
	int N, T;
	cin >> N >> T;

	int price_sum = 0;
	vector<Data> datas(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> datas[i].time >> datas[i].price;
		price_sum += datas[i].price;
	}

	vector<vector<int>> cache(N + 1, vector<int>(T + 1, 0));

	int max_price = 0;
	for (int i = 1; i <= N; ++i) {
		const Data& d = datas[i];
		for (int k = 0; k <= T; ++k) {
			if (k + d.time <= T) {
				cache[i][d.time + k] = max(cache[i][d.time + k], cache[i - 1][k] + d.price);
				max_price = max(max_price, cache[i][d.time + k]);
			}

			cache[i][k] = max(cache[i][k], cache[i - 1][k]);
			max_price = max(max_price, cache[i][k]);
		}
	}

	cout << max(0, price_sum - max_price);

	return 0;
}