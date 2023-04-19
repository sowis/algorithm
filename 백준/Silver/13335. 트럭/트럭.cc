#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

int N, W, L;
vector<int> trucks;

int main(void) {
	scanf("%d%d%d", &N, &W, &L);

	trucks = vector<int>(N);
	for (int& truck : trucks) {
		scanf("%d", &truck);
	}

	int result = 0;
	int current_weight = 0;
	deque<int> bridge(W, 0);

	for (int i = 0; i < N;) {
		current_weight -= bridge.front();
		bridge.pop_front();

		if (current_weight + trucks[i] <= L) {
			bridge.push_back(trucks[i]);
			current_weight += trucks[i];
			++i;
		}
		else {
			bridge.push_back(0);
		}

		++result;
	}

	result += W;
	printf("%d\n", result);

	return 0;
}