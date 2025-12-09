#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef struct _data {
	int num;
	int push_count;
} Data;

vector<bool> visit(100000, false);

int digit(int num) {
	int result = 0;
	while (num > 0) {
		++result;
		num /= 10;
	}

	return result;
}

inline int digit_min(const int num, const int dgt) {
	return num - (int)pow(10, dgt - 1);
}

int A(const int num) {
	return num + 1;
}

int B(const int num) {
	if (num == 0) {
		return 0;
	}

	return digit_min(num, digit(num));
}

int main(void) {
	int N, T, G;
	cin >> N >> T >> G;

	visit[N] = true;
	queue<Data> q;
	q.push({ N, 0 });

	while (q.empty() == false) {
		const Data d = q.front();
		q.pop();

		if (d.num == G) {
			cout << d.push_count << "\n";
			return 0;
		}

		if (d.push_count >= T) {
			continue;
		}

		const int a = A(d.num);
		if (a <= 99999 && visit[a] == false) {
			q.push({ a, d.push_count + 1 });
			visit[a] = true;
		}
		
		const int b = B(2 * d.num);
		if (2 * d.num <= 99999 && visit[b] == false) {
			q.push({ b, d.push_count + 1 });
			visit[b] = true;
		}
	}

	cout << "ANG\n";

	return 0;
}