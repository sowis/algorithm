#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

typedef struct _data {
	long long weight;
	long long price;

	bool operator< (const struct _data& d) const {
		if (this->price != d.price) {
			return this->price < d.price;
		}
		
		return this->weight > d.weight;
	}
} Data;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<Data> meats(N);
	for (Data& meat : meats) {
		cin >> meat.weight >> meat.price;
	}

	sort(meats.begin(), meats.end());

	long long weight_sum = 0;
	long long last_price = -1;
	long long current_price_count = 0;
	long long same_price_weight_sum = 0;
	long long result = numeric_limits<long long>::max();

	for (const Data& meat : meats) {
		if (meat.price > last_price) {
			last_price = meat.price;
			current_price_count = 1;
			weight_sum += same_price_weight_sum;
			same_price_weight_sum = meat.weight;
		}
		else {
			++current_price_count;
			same_price_weight_sum += meat.weight;
		}

		if (weight_sum + same_price_weight_sum >= M) {
			result = min(result, meat.price * current_price_count);
		}
	}

	if (result > numeric_limits<int>::max()) {
		result = -1;
	}

	cout << result;

	return 0;
}