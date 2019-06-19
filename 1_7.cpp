
#include <iostream>
#include <string>

using namespace std;

void rotate(int** matrix, int mat_size) {

	for (int layer=0; layer<mat_size; ++layer) {
		int start = layer;
		int end = mat_size - layer - 1;

		for (int i=0; i<(end-start); ++i) {
			int top = matrix[layer][start+i];

			matrix[layer][start+i] = matrix[end-i][layer];
			matrix[end-i][layer] = matrix[end][end-i];
			matrix[end][end-i] = matrix[start+i][end];
			matrix[start+i][end] = top;
		}
	}
	
}

void print_matrix(int** matrix, int mat_size) {

	for (int c=0; c<mat_size; ++c) {
		for (int r=0; r<mat_size; ++r) {
			cout << matrix[c][r] << "\t";
		}
		cout << endl;
	}
}

int main() {
	//
	int** matrix = new int*[8];
	for(int i=0; i<8; ++i) {
		matrix[i] = new int[8];
	}

	for (int c=0; c<8; ++c) {
		for (int r=0; r<8; ++r) {
			matrix[c][r] = 8*c + r;
		}
	}

	//
	rotate(matrix, 8);
	print_matrix(matrix, 8);

	//
	for (int i=0; i<8; ++i) {
		delete matrix[i];
	}
	delete[] matrix;
}
