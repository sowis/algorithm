#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct _data {
	int cal;
	int price;
} Data;

int N, M;
vector<int> cache;

int main(void) {
	while (true) {
		double m;

		cin >> N >> m;
		M = (int)round(m * 100);

		if (N == 0 && M == 0) {
			break;
		}

		vector<Data> datas;
		for (int i = 0; i < N; ++i) {
			int c;
			double p;
			cin >> c >> p;

			datas.push_back({ c, (int)round(p * 100) });
		}

		cache = vector<int>(M + 1, 0); // [x]원으로 구할 수 있는 최대 가치
		for (int i = 0; i < N; ++i) {
			for (int money = datas[i].price; money <= M; ++money) {
				cache[money] = max(cache[money], cache[money - datas[i].price] + datas[i].cal);
			}
		}

		cout << cache[M] << "\n";
	}

	return 0;
}