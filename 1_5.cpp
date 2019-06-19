
#include <iostream>
#include <string>

using namespace std;

bool is_one_way(string src, string target) {

	string *str_longer, *str_shorter;

	if (target.size() > src.size()) {
		str_longer = &target;
		str_shorter = &src;
	} else {
		str_longer = &src;
		str_shorter = &target;
	}

	if (str_longer->size() > str_shorter->size() + 1)
		return false;

	if (str_longer->size() == str_shorter->size()) {
		int diff_idx = -1;

		for (int i=0, long_idx=0; i<str_shorter->size(); ++i, ++long_idx) {
			char c_short = (*str_shorter)[i];
			char c_long = (*str_longer)[long_idx];

			if (c_short != c_long) {
				if (diff_idx >= 0)
					return false;
			}
		}

	} else {
		int diff_idx = -1;
		int long_idx = 0;

		for (int i=0; i<str_shorter->size(); ++i, ++long_idx) {
			char c_short = (*str_shorter)[i];
			char c_long = (*str_longer)[long_idx];

			if (c_short != c_long) {
				if (diff_idx >= 0)
					return false;

				diff_idx = long_idx;
				i--;
			}
		}

		if (long_idx < str_longer->size() -1)
			return false;
	}

	return true;
}

int main() {
	cout << is_one_way("ple", "ple") << endl;
	cout << is_one_way("ple", "pla") << endl;
	cout << is_one_way("ple", "pleea") << endl;
	cout << is_one_way("ple", "plee") << endl;
	cout << is_one_way("aple", "ple") << endl;
	cout << is_one_way("plae", "ple") << endl;
	cout << is_one_way("plae", "plb") << endl;
}
