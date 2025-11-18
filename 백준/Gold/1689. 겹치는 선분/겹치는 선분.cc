#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	int pos;
	int value;

	bool operator<(const struct _data& d) {
		if (this->pos == d.pos) { // 같은좌표에서 먼저 선분개수에 뺀다음에 더해줘야 오류발생x
			return this->value < d.value;
		}

		return this->pos < d.pos;
	}
} Data;

int N;
vector<Data> v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int begin, end;
		cin >> begin >> end;

		v.push_back({ begin, 1 });
		v.push_back({ end, -1 });
	}

	sort(v.begin(), v.end());

	int result = 0;
	int cur = 0;
	for (const Data& d : v) {
		cur += d.value;
		result = max(result, cur);
	}

	cout << result;

	return 0;
}