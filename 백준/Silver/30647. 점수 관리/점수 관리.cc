#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct _data {
	string name;
	int score;
	bool ishidden;
	int rank;

	bool operator<(const struct _data& d) const {
		if (this->score != d.score) {
			return this->score > d.score;
		}

		return this->name < d.name;
	}

} Data;

int main(void) {
	int N;
	cin >> N;

	vector<Data> datas;

	bool first_line = true;
	for (int i = 0; i < N; ++i) {
		string line;
		cin >> line;

		int cursor = 9;
		if (first_line) {
			++cursor;
			first_line = false;
		}

		string name;
		while (line[cursor] != '"') {
			name += line[cursor];
			++cursor;
		}

		cursor += 10;
		string score;
		while (line[cursor] != ',') {
			score += line[cursor];
			++cursor;
		}

		cursor += 12;
		bool hidden = line[cursor] == '1';

		datas.push_back(Data{ name, stoi(score), hidden, -1 });
	}

	sort(datas.begin(), datas.end());

	int cur_rank = 1;
	for (int i = 0; i < N; ++i) {
		if (datas[i].rank != -1) {
			continue;
		}

		datas[i].rank = cur_rank;
		int rank_size = 1;
		for (int k = i + 1; k < N; ++k) {
			if (datas[i].score != datas[k].score) {
				break;
			}

			datas[k].rank = cur_rank;
			++rank_size;
		}

		cur_rank += rank_size;
	}

	for (int i = 0; i < N; ++i) {
		if (datas[i].ishidden) {
			continue;
		}

		cout << datas[i].rank << " " << datas[i].name << " " << datas[i].score << "\n";
	}

	return 0;
}