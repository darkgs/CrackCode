
#include <iostream>
#include <string>

#include <ctime>
#include <algorithm>

using namespace std;

void generate_rand_array(int *array, int size){

	for (int i=0; i<size; ++i) {
		array[i] = rand()%128;
	}
}

//
typedef struct _BSTNode {
private:
	int m_val;
	struct _BSTNode *m_left, *m_right;

public:
	_BSTNode(int val, struct _BSTNode *left=NULL, struct _BSTNode *right=NULL) {
		m_val = val;
		m_left = left;
		m_right = right;
	}

	int get_value() {
		return m_val;
	}

	void print_inorder() {
		if (m_left != NULL)
			m_left->print_inorder();

		cout << m_val << " ";

		if (m_right != NULL)
			m_right->print_inorder();
	}

} BSTNode;

BSTNode* generate_BST(int *array, int size, int cur) {
	if (cur >= size)
		return NULL;

	cout << "(" << cur << ", " << size << ")" << endl;

	int left_idx = cur * 2;
	int right_idx = cur * 2 + 1;

	BSTNode *node = new BSTNode(array[cur],
			generate_BST(array, size, left_idx), generate_BST(array, size, right_idx));

	return node;
}

int main() {
	srand((unsigned int)time(0));

	int array[100];

	generate_rand_array(array, sizeof(array)/sizeof(*array));

	sort(array, array+(sizeof(array)/sizeof(*array)));

	BSTNode *root = generate_BST(array, sizeof(array)/sizeof(*array), 0);

	/*
	for(int i=0; i<(sizeof(array)/sizeof(*array)); ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
	*/
}
