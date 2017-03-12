#ifndef _BTreeNode_H_
#define _BTreeNode_H_
#include <iostream>
class BTreeNode {
private:
	int value;
public:
	BTreeNode* leftChild;
	BTreeNode* rightChild;
public:
	BTreeNode() {
		this->leftChild = NULL;
		this->rightChild = NULL;
		this->value = 0;
	}
	BTreeNode(const BTreeNode& copy) {
		this->value = copy.value;
		this->leftChild = copy.leftChild;
		this->rightChild = copy.rightChild;
	}
	BTreeNode(int value) : value(value) {
		this->leftChild = NULL;
		this->rightChild = NULL;
	}

	int getValue() {
		return value;
	}

	void setValue(int value) {
		this->value = value;
	}

	BTreeNode* getLeftSubTree() {
		return this->leftChild;
	}

	BTreeNode* getRightSubTree() {
		return this->rightChild;
	}

	void setLeftSubTree(BTreeNode* tree) {
		this->leftChild = tree;
	}

	void setRightSubTree(BTreeNode* tree) {
		this->rightChild = tree;
	}

	bool hasLeftSubTree() {
		if (this->leftChild != NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	bool hasRightSubTree() {
		if (this->rightChild != NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	void preorderTraversal(void(*fptr) (int)) {
		fptr(this->getValue());
		if (hasLeftSubTree()) {
			this->getLeftSubTree()->preorderTraversal(fptr);
		}
		if (hasRightSubTree()) {
			this->getRightSubTree()->preorderTraversal(fptr);
		}
	}
	void inorderTraversal(void(*fptr) (int)) {
		if (hasLeftSubTree()) {
			this->getLeftSubTree()->inorderTraversal(fptr);
		}
		fptr(this->getValue());
		if (hasRightSubTree()) {
			this->getRightSubTree()->inorderTraversal(fptr);
		}
	}
	void postorderTraversal(void(*fptr) (int)) {
		if (hasLeftSubTree()) {
			this->getLeftSubTree()->postorderTraversal(fptr);
		}
		if (hasRightSubTree()) {
			this->getRightSubTree()->postorderTraversal(fptr);
		}
		fptr(this->getValue());
	}
};

#endif