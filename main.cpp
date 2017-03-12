#include <iostream>
#include "BinarySearchTree.h"

void print(int num) {
	std::cout << num << " ";
}

int main() {
	BTreeNode root = BTreeNode(17);
	BinarySearchTree bst = BinarySearchTree(&root);
	BinarySearchTree::insert(&root, 9);
	BinarySearchTree::insert(&root, 25);
	BinarySearchTree::insert(&root, 11);
	BinarySearchTree::insert(&root, 10);
	root.inorderTraversal(print);
	BTreeNode* tree = bst.search(11);
	if (tree == NULL) {
		std::cout << "data ¾øÀ½" << std::endl;
	}
	else {
		std::cout << "data : " << tree->getValue() << std::endl;
	}
}