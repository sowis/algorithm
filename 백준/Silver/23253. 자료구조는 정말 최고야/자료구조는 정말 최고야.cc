#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<vector<int>> books(M);
	for (int i = 0; i < M; ++i) {
		int K;
		scanf("%d", &K);

		books[i] = vector<int>(K);
		for (int& n : books[i]) {
			scanf("%d", &n);
		}
	}

	unordered_map<int, vector<int>*> head;
	for (vector<int>& v : books) {
		head[v.back()] = &v;
	}

	for (int target = 1; target <= N; ++target) {
		if (head.find(target) == head.end()) {
			printf("No\n");
			return 0;
		}

		vector<int> *v = head[target];
		head.erase(target);

		v->pop_back();
		if (v->empty() == false) {
			head[v->back()] = v;
		}
	}

	printf("Yes\n");

	return 0;
}