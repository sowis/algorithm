#include <iostream>
#include <vector>

using namespace std;

const vector<vector<long long>> DEFAULT_MAT{ {0, 1}, {1, 1} };
constexpr long long DIV = 1000000007;

vector<vector<long long>> mat_mul(const vector<vector<long long>> &m1, const vector<vector<long long>> &m2) {
	vector<vector<long long>> result(2, vector<long long>(2));
	result[0][0] = (m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0]) % DIV;
	result[0][1] = (m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1]) % DIV;
	result[1][0] = (m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0]) % DIV;
	result[1][1] = (m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1]) % DIV;
	return result;
}

vector<vector<long long>> N_mat(const long long n) {
	if (n == 1) {
		return DEFAULT_MAT;
	}

	const vector<vector<long long>> half = N_mat(n / 2);
	vector<vector<long long>> result = mat_mul(half, half);
	if (n % 2) {
		result = mat_mul(result, DEFAULT_MAT);
	}
	
	return result;
}

int main(void) {
	long long n;
	cin >> n;
	if (n % 2 == 0) {
		++n;
	}

	const vector<vector<long long>> mul = N_mat(n);
	long long result = mul[0][1] - 1;
	cout << result;

	return 0;
}