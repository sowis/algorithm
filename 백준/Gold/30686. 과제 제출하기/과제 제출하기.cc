#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> D;
int result = 1987654321;
vector<vector<int>> needs;

void solve(vector<bool>& visit, const vector<int> &remain, const int check_count = 0, const int study_count = 0) {
	if (check_count >= M) {
		result = min(result, study_count);
		return;
	}

	for (int i = 0; i < M; ++i) {
		if (visit[i]) {
			continue;
		}

		visit[i] = true;
		int additional_study = 0;
		vector<int> next_remain = remain;
		for (const int need : needs[i]) {
			if (next_remain[need] == 0) {
				next_remain[need] = D[need];
				++additional_study;
			}
		}

		for (int& next : next_remain) {
			if (next > 0) {
				--next;
			}
		}
		
		if (study_count + additional_study >= result) {
			visit[i] = false;
			continue;
		}

		solve(visit, next_remain, check_count + 1, study_count + additional_study);

		visit[i] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	D = vector<int>(N);
	for (int i = 0; i < N; ++i) {
		cin >> D[i];
	}

	needs = vector<vector<int>>(M);

	for (int i = 0; i < M; ++i) {
		int k;
		cin >> k;

		for (int j = 0; j < k; ++j) {
			int a;
			cin >> a;
			--a;

			needs[i].push_back(a);
		}
	}
	
	vector<bool> visit(M, false);
	vector<int> remain(N, 0);
	solve(visit, remain);

	cout << result;

	return 0;
}