#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, L;
	cin >> N >> L;

	int max_stripe = 0;
	int max_stripe_count = 0;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;

		int last = -1;
		int stripe_count = 0;
		for (const char& c : str) {
			if (c == '1' && last != c) {
				++stripe_count;
			}
			
			last = c;
		}

		if (max_stripe < stripe_count) {
			max_stripe = stripe_count;
			max_stripe_count = 1;
		}
		else if (max_stripe == stripe_count) {
			++max_stripe_count;
		}
	}

	cout << max_stripe << " " << max_stripe_count;

	return 0;
}