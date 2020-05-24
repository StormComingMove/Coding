// find how many universal value trees present in given binary tree
// universal value tree means - all of the nodes of that tree have same valeus

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
	int value;
	Node left;
	Node right;
	
public:
	Node(int x){
		this->value = x;
	}
};

Node* convertToBinaryTree(vector<string> v);

int main(void){
	int n;
	cin >> n;
	return 0;
}
