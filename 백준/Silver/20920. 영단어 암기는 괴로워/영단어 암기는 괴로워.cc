#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef struct _data {
	string str;
	int len;
	int appear;

	bool operator< (const _data& d) const {
		if (this->appear != d.appear) {
			return this->appear > d.appear;
		}

		if (this->len != d.len) {
			return this->len > d.len;
		}

		return this->str < d.str;
	}
} Data;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	unordered_map<string, int> exists;
	vector<Data> datas;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;

		if (str.size() < M) {
			continue;
		}

		if (exists.find(str) != exists.end()) {
			++datas[exists[str]].appear;
		}
		else {
			exists[str] = (int)datas.size();
			datas.push_back({ str, (int)str.size(), 1 });
		}
	}

	sort(datas.begin(), datas.end());

	for (const Data& data : datas) {
		cout << data.str << "\n";
	}

	return 0;
}