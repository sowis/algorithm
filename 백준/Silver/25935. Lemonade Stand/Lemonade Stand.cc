#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int sale_count;
	int lemon_price;
	int sugar_80_price;
} Day;

void test_case(void) {
	int d, x, s;
	cin >> d >> x >> s;

	vector<Day> days(d);
	for (Day& day : days) {
		cin >> day.sale_count >> day.lemon_price >> day.sugar_80_price;
	}

	int result = 0;
	int current_lemon = 0; // 레몬 재고 (개)
	int current_sugar = 0; // 설탕 재고 (온즈)
	for (int i = 0; i < d; ++i) {
		const Day& today = days[i];

		/* 레몬 구입여부 결정 */
		int require_lemon = 0;
		for (int next_lemon_min_price_day = i; next_lemon_min_price_day < d; ++next_lemon_min_price_day) {
			if (today.lemon_price > days[next_lemon_min_price_day].lemon_price) {
				break;
			}

			require_lemon += x * days[next_lemon_min_price_day].sale_count;
		}

		if (current_lemon < require_lemon) { // 현재 레몬 재고량이 이후 레몬이 싸질때까지 못버티면 레몬 구입
			const int buy_lemon = require_lemon - current_lemon;
			current_lemon += buy_lemon;
			result += buy_lemon * today.lemon_price;
		}
		/**********************/


		/* 설탕 구입여부 결정 */
		int require_sugar = 0; // 온즈 단위
		for (int next_sugar_min_price_day = i; next_sugar_min_price_day < d; ++next_sugar_min_price_day) {
			if (today.sugar_80_price > days[next_sugar_min_price_day].sugar_80_price) {
				break;
			}

			require_sugar += s * days[next_sugar_min_price_day].sale_count;
		}

		if (current_sugar < require_sugar) { // 현재 설탕 재고량이 이후 설탕이 싸질때까지 못버티면 설탕 구입. 설탕은 80온즈 단위
			int buy_sugar = require_sugar - current_sugar;
			buy_sugar = (buy_sugar % 80) ? (buy_sugar / 80 + 1) : (buy_sugar / 80); // buy_suger == 봉지(80온즈) 단위
			current_sugar += buy_sugar * 80;
			result += buy_sugar * today.sugar_80_price;
		}
		/**********************/

		/* 그날 재고 소진 */
		current_lemon -= today.sale_count * x;
		current_sugar -= today.sale_count * s;
		/*****************/
	}

	cout << result << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}