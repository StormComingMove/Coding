#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class BST{
public:
	int value;
	BST* left;
	BST* right;
	
	BST(int val){
		value = val;
		left = NULL;
		right = NULL;
	}

	BST& insert(int val){
		if(val >= value){
			if(this->right == NULL){
				BST* to_insert = new BST(val);
				this->right = to_insert;
			}
			else{
				this->right->insert(val);
			}
			return *this;
		}
		else{
			if(this->left == NULL){
				BST* to_insert = new BST(val);
				this->left = to_insert;
			}
			else{
				this->left->insert(val);
			}
			return *this;
		}
	}

	int getleftmost(BST* root){
		if(root->left == NULL)
			return root->value;
		return getleftmost(root->left);
	}
	
	BST& remove(int val, BST* parent = NULL){
		if(value == val){
			if(parent == NULL && left == NULL && right == NULL)
				return *this;
			if(right == NULL & left == NULL){
				if(parent->left == this)
					parent->left = NULL;
				else
					parent->right = NULL;
				return *this;
			}
			if(right == NULL && parent != NULL){
				if(parent->left == this)
					parent->left = this->left;
				else
					parent->right = this->left;
				return *this;
			}
			if(right == NULL && parent == NULL){
				this->value = this->left->value;
				this->right = this->left->right;
				this->left = this->left->left;
				return *this;
			}
			if(left == NULL && parent == NULL){
				this->value = this->right->value;
				this->left = this->right->left;
				this->right = this->right->right;
				return *this;
			}
			int new_val = getleftmost(this->right);
			this->value = new_val;
			BST& trash = this->right->remove(new_val, this);
		}
		else if(value < val){
			if(this->right == NULL)
				return *this;
			return this->right->remove(val, this);
		}
		else
			if(this->left == NULL)
				return *this;
			return this->left->remove(val, this);
	}

	bool contains(int val){
		if(value == val)
			return true;
		if(val < value){
			if(this->left == NULL)
				return false;
			return this->left->contains(val);
		}
		else{
			if(this->right == NULL)
				return false;
			return this->right->contains(val);
		}
	}
};

int main(void){
	
	return 0;
} 
