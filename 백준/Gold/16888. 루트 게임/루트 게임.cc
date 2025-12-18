#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int EMPTY = -1;
constexpr int TRUE = 1;
constexpr int FALSE = 0;

vector<int> perfect_squares;
vector<int> cache;

bool can_i_win(const int n) {
	int &c = cache[n];
	if (c != EMPTY) {
		return c;
	}

	if (find(perfect_squares.begin(), perfect_squares.end(), n) != perfect_squares.end()) { // 내가 바로 이길수있는경우
		return c = TRUE;
	}

	for (int i = 0; i < perfect_squares.size() && perfect_squares[i] < n; ++i) {
		if (can_i_win(n - perfect_squares[i]) == false) { // 상대가 못이기면
			return c = TRUE; // 내가 이김
		}
	}

	return c = FALSE; // 상대가 모든경우에 다 이기면 내가 짐
}

void test_case(void) {
	int N;
	cin >> N;

	if (can_i_win(N)) {
		cout << "koosaga\n";
	}
	else {
		cout << "cubelover\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 1; i * i < 1000001; ++i) {
		perfect_squares.push_back(i * i);
	}

	cache = vector<int>(1000001, EMPTY);
	
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}