#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N;
	cin >> N;

	vector<int> skills_v(N);
	unordered_map<int, int> skills_h;

	for (int i = 0; i < N; ++i) {
		int skill;
		cin >> skill;

		skills_v[i] = skill;
		++skills_h[skill];
	}

	long long result = 0;
	for (int i = 0; i < N; ++i) {
		for (int k = i + 1; k < N; ++k) {
			const int target = (skills_v[i] + skills_v[k]) * -1;
			if (skills_v[i] == skills_v[k] && target == skills_v[i]) {
				result += max(0, skills_h[target] - 2);
			}
			else if (skills_v[i] == target || skills_v[k] == target) {
				result += max(0, skills_h[target] - 1);
			}
			else {
				result += skills_h[target];
			}
		}
	}

	cout << result / 3 << "\n";

	return 0;
}