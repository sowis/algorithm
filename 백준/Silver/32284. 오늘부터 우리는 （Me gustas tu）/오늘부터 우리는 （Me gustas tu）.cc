#include <iostream>
#include <vector>

using namespace std;

int N, M;
int a, b;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	cin >> a >> b;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (x < b) {
				cout << 'E';
				continue;
			}

			if (x > b) {
				cout << 'W';
				continue;
			}

			if (y > a) {
				cout << 'N';
				continue;
			}

			cout << 'S';
		}
			cout << "\n";
	}

	return 0;
}