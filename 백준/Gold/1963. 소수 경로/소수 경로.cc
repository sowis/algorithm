#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <string>

#define number first
#define dist second

using namespace std;

typedef pair<int, int> Data;

vector<bool> is_prime(10001, true);

vector<int> get_next_primes(const int num) {
	vector<int> results;
	string str_num = to_string(num);

	for (char& c : str_num) {
		const char begin_c = c;
		for (char change = '0'; change <= '9'; ++change) {
			c = change;
			const int int_num = stoi(str_num);
			if (is_prime[int_num]) {
				results.push_back(int_num);
			}
		}

		c = begin_c;
	}

	return results;
}

int main(void) {
	for (int i = 2; i < (int)sqrt(10001) + 1; ++i) {
		if (is_prime[i] == false) {
			continue;
		}

		for (int mul = 2; i * mul < 10001; ++mul) {
			is_prime[i * mul] = false;
		}
	}

	int T;
	scanf("%d", &T);

	vector<int> distances(10001);
	for (int i = 0; i < T; ++i) {
		int source, target;
		scanf("%d%d", &source, &target);

		fill(distances.begin(), distances.end(), 987654321);

		queue<Data> q;
		q.push({ source, 0 });
		distances[source] = 0;

		while (q.empty() == false) {
			const Data d = q.front();
			q.pop();

			const int next_dist = d.dist + 1;
			const vector<int> nexts = get_next_primes(d.number);

			for (const int next : nexts) {
				if (distances[next] <= next_dist) {
					continue;
				}

				distances[next] = next_dist;
				q.push({ next, next_dist });
			}
		}

		if (distances[target] == 987654321) {
			printf("Impossible\n");
		}
		else {
			printf("%d\n", distances[target]);
		}
	}

	return 0;
}