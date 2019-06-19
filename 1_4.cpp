
#include <iostream>
#include <string>

using namespace std;

bool is_palindrome_permutation(string input) {

	if (input.size() <= 0) {
		return false;
	}

	int count[128] = {0, };
	int c_count = 0;

	for(int i=0; i<input.size(); ++i) {
		char c = input[i];
		
		if (c < 0) {
			return false;
		}

		if (c == ' ')
			continue;

		if (c >= 'A' && c <= 'Z') {
			c = 'a' + c - 'A';
		}

		count[c]++;
		c_count++;
	}

	bool is_odd = ((c_count % 2) == 1) ? true : false;
	int odd_count = 0;

	for(int i=0; i<(sizeof(count)/sizeof(*count)); ++i) {
		if (count[i]%2 == 1)
			odd_count++;
	}

	if (odd_count == 0) {
		return true;
	} else if (odd_count == 1 && is_odd) {
		return true;
	}
	cout << odd_count << is_odd << endl;

	return false;
}

int main() {
	cout << is_palindrome_permutation("Taco cat") << endl;
}
