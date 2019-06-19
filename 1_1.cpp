
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

int main() {
	cout << is_unique("abcde") << endl;
}
