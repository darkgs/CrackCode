
#include <stdlib.h>

#include <ctime>
#include <iostream>

#include <string>

using namespace std;

void zero_matrix(int **matrix, int row, int col) {
	bool *row_check = new bool[row];
	bool *col_check = new bool[col];

	for(int i=0; i<row; ++i) {
		row_check[i] = false;
	}

	for(int i=0; i<col; ++i) {
		col_check[i] = false;
	}

	for (int c=0; c<col; ++c) {
		for (int r=0; r<row; ++r) {
			if (matrix[c][r] == 0) {
				row_check[r] = true;
				col_check[c] = true;
			}
		}
	}

	for (int c=0; c<col; ++c) {
		for (int r=0; r<row; ++r) {
			if (row_check[r] || col_check[c]) {
				matrix[c][r] = 0;
			}
		}
	}
}

void print_matrix(int** matrix, int row, int col) {

	for (int c=0; c<col; ++c) {
		for (int r=0; r<row; ++r) {
			cout << matrix[c][r] << "\t";
		}
		cout << endl;
	}
}

int main() {
	srand((unsigned int)time(0));

	//
	int** matrix = new int*[8];
	for(int i=0; i<8; ++i) {
		matrix[i] = new int[8];
	}

	for (int c=0; c<8; ++c) {
		for (int r=0; r<8; ++r) {
			matrix[c][r] = rand() % 32;
		}
	}
	print_matrix(matrix, 8, 8);

	//
	cout << "==========================================" << endl;
	zero_matrix(matrix, 8, 8);
	print_matrix(matrix, 8, 8);
}
