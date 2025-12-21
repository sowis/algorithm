#include <iostream>
#include <vector>

using namespace std;

constexpr long long DIV = 1000000007;

typedef struct _mat {
	long long a, b, c, d;
} Mat;

const Mat default_fibo{ 0, 1, 1, 1 };

inline Mat mat_mul(const Mat& m1, const Mat& m2) {
	return { (m1.a * m2.a + m1.b * m2.c) % DIV, (m1.a * m2.b + m1.b * m2.d) % DIV, (m1.c * m2.a + m1.d * m2.b) % DIV, (m1.c * m2.b + m1.d * m2.d) % DIV };
}

Mat fibo(const long long n) {
	if (n == 1) {
		return default_fibo;
	}

	const Mat half = fibo(n / 2);
	Mat result = mat_mul(half, half);
	if (n % 2) {
		result = mat_mul(result, default_fibo);
	}

	return result;
}

int main(void) {
	long long N;
	cin >> N;

	const long long target_fibo = ((N + 1) / 2) * 2;
	const long long result = fibo(target_fibo).b;
	cout << result;

	return 0;
}