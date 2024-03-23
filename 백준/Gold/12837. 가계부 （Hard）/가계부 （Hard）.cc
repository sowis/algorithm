#include <iostream>
using namespace std;
const int MAX = 1000000;

int n, q;
long long tree[MAX * 4];

void update(int index, int target, int value, int start, int end) {
	if (target < start || target > end)return;
	tree[index] += value;
	if (start != end) {
		int mid = (start + end) / 2;
		update(index * 2, target, value, start, mid);
		update(index * 2 + 1, target, value, mid + 1, end);
	}
}

long long query(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[index];
	else {
		int mid = (start + end) / 2;
		return query(index * 2, left, right, start, mid) + query(index * 2 + 1, left, right, mid + 1, end);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;

	int a, b, c;
	while (q--) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, b, c, 1, n);
		}
		else {
			cout << query(1, b, c, 1, n) << '\n';
		}
	}

	return 0;
}