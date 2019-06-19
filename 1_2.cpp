
#include <iostream>
#include <string>

using namespace std;

bool is_unique(string input) {

	static bool check[128];

	for (int i=0; i<(sizeof(check)/sizeof(*check)); ++i) {
		check[i] = false;
	}

	for (int i=0; i<input.size(); ++i) {
		char c = input[i];

		if (c >= 128 || c < 0) {
			continue;
		}

		if (check[c]) {
			return true;
		}

		check[c] = true;
	}

	return false;
}

bool is_permutate(string input1, string input2) {

	if (input1.size() == 0 || input2.size() == 0)
		return false;

	if (input1.size() != input2.size())
		return false;

	int count[128] = {0, };

	for (int i=0; i<input1.size(); ++i) {
		char c_1 = input1[i];
		char c_2 = input2[i];

		if (c_1 < 0 || c_2 < 0) {
			cout << "invalid input : " << input1 << ", " << input2 << endl;
			return false;
		}

		count[c_1]++;
		count[c_2]--;

	}

	for (int i=0; i<(sizeof(count)/sizeof(*count)); ++i) {
		if (count[i] != 0)
			return false;
	}

	return true;
}

int main() {
	cout << is_permutate("bac", "aba") << endl;
}
