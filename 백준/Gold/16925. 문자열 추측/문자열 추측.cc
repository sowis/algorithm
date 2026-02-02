#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	int idx;
	string str;
	char type;
} Data;

typedef struct _cmp1 {
	bool operator()(const Data& d1, const Data& d2) const {
		return d1.str.size() > d2.str.size();
	}
} cmp1;

typedef struct _cmp2 {
	bool operator()(const Data& d1, const Data& d2) const {
		return d1.idx < d2.idx;
	}
} cmp2;

bool is_prefix(const string& pre, const string& str) {
	if (pre.size() > str.size()) {
		return false;
	}

	for (int i = 0; i < pre.size(); ++i) {
		if (pre[i] != str[i]) {
			return false;
		}
	}

	return true;
}

bool is_postfix(const string& post, const string& str) {
	if (post.size() > str.size()) {
		return false;
	}

	for (int i = 0; i < post.size(); ++i) {
		if (post[post.size() - 1 - i] != str[str.size() - 1 - i]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N;
	cin >> N;

	vector<Data> v(2 * N - 2);
	for (int i = 0; i < 2 * N - 2; ++i) {
		v[i].idx = i;
		cin >> v[i].str;
	}

	if (N == 2) {
		cout << v[0].str << v[1].str << "\n";
		cout << "PS\n";
		return 0;
	}

	sort(v.begin(), v.end(), cmp1());

	vector<string> nominees(4);
	nominees[0] += v[0].str;
	nominees[0] += v[v.size() - 2].str;
	nominees[1] += v[1].str;
	nominees[1] += v[v.size() - 2].str;
	nominees[2] += v[0].str;
	nominees[2] += v[v.size() - 1].str;
	nominees[3] += v[1].str;
	nominees[3] += v[v.size() - 1].str;

	for (const string& target : nominees) {
		bool ok = true;
		for (int i = 0; i < v.size(); i += 2) {
			if (is_prefix(v[i].str, target) && is_postfix(v[i + 1].str, target)) {
				v[i].type = 'P';
				v[i + 1].type = 'S';
			}
			else if (is_prefix(v[i + 1].str, target) && is_postfix(v[i].str, target)) {
				v[i].type = 'S';
				v[i + 1].type = 'P';
			}
			else {
				ok = false;
				break;
			}
		}

		if (ok) {
			cout << target << "\n";
			break;
		}
	}

	sort(v.begin(), v.end(), cmp2());

	for (const Data& d : v) {
		cout << d.type;
	}


	return 0;
}