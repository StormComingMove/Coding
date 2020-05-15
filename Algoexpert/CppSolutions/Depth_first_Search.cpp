#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
	string name;
	vector<Node*> children;
	
	// constructor
	Node(string str) { name = str; }
	
	Node* addChild(string name){
		Node* child = new Node(name);
		children.push_back(child);
		return this;
	}
	
	vector<string> depthFirstSearch(vector<string> * array){
		(*array).push_back(this->name);
		int size = this->children.size();
		for(int i = 0;i < size;i++)
			vector<string> temp = children[i] -> depthFirstSearch(array);
		return *array;
	}
};

int main(void){
	
	return 0;
}
