#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> Alphabets;

vector<int> union_find(1001, -1);

int uf_get_head(const int id) {
	if ((union_find[id] == -1) || (union_find[id] == id)) {
		return union_find[id] = id;
	}

	return union_find[id] = uf_get_head(union_find[id]);
}

void uf_merge(const int id_1, const int id_2) {
	const int head_1 = uf_get_head(id_1);
	const int head_2 = uf_get_head(id_2);

	union_find[head_2] = head_1;
}

bool is_anagram(const Alphabets alphabets_1, const Alphabets alphabets_2) {
	for (int i = 0; i < 27; ++i) {
		if (alphabets_1[i] != alphabets_2[i]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	while (true) {
		int N;
		cin >> N;

		if (N == 0) {
			break;
		}

		vector<string> words(N);
		vector<Alphabets> alphabets_container(N);
		for (int i = 0; i < N; ++i) {
			Alphabets alphabets(27, 0);
			cin >> words[i];

			for (const char c : words[i]) {
				++alphabets[c - 'a'];
			}

			alphabets_container[i] = alphabets;
		}
		
		union_find = vector<int>(1001, -1);
		int max_size = 0;
		int max_idx = 0;
		for (int i = 0; i < N; ++i) {
			if (uf_get_head(i) != i) {
				continue;
			}
			
			int cur_size = 0;
			for (int k = i + 1; k < N; ++k) {
				if (is_anagram(alphabets_container[i], alphabets_container[k])) {
					uf_merge(i, k);
					++cur_size;
				}
			}

			if (max_size < cur_size) {
				max_size = cur_size;
				max_idx = i;
			}
		}

		cout << words[max_idx] << " " << max_size << "\n";
	}

	return 0;
}