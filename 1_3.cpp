
#include <iostream>
#include <string>

using namespace std;

string urlify(string input, int input_length) {

	if (input.size() < input_length) {
		return NULL;
	}

	if (input_length < 0) {
		return NULL;
	}

	char *buf = new char[input_length*3 + 1];
	int buf_i = 0;
	for (int i=0; i<input_length; ++i) {
		buf[buf_i] = input[i];

		if (buf[buf_i] == ' ') {
			buf[buf_i] = '%';
			buf[buf_i+1] = '2';
			buf[buf_i+2] = '0';
			buf_i += 2;
		}
		buf_i += 1;
	}
	buf[buf_i] = '\0';

	string ret(buf);

	delete buf;

	return ret;
}

int main() {
	cout << urlify("Mr John Smith    ", 13) << endl;
}
