#include <iostream>
#include <cstring>

using namespace std;

int counts = 0;

int recursion(const char* s, int l, int r) {
    ++counts;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    counts = 0;
    return recursion(s, 0, (int)strlen(s) - 1);
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        char str[1001];
        cin >> str;

        cout << isPalindrome(str) << " " << counts << "\n";
    }
}