#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

typedef struct _data {
	double dense;
	double volume;

	bool operator< (const struct _data& d) const {
		if (this->dense != d.dense) {
			return this->dense < d.dense;
		}

		return this->volume < d.volume;
	}
} Data;

int N;
vector<double> C, W;

double diff_sum(const double dense) {
	double result = 0;
	for (int i = 0; i < N; ++i) {
		result += abs(dense * C[i] - W[i]);
	}

	return result;
}

int main(void) {
	cin >> N;

	C = vector<double>(N);
	W = vector<double>(N);

	for (double& c : C) {
		cin >> c;
	}

	for (double& w : W) {
		cin >> w;
	}

	vector<Data> v(N);
	double volume_sum = 0;
	for (int i = 0; i < N; ++i) {
		v[i].dense = W[i] / C[i];
		v[i].volume = C[i];
		volume_sum += v[i].volume;
	}

	sort(v.begin(), v.end());

	const double half_volume = volume_sum / 2;
	double target_dense;
	double volume_psum = 0;

	for (const Data& d : v) {
		volume_psum += d.volume;
		if (volume_psum >= half_volume) {
			target_dense = d.dense;
			break;
		}
	}

	cout << fixed;
	cout.precision(10);
	cout << diff_sum(target_dense);

	return 0;
}