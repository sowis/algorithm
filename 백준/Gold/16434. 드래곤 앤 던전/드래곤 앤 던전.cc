#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	long long t;
	long long a;
	long long h;
} Data;

long long N, ATK;
vector<Data> rooms;

bool can_beat(const long long max_hp) {
	long long atk = ATK;
	long long cur_hp = max_hp;

	for (const Data& room : rooms) {
		if (room.t == 1) { // 몬스터
			const long long monster_atk = room.a;
			const long long monster_hp = room.h;
			const long long hit_turn = (monster_hp % atk) ? monster_hp / atk + 1 : monster_hp / atk;
			cur_hp -= (hit_turn - 1) * monster_atk;
			if (cur_hp <= 0) {
				return false;
			}
		}
		else { // 포션
			atk += room.a;
			cur_hp = min(cur_hp + room.h, max_hp);
		}
	}

	return true;
}

int main(void) {
	cin >> N >> ATK;

	for (int i = 0; i < N; ++i) {
		long long t, a, h;
		cin >> t >> a >> h;
		rooms.push_back({ t, a, h });
	}

	long long left = 1;
	long long right = (long long)1e18;
	long long max_ok = right;

	while (left <= right) {
		const long long mid = (left + right) / 2;

		if (can_beat(mid)) {
			max_ok = min(max_ok, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << max_ok;

	return 0;
}