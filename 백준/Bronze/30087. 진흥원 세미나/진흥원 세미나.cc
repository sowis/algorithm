#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	map<string, string> board;
	board["Algorithm"] = "204";
	board["DataAnalysis"] = "207";
	board["ArtificialIntelligence"] = "302";
	board["CyberSecurity"] = "B101";
	board["Network"] = "303";
	board["Startup"] = "501";
	board["TestStrategy"] = "105";

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string semina;
		cin >> semina;

		cout << board[semina] << "\n";
	}

	return 0;
}