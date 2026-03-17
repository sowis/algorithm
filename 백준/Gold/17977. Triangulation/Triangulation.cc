#include <iostream>
#include <cmath>

using namespace std;

long long max_n(const long long d) {
    if (d == 0) {
        return 3;
    }

    if (d % 2) {
        const long long k = (d + 1) / 2;
        return (long long)pow(2, k + 1);
    }
    else {
        const long long k = d / 2;
        return 3 * (long long)pow(2, k);
    }
}

int main(void) {
    long long n;
    cin >> n;

    long long d = 0;
    while (true) {
        if (max_n(d) >= n) {
            cout << d;
            break;
        }

        ++d;
    }

    return 0;
}