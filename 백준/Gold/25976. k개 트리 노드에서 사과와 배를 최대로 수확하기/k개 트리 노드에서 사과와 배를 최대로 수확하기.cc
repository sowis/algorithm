#include <iostream>
#include <vector>

#define APPLE first
#define PEAR second

using namespace std;

constexpr pair<int, int> fruit_data[3]{ {0, 0}, {1, 0}, {0, 1} };

int N, K;
vector<int> edges[18];
vector<pair<int, int>> node_fruit;
int result_apple = 0;
int result_pear = 0;

void set_max(const int apple, const int pair) {
	if (apple * pair > result_apple * result_pear) {
		result_apple = apple;
		result_pear = pair;
		return;
	}

	if (apple * pair < result_apple * result_pear) {
		return;
	}

	if (apple > result_apple) {
		result_apple = apple;
		result_pear = pair;
		return;
	}

	if (apple < result_apple) {
		return;
	}

	if (pair > result_pear) {
		result_apple = apple;
		result_pear = pair;
		return;
	}
}

void validate(const vector<bool>& visit, vector<bool>& to_validate, int cur = 0) {
	to_validate[cur] = true;
	for (const int next : edges[cur]) {
		if (visit[next] == false) {
			continue;
		}

		if (to_validate[next] == false) {
			validate(visit, to_validate, next);
		}
	}
}

bool validate(const vector<bool>& visit) {
	vector<bool> to_validate(N, false);
	if (visit[0] == false) {
		return false;
	}

	validate(visit, to_validate);

	for (int i = 0; i < N; ++i) {
		if (visit[i] != to_validate[i]) {
			return false;
		}
	}

	return true;
}

void solve(vector<bool>& visit, int apple, int pear, const int cur = 1, const int visit_count = 1) {
	if (visit_count == K) {
		if (validate(visit)) {
			set_max(apple, pear);
		}

		return;
	}

	if (cur == N) {
		return;
	}

	solve(visit, apple, pear, cur + 1, visit_count);
	visit[cur] = true;
	solve(visit, apple + node_fruit[cur].APPLE, pear + node_fruit[cur].PEAR, cur + 1, visit_count + 1);
	visit[cur] = false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	for (int i = 0; i < N - 1; ++i) {
		int node_1, node_2;
		cin >> node_1 >> node_2;

		edges[node_1].push_back(node_2);
		edges[node_2].push_back(node_1);
	}

	node_fruit = vector<pair<int, int>>(N);
	for (int i = 0; i < N; ++i) {
		int fruit_op;
		cin >> fruit_op;

		node_fruit[i] = fruit_data[fruit_op];
	}

	vector<bool> visit(N, false);
	visit[0] = true;
	solve(visit, node_fruit[0].APPLE, node_fruit[0].PEAR);

	cout << result_apple << " " << result_pear;

	return 0;
}