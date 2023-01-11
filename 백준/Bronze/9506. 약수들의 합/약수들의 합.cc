#include <cstdio>
#include <vector>

using namespace std;

vector<int> get_divisors(const int num) {
	vector<int> result;
	for (int i = 1; i < num; ++i) {
		if (num % i == 0) {
			result.push_back(i);
		}
	}

	return result;
}

int main(void) {
	int input;

	while (true) {
		scanf("%d", &input);
		if (input == -1) {
			break;
		}

		const vector<int> divisors = get_divisors(input);
		int sum = 0;
		for (const int divisor : divisors) {
			sum += divisor;
		}

		if (sum == input) {
			printf("%d = %d", input, divisors[0]);
			for (int i = 1; i < divisors.size(); ++i) {
				printf(" + %d", divisors[i]);
			}

			printf("\n");
		}
		else {
			printf("%d is NOT perfect.\n", input);
		}
	}

	return 0;
}