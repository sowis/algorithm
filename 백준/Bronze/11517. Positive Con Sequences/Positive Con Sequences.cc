#include <cstdio>
#include <vector>

using namespace std;


// -1 -> no, not -1 -> target value
int is_arithmetic2(const vector<int>& v) {
	int target_index = -1;
	for (int i = 0; i < 4; ++i) {
		if (v[i] == -1) {
			target_index = i;
			break;
		}
	}

	if (target_index == 0) {
		const int hop = v[2] - v[1];
		if (v[3] - v[2] != hop) {
			return -1;
		}

		return v[1] - hop;
	}
	else if (target_index == 1) {
		const int hop = v[3] - v[2];
		if (v[2] - v[0] != 2 * hop) {
			return -1;
		}

		return v[0] + hop;
	}
	else if (target_index == 2) {
		const int hop = v[1] - v[0];
		if (v[3] - v[1] != 2 * hop) {
			return -1;
		}

		return v[1] + hop;
	}
	else if (target_index == 3) {
		const int hop = v[1] - v[0];
		if (v[2] - v[1] != hop) {
			return -1;
		}

		return v[2] + hop;
	}
	else {
		return -1;
	}
}

// -1 -> no, not -1 -> target value
int is_geometric2(const vector<int>& v) {
	int target_index = -1;
	for (int i = 0; i < 4; ++i) {
		if (v[i] == -1) {
			target_index = i;
			break;
		}
	}

	if (target_index == 0) {
		if (v[2] % v[1] != 0) {
			return -1;
		}

		const int hop = v[2] / v[1];
		if (v[2] * hop != v[3]) {
			return -1;
		}

		if (v[1] % hop != 0) {
			return -1;
		}

		return v[1] / hop;
	}
	else if (target_index == 1) {
		if (v[3] % v[2] != 0) {
			return -1;
		}

		const int hop = v[3] / v[2];
		if (v[0] * hop * hop != v[2]) {
			return -1;
		}

		return v[0] * hop;
	}
	else if (target_index == 2) {
		if (v[1] % v[0] != 0) {
			return -1;
		}

		const int hop = v[1] / v[0];
		if (v[1] * hop * hop != v[3]) {
			return -1;
		}

		return v[1] * hop;
	}
	else if (target_index == 3) {
		if (v[1] % v[0] != 0) {
			return -1;
		}

		const int hop = v[1] / v[0];
		if (v[1] * hop != v[2]) {
			return -1;
		}

		return v[2] * hop;
	}
	else {
		return -1;
	}
}

int solve(const vector<int>& v) {
	int result = is_arithmetic2(v);
	if (result < 1 || 10000 < result) {
		result = -1;
	}

	if (result == -1) {
		result = is_geometric2(v);
	}

	if (result < 1 || 10000 < result) {
		result = -1;
	}

	return result;
}


int main(void) {
	while (true) {
		vector<int> v(4);
		bool no_min_one = false;

		for (int& num : v) {
			scanf("%d", &num);
			if (num != -1) {
				no_min_one = true;
			}
		}

		if (no_min_one == false) {
			break;
		}

		const int result = solve(v);
		printf("%d\n", result);
	}

	return 0;
}