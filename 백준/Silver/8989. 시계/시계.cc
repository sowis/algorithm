#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	string time_s;
	int time;
	int angle;

	bool operator< (const struct _data& d) const {
		if (this->angle == d.angle) {
			return this->time < d.time;
		}

		return this->angle < d.angle;
	}
} Data;

pair<int, int> get_angle_2(const string& time_s) { // 시간(분단위), 시침과 분침 사이의 작은쪽 각도 * 2 반환
	string str_h;
	str_h += time_s[0];
	str_h += time_s[1];
	const int h = stoi(str_h);

	string str_m;
	str_m += time_s[3];
	str_m += time_s[4];
	const int m = stoi(str_m);

	const int angle_m = (12 * m) % 720;
	const int angle_h = (60 * h + m) % 720;

	return { 60 * h + m, min((angle_m - angle_h + 720) % 720, (angle_h - angle_m + 720) % 720) };
}

void test_case(void) {
	vector<Data> times;
	for (int i = 0; i < 5; ++i) {
		string time_s;
		cin >> time_s;

		const pair<int, int> d = get_angle_2(time_s);
		times.push_back({ time_s, d.first, d.second });
	}

	sort(times.begin(), times.end());
	cout << times[2].time_s << "\n";
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