#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
	long long A, B, N;
	scanf("%lld%lld%lld", &A, &B, &N);

	long long remain = (A % B) * 10;

	vector<pair<long long, long long>> v;
	unordered_map<long long, long long> remain_appear;

	for (int idx = 0; ; ++idx) {
		/* 순환을 찾은 경우 */
		if (remain_appear.find(remain) != remain_appear.end()) {
			const long long cycle_begin = remain_appear[remain];
			const long long cycle_size = idx - cycle_begin;
			const long long target_cycle_offset = (N - cycle_begin + (cycle_size - 1)) % cycle_size;
			const long long target_idx = cycle_begin + target_cycle_offset;
			printf("%lld\n", v[target_idx].second);
			break;
		}
		/*******************/

		v.push_back({ remain, remain / B });
		remain_appear[remain] = idx;
		remain = (remain % B) * 10;

		/* 순환을 찾기 전에 직접 구한 경우 */
		if (idx == N - 1) {
			printf("%lld\n", v[v.size() - 1].second);
			break;
		}
		/**********************************/

		/* N번째 이전에 나누어 떨어지는 경우 */
		if (remain == 0) {
			printf("0\n");
			break;
		}
		/************************************/
	}

	return 0;
}