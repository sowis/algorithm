#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	int begin;
	int end;

	bool operator<(const struct _data& d) const {
		if (this->end != d.end) {
			return this->end < d.end;
		}

		return this->begin < d.begin;
	}
} Data;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int case_num = 1;
	int p;

	while (true) {
		cin >> p;
		if (p == 0) {
			break;
		}

		vector<Data> parties(p);
		for (Data& party : parties) {
			cin >> party.begin >> party.end;
			party.begin *= 2;
			party.end *= 2;
		}

		sort(parties.begin(), parties.end());
		int party_count = 0;
		vector<bool> visit(p, false);
		vector<bool> time_slot(50, false);
		for (int i = 0; i < p; ++i) {
			for (int k = 0; k < p; ++k) {
				if (visit[k]) {
					continue;
				}

				const Data& party = parties[k];
				for (int time = party.begin; time < party.end; ++time) {
					if (time_slot[time]) {
						continue;
					}

					time_slot[time] = true;
					++party_count;
					visit[k] = true;
					break;
				}

				visit[k] = true;
			}
		}

		cout << "On day " << case_num << " Emma can attend as many as " << party_count << " parties.\n";

		++case_num;
	}

	return 0;
}