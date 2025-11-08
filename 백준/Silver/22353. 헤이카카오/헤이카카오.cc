#include <iostream>

using namespace std;

int main(void) {
	double a, d, k;
	cin >> a >> d >> k;

	double win_rate = d / 100; // 현재 시행횟수에서 승리할 확률
	double arrival_rate = 1; // 이전에 모두 실패하고 이 시행횟수에 도달할 확률
	int implement_count = 1; // 시행횟수
	double result = 0; // 결과(기댓값)
	while (true) {
		if (win_rate >= 1) { // 승률이 100% 넘으면 100%로 고정
			win_rate = 1;
		}

		result += a * implement_count * arrival_rate * win_rate; // 현재 승리했을 경우

		if (win_rate >= 1) { // 승률 100%인 경우 종료
			break;
		}

		arrival_rate *= (1 - win_rate); // 실패할 확률
		win_rate *= (100 + k) / 100; // 실패시 승률 증가
		++implement_count;
	}

	cout << fixed;
	cout.precision(7);
	cout << result;

	return 0;
}