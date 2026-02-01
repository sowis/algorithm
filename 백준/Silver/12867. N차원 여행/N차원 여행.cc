#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;
vector<pair<int, char>> indexes;

bool is_come_back(const int begin, const int end) {
	unordered_map<int, int> count;
	for (int i = begin; i < end; ++i) {
		if (indexes[i].second == '+') {
			++count[indexes[i].first];
		}
		else {
			--count[indexes[i].first];
		}
	}

	for (const pair<int, int>& p : count) {
		if (p.second != 0) {
			return false;
		}
	}

	return true;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> M;

	indexes = vector<pair<int, char>>(M);
	for (pair<int, char> & idx : indexes) {
		cin >> idx.first;
	}

	for (pair<int, char>& idx : indexes) {
		cin >> idx.second;
	}

	for (int begin = 0; begin <= M; ++begin) {
		for (int end = begin + 1; end <= M; ++end) {
			if (is_come_back(begin, end)) { // 중복방문이 한번이라도 있으면
				cout << 0;
				return 0;
			}
		}
	}

	cout << 1;

	return 0;
}