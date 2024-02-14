#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main(void) {
	long long K, N;
	scanf("%lld%lld", &K, &N);

	vector<long long> nums(K);
	for (long long& num : nums) {
		scanf("%lld", &num);
	}

	sort(nums.begin(), nums.end());

	unordered_set<long long> memory;
	priority_queue<long long, vector<long long>, greater<long long>> q;
	q.push(1);
	long long q_max = 1;

	for (int i = 0; i < N; ++i) {
		const long long mul = q.top();
		q.pop();

		for (const long long num : nums) {
			const long long target = mul * num;
			if ((long long)q.size() > N && q_max < target) {
				break;
			}

			if (memory.find(target) != memory.end()) {
				continue;
			}

			memory.insert(target);
			q_max = max(q_max, target);
			q.push(target);
		}
	}

	const long long result = q.top();
	printf("%lld\n", result);

	return 0;
}