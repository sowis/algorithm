#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string my_mbti;
	cin >> my_mbti;

	int N;
	cin >> N;

	int result = 0;
	for (int i = 0; i < N; ++i) {
		string friend_mbti;
		cin >> friend_mbti;

		if (my_mbti == friend_mbti) {
			++result;
		}
	}

	cout << result << "\n";

	return 0;
}