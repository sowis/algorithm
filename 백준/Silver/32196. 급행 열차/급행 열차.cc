#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N, M, K, X, Y;

typedef struct _data {
	long long A;
	long long B;
	
	bool operator< (const struct _data& d) const {
		return X * this->A - Y * this->B < X * d.A - Y * d.B;
	}
} Data;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K >> X >> Y;

	vector<Data> datas(N);
	for (Data& data : datas) {
		cin >> data.A >> data.B;
	}

	sort(datas.begin(), datas.end());

	long long local = K, express = K;
	for (int i = 0; i < M; ++i) {
		local += datas[i].A;
		express -= datas[i].B;
	}

	cout << local * X + express * Y;

	return 0;
}