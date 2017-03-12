#include "BTreeNode.h"

class BinarySearchTree {
private:
	BTreeNode *root;
public:
	BinarySearchTree(BTreeNode* root) :root(root){
	}
public:
	static void insert(BTreeNode * treePtr,int value) {
		if (treePtr->getValue() < value) {//rightSubTree·Î
			if (!treePtr->hasRightSubTree()) {
				BTreeNode * newTree = new BTreeNode(value);
				treePtr->setRightSubTree(newTree);
			}
			else {
				BinarySearchTree::insert(treePtr->getRightSubTree(), value);
			}
		}
		else {
			if (!treePtr->hasLeftSubTree()) {
				BTreeNode * newTree = new BTreeNode(value);
				treePtr->setLeftSubTree(newTree);
			}
			else {
				BinarySearchTree::insert(treePtr->getLeftSubTree(), value);
			}
		}
	}

	BTreeNode* search(int value) {
		BTreeNode* curSubTree = root;
		std::cout << curSubTree->getValue() << std::endl;
		while (true) {
			std::cout << curSubTree->getValue() << std::endl;
			if (curSubTree->getValue() < value) {
				if (!curSubTree->hasRightSubTree()) {
					return NULL;
				}
				curSubTree = curSubTree->getRightSubTree();
				continue;
			}
			else if (curSubTree->getValue() > value) {
				if (!curSubTree->hasLeftSubTree()) {
					return NULL;
				}
				curSubTree = curSubTree->getLeftSubTree();
				continue;
			}
			else {
				return curSubTree;
			}
		}
	}


};