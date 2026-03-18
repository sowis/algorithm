#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<pair<int, int>> line;
vector<bool> visit;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> S;

	line = vector<pair<int, int>>(N + 1);
	for (int i = 1; i <= N; ++i) {
		int q, v;
		cin >> q >> v;

		line[i] = { q, v };
	}

	visit = vector<bool>(N + 1, false);
	int pos = S;
	int power = 1;
	int direction = 1;
	int result = 0;
	int move_count = 0;
	while (1 <= pos && pos <= N && move_count < 10000000) {
		if (line[pos].first == 0) { // 점프패드
			direction *= -1;
			power += line[pos].second;
		}
		else { // 타겟
			if (visit[pos] == false && line[pos].second <= power) {
				visit[pos] = true;
				++result;
			}
		}

		pos += direction * power;
		++move_count;
	}

	cout << result;

	return 0;
}