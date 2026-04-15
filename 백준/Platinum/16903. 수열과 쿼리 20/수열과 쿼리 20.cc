#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct _data {
	char c;
	int data_count;
	int descendent_count;
	struct _data *childs[2];
} Data;

string number_to_binary(int num) {
	string result(32, '0'); // x의 범위가 10^9 까지이므로 32비트로 표시
	int str_idx = (int)result.size() - 1;
	while (num > 0) {
		if (num % 2) {
			result[str_idx] = '1';
		}

		num /= 2;
		--str_idx;
	}

	return result;
}

int binary_to_number(const vector<int>& binary) {
	int result = 0;
	int mul = 1;
	for (int i = (int)binary.size() - 1; i >= 0; --i) {
		if (binary[i] == 1) {
			result += mul;
		}

		mul *= 2;
	}

	return result;
}

class Trie {
private:
	Data root;

	void insert(const string& str, const int idx, Data* current_node) {
		if (idx == str.size()) {
			++(current_node->data_count);
			return;
		}

		++(current_node->descendent_count);

		if (current_node->childs[str[idx] - '0'] == nullptr) {
			Data* next_node = new Data();
			next_node->c = str[idx];
			next_node->data_count = 0;
			next_node->childs[0] = nullptr;
			next_node->childs[1] = nullptr;

			current_node->childs[str[idx] - '0'] = next_node;
		}

		insert(str, idx + 1, current_node->childs[str[idx] - '0']);
	}

	void remove(const string& str, const int idx, Data* current_node) {
		if (idx == str.size()) {
			--(current_node->data_count);
			return;
		}

		--(current_node->descendent_count);

		this->remove(str, idx + 1, current_node->childs[str[idx] - '0']);

		if (current_node->childs[str[idx] - '0']->data_count == 0 && current_node->childs[str[idx] - '0']->descendent_count == 0) {
			delete current_node->childs[str[idx] - '0'];
			current_node->childs[str[idx] - '0'] = nullptr;
		}
	}

	void get_xor_max(const string& xor_str, const int idx, Data* current_node, vector<int> &result) {
		if (idx == xor_str.size()) {
			return;
		}

		Data* next_node = nullptr;

		if (xor_str[idx] == '0') { // xor 할 문자가 0 이면 1, 0 순서로 탐색 (앞자리에서 달라야 결과가 크게 나오므로..)
			for (int i = 1; i >= 0; --i) {
				if (current_node->childs[i] != nullptr) {
					result.push_back((i == (xor_str[idx]) - '0') ? 0 : 1); // xor한 값을 저장
					next_node = current_node->childs[i];
					break;
				}
			}
		}
		else if (xor_str[idx] == '1') { // xor 할 문자가 1 이면 0, 1 순서로 탐색
			for (int i = 0; i <= 1; ++i) {
				if (current_node->childs[i] != nullptr) {
					result.push_back((i == (xor_str[idx]) - '0') ? 0 : 1);
					next_node = current_node->childs[i];
					break;
				}
			}
		}

		this->get_xor_max(xor_str, idx + 1, next_node, result);
	}

public:
	Trie(void) {
		this->root.data_count = 0;
		this->root.descendent_count = 0;
		this->root.childs[0] = nullptr;
		this->root.childs[1] = nullptr;
	}

	void insert(const string& str) {
		this->insert(str, 0, &(this->root));
	}

	void remove(const string& str) {
		this->remove(str, 0, &(this->root));
	}

	vector<int> get_xor_max(const string& xor_str) {
		vector<int> result;
		this->get_xor_max(xor_str, 0, &(this->root), result);
		return result;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M;
	cin >> M;

	Trie trie;
	trie.insert(number_to_binary(0)); // 기본값으로 0 넣기

	while (M--) {
		int op, x;
		cin >> op >> x;

		if (op == 1) {
			trie.insert(number_to_binary(x));
		}
		else if (op == 2) {
			trie.remove(number_to_binary(x));
		}
		else if (op == 3) {
			cout << binary_to_number(trie.get_xor_max(number_to_binary(x))) << "\n";
		}
	}

	return 0;
}