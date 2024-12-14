#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int K;
	cin >> K;

	int N;
	cin >> N;

	int cur_id = K;
	int cur_time = 0;
	for (int i = 0; i < N; ++i) {
		int t;
		char op;

		cin >> t >> op;
		cur_time += t;

		if (cur_time > 200) {
			break;
		}

		if (op == 'T') {
			++cur_id;
			
			if (cur_id == 9) {
				cur_id = 1;
			}
		}
	}

	cout << cur_id;

	return 0;
}