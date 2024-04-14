#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;

	unordered_map<string, set<string>> team_to_member;
	unordered_map<string, string> member_to_team;
	for (int i = 0; i < N; ++i) {
		string team;
		cin >> team;

		int member_count;
		cin >> member_count;

		for (int k = 0; k < member_count; ++k) {
			string name;
			cin >> name;

			team_to_member[team].insert(name);
			member_to_team[name] = team;
		}
	}

	for (int i = 0; i < M; ++i) {
		string name;
		int op;


		cin >> name >> op;

		if (op == 0) {
			for (const string& name : team_to_member[name]) {
				cout << name << "\n";
			}
		}
		else {
			cout << member_to_team[name] << "\n";
		}
	}

	return 0;
}