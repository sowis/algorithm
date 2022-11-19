#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int op;
	int first;
	int second;
} Query;

int parents[200001];
vector<int> union_find(200001, -1);

int uf_get_head(const int target) {
	if (union_find[target] == -1 || union_find[target] == target) {
		return union_find[target] = target;
	}

	return union_find[target] = uf_get_head(union_find[target]);
}

void uf_merge(const int target_a, const int target_b) {
	const int head_a = uf_get_head(target_a);
	const int head_b = uf_get_head(target_b);

	union_find[head_b] = head_a;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, Q;
	cin >> N >> Q;

	/* 부모가 누군지 기억 */
	for (int i = 2; i <= N; ++i) {
		cin >> parents[i];
	}
	/**********************/

	/* 쿼리 저장 */
	vector<Query> queries;
	for (int i = 0; i < N - 1 + Q; ++i) {
		int x;
		cin >> x;

		if (x == 0) {
			int b;
			cin >> b;

			queries.push_back({ x, b, -1 });
		}
		else if (x == 1) {
			int c, d;
			cin >> c >> d;

			queries.push_back({ x, c, d });
		}
	}
	/*************/

	/* 쿼리 역순으로 실행 */
	vector<bool> results;
	for (int i = (int)queries.size() - 1; i >= 0; --i) {
		const Query& q = queries[i];
		
		if (q.op == 0) {
			uf_merge(parents[q.first], q.first);
		}
		else {
			const register bool result = uf_get_head(q.first) == uf_get_head(q.second);
			results.push_back(result);
		}
	}
	/*********************/

	/* 결과 출력 */
	for (int i = (int)results.size() - 1; i >= 0; --i) {
		if (results[i]) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	/*************/

	return 0;
}