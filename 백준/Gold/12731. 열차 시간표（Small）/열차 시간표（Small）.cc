#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct _data {
	int begin;
	int end;
	bool is_a;

	bool operator<(const struct _data& d) const {
		if (this->begin != d.begin) {
			return this->begin > d.begin;
		}

		return this->end > d.end;
	}
} Data;

int time_to_int(const string& str) {
	return ((str[0] - '0') * 10 + (str[1] - '0')) * 60 + ((str[3] - '0') * 10 + (str[4] - '0'));
}

void test_case(const int case_id) {
	int T;
	cin >> T;

	int NA, NB;
	cin >> NA >> NB;

	priority_queue<Data> train;
	priority_queue<int, vector<int>, greater<int>> a_wait, b_wait;

	for (int i = 0; i < NA; ++i) {
		string begin, end;
		cin >> begin >> end;

		train.push({ time_to_int(begin), time_to_int(end), true });
	}

	for (int i = 0; i < NB; ++i) {
		string begin, end;
		cin >> begin >> end;

		train.push({ time_to_int(begin), time_to_int(end), false });
	}

	int a_result = 0, b_result = 0;
	while (train.empty() == false) {
		const Data d = train.top();
		train.pop();

		if (d.is_a) {
			if (a_wait.empty() || a_wait.top() > d.begin) {
				++a_result;
				b_wait.push({ d.end + T });
			}
			else {
				a_wait.pop();
				b_wait.push({ d.end + T });
			}
		}
		else {
			if (b_wait.empty() || b_wait.top() > d.begin) {
				++b_result;
				a_wait.push({ d.end + T });
			}
			else {
				b_wait.pop();
				a_wait.push({ d.end + T });
			}
		}
	}

	cout << "Case #" << case_id << ": " << a_result << " " << b_result << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		test_case(i + 1);
	}

	return 0;
}