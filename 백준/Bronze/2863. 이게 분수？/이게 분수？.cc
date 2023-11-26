#include <cstdio>
#include <vector>

using namespace std;

void rotate(vector<double>& v) {
	const double tmp = v[0];
	v[0] = v[2];
	v[2] = v[3];
	v[3] = v[1];
	v[1] = tmp;
}

inline double calc(const vector<double>& v) {
	return v[0] / v[2] + v[1] / v[3];
}

int main(void) {
	vector<double> v(4);
	for (double& d : v) {
		scanf("%lf", &d);
	}

	int result = 0;
	double val = 0;

	for (int r = 0; r < 4; ++r) {
		if (calc(v) > val) {
			val = calc(v);
			result = r;
		}

		rotate(v);
	}

	printf("%d\n", result);

	return 0;
}