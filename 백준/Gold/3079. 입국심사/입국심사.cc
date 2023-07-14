#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

bool parametric_search(const vector<long long>& T, const long long number_of_people, const long long time_limit) {
	long long people_sum = 0;
	for (const long long t : T) {
		people_sum += time_limit / t;
	}

	return people_sum >= number_of_people;
}

int main(void) {
	long long N, M;
	scanf("%lld%lld", &N, &M);

	vector<long long> T(N);
	for (long long& t : T) {
		scanf("%lld", &t);
	}

	long long left = 1;
	long long right = (*min_element(T.begin(), T.end())) * M;
	long long last_ok = right;

	while (left <= right) {
		const long long mid = left + (right - left) / 2;
		if (parametric_search(T, M, mid)) {
			last_ok = min(last_ok, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	printf("%lld\n", last_ok);

	return 0;
}