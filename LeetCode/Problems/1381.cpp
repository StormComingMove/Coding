#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
using namespace std;

class CustomStack {
	stack <int> lifo;
	int maxSize;
	vector<int> add;
public:
	CustomStack(int maxSize){
		this->maxSize = maxSize;
		add.resize(maxSize+1, 0);
	}
	
	void push(int x){
		if(lifo.size() < maxSize){
			lifo.push(x);
		}
		return;
	}

	int pop(){
		if(lifo.size() == 0)
			return -1;
		int top_elem = lifo.top();
		int curr_size = lifo.size();
		int new_top = top_elem;
		for(int i = 0;i < curr_size;i++){
			new_top += add[i];
		}
		add[curr_size-1] += add[curr_size];
		add[curr_size] = 0;
		lifo.pop();
		return new_top;
	}
	
	void increment(int k, int val){
		int upto = min(k, maxSize);
		int curr_size = lifo.size();
		upto = min(upto, curr_size);
		add[0] += val;
		add[upto] -= val;
		return;
	}

};

int main(void){
	
	return 0;
}
