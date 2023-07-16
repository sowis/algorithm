#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

typedef struct _data {
	long long monitor_count;
	long long buffer_count;

	bool operator<=(const struct _data d) const {
		if (this->monitor_count <= d.monitor_count && this->buffer_count <= d.buffer_count) {
			return true;
		}

		return false;
	}
} Data;

vector<list<Data>> cache(102);

void data_insert(list<Data>& v, const Data& d) {
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (d <= *it) {
			return;
		}
		
		if (*it <= d) {
			it = v.erase(it);

			if (it != v.begin()) {
				--it;
			}

			if (it == v.end()) {
				break;
			}
		}
	}

	v.push_back(d);
}

int main(void) {
	long long N;
	scanf("%lld", &N);

	data_insert(cache[1], { 1, 0 });
	for (long long button = 1; button < N; ++button) {
		for (const Data& d : cache[button]) {
			/* A 누르기 */
			data_insert(cache[button + 1], { d.monitor_count + 1, d.buffer_count });
			/************/

			/* ctrl-V 누르기 */
			data_insert(cache[button + 1], { d.monitor_count + d.buffer_count, d.buffer_count });
			/*****************/

			/* ctrl-A, ctrl-C 누르기 */
			data_insert(cache[button + 2], { d.monitor_count, d.monitor_count });
			/*************************/
		}
	}

	long long result = 0;
	for (const Data& d : cache[N]) {
		result = max(result, d.monitor_count);
	}

	printf("%lld\n", result);

	return 0;
}