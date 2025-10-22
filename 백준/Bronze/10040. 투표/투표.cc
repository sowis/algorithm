#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;

	vector<int> A(N), B(M);
	for (int& cost : A) {
		cin >> cost;
	}

	for (int& criteria : B) {
		cin >> criteria;
	}

	vector<int> vote(N, 0);
	for (const int criteria : B) {
		for (int i = 0; i < N; ++i) {
			if (A[i] <= criteria) {
				++vote[i];
				break;
			}
		}
	}

	int max_vote = 0;
	int max_vote_index = 0;
	for (int i = 0; i < N; ++i) {
		if (max_vote < vote[i]) {
			max_vote = vote[i];
			max_vote_index = i;
		}
	}

	cout << max_vote_index + 1;

	return 0;
}