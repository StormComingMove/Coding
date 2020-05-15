#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BST{
public:
	int value;
	BST* left;
	BST* right;

	// constructor
	BST(int val);
	BST& insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
	if(target == tree->value)
		return target;
	if(target < tree->value){
		int curr_tree = tree->value;
		if(tree->left == nullptr)
			return curr_tree;
		int child_tree = findClosestValueInBst(tree->left, target);
		if(abs(child_tree - target) < abs(curr_tree - target))
			return child_tree;
		return curr_tree;
	}
	int curr_tree = tree->value;
	if(tree->right == nullptr)
		return curr_tree;
	int child_tree = findClosestValueInBst(tree->right, target);
	if(abs(child_tree - target) < abs(curr_tree - target))
		return child_tree;
	return curr_tree;
}

int main(void){
	
	return 0;
}
