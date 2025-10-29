#include <iostream>
#include <vector>
#include <string>

using namespace std;

int time_to_min(const string& time_s) {
	string time_h;
	time_h += time_s[0];
	time_h += time_s[1];

	const int hour = stoi(time_h) % 12;

	string time_m;
	time_m += time_s[3];
	time_m += time_s[4];

	const int min = stoi(time_m) % 60;

	return hour * 60 + min;
}

int get_area_index(int time) {
	time %= 720;
	return time / 120;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string time_s;
	cin >> time_s;

	int cur_time = time_to_min(time_s);
	vector<bool> area_disabled(6, false);
	vector<int> area(6);

	for (int& heal_point : area) {
		cin >> heal_point;
	}

	int L;
	cin >> L;

	for (int i = 0; i < L; ++i) {
		double t;
		string op;

		cin >> t >> op;

		if (t >= 60) {
			break;
		}

		if (op == "^") {
			area_disabled[get_area_index(cur_time)] = true;
		}
		else if (op == "10MIN") {
			cur_time += 10;
			cur_time %= 720;
		}
		else if (op == "30MIN") {
			cur_time += 30;
			cur_time %= 720;
		}
		else if (op == "50MIN") {
			cur_time += 50;
			cur_time %= 720;
		}
		else if (op == "2HOUR") {
			cur_time += 120;
			cur_time %= 720;
		}
		else if (op == "4HOUR") {
			cur_time += 240;
			cur_time %= 720;
		}
		else if (op == "9HOUR") {
			cur_time += 540;
			cur_time %= 720;
		}
	}

	int result = 0;
	for (int i = 0; i < 6; ++i) {
		if (area_disabled[i]) {
			continue;
		}

		result += area[i];
	}

	if (result > 100) {
		result = 100;
	}

	cout << result;

	return 0;
}