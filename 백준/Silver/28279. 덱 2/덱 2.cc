#include <cstdio>
#include <deque>

using namespace std;

int main(void) {
	deque<int> d;

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int op;
		scanf("%d", &op);

		if (op == 1) {
			int num;
			scanf("%d", &num);

			d.push_front(num);
		}
		else if (op == 2) {
			int num;
			scanf("%d", &num);

			d.push_back(num);
		}
		else if (op == 3) {
			if (d.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", d.front());
				d.pop_front();
			}
		}
		else if (op == 4) {
			if (d.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", d.back());
				d.pop_back();
			}
		}
		else if (op == 5) {
			printf("%zd\n", d.size());
		}
		else if (op == 6) {
			printf("%d\n", d.empty() ? 1 : 0);
		}
		else if (op == 7) {
			if (d.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", d.front());
			}
		}
		else if (op == 8) {
			if (d.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", d.back());
			}
		}
	}

	return 0;
}