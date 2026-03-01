#include <iostream>
#include <vector>

using namespace std;

unsigned int N, M, K;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;

	vector<bool> visit(M + 1, false);
	vector<unsigned int> result;

	for (unsigned int target = 1; target <= M; ++target) {
		if (result.size() == N) {
			break;
		}

		if (visit[target]) {
			continue;
		}

		if ((target ^ K) <= M && visit[target ^ K]) {
			continue;
		}

		result.push_back(target);
		visit[target] = true;
	}

	if (result.size() == N) {
		for (const int num : result) {
			cout << num << " ";
		}
	}
	else {
		cout << -1;
	}

	return 0;
}