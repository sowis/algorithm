#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef struct _data {
	long long pos;
	long long dist;
} Data;

int main(void) {
	long long N, K;
	cin >> N >> K;

	vector<long long> sams(N);
	unordered_set<long long> visit;
	for (long long& sam : sams) {
		cin >> sam;
		visit.insert(sam);
	}

	queue<Data> q;
	for (const long long sam : sams) {
		if (visit.find(sam - 1) == visit.end()) {
			q.push({ sam - 1, 1 });
			visit.insert(sam - 1);
		}

		if (visit.find(sam + 1) == visit.end()) {
			q.push({ sam + 1, 1 });
			visit.insert(sam + 1);
		}
	}

	long long count = 0;
	long long result = 0;
	
	while (q.empty() == false && count < K) {
		const Data d = q.front();
		q.pop();

		++count;
		result += d.dist;

		if (visit.find(d.pos - 1) == visit.end()) {
			q.push({ d.pos - 1, d.dist + 1 });
			visit.insert(d.pos - 1);
		}

		if (visit.find(d.pos + 1) == visit.end()) {
			q.push({ d.pos + 1, d.dist + 1 });
			visit.insert(d.pos + 1);
		}
	}

	cout << result;

	return 0;
}