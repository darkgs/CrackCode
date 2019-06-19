
#include <iostream>
#include <string>

using namespace std;

string compress(string input) {

	char* buf = new char[input.size()*2 + 1];

	for (int i=0; i<(sizeof(buf)/sizeof(*buf)); ++i) {
		buf[i] = '\0';
	}

	char c_cur = -1;
	int accum = 0;

	int buf_idx = 0;
	for (int i=0; i<input.size(); ++i) {
		char c = input[i];

		if (c_cur != c) {
			if (c_cur < 0) {
				c_cur = c;
				accum = 1;
				continue;
			}

			//
			buf[buf_idx++] = c_cur;

			//
			if (accum <= 0)
				continue;

			int digit = 0;
			{
				int tmp = accum;
				while(tmp > 0) {
					digit++;
					tmp /= 10;
				}
			}

			//
			for (int i=0; i<digit; ++i) {
				buf[buf_idx + digit -1 - i] = '0' + (accum % 10);
				accum /= 10;
			}

			buf_idx += digit;

			//
			c_cur = c;
			accum = 1;
		} else {
			accum += 1;
		}
	}

	string ret(buf);

	delete[] buf;

	if (ret.size() < input.size())
		return ret;

	return input;
}

int main() {
	cout << compress("aaaaaaaaaaaaaaaaaaaaaaaaabccccccccddde") << endl;
	cout << compress("abcd") << endl;
}
