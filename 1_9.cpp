
#include <stdlib.h>

#include <ctime>
#include <iostream>

#include <string>

using namespace std;

bool is_rotate(string s1, string s2) {

	if (s1.size() != s2.size())
		return false;

	string s2_cat = s2 + s2;

	if (s2_cat.find(s1) == string::npos)
		return false;

	return true;
}

int main() {
	cout << is_rotate("waterbottle", "erbottlewat") << endl;
	cout << is_rotate("waterbottle", "erbotttewat") << endl;
}
