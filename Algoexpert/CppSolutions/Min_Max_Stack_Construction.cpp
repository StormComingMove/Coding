#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MinMaxStack {
	stack<int> nums;
	stack<int> maxx;
	stack<int> minn;
public:
	int peek(){
		if(nums.size() == 0)
			return -1;
		return nums.top();
	}

	int pop(){
		if(nums.size() == 0)
			return -1;
		int x = nums.top();
		nums.pop();
		maxx.pop();
		minn.pop();
		return x;
	}

	void push(int number){
		nums.push(number);
		if(maxx.size() != 0){
			if(maxx.top() < number)
				maxx.push(number);
			else
				maxx.push(maxx.top());
		}
		else
			maxx.push(number);
		if(minn.size() != 0){
			if(minn.top() > number)
				minn.push(number);
			else
				minn.push(minn.top());
		}
		else
			minn.push(number);
		return;
	}

	int getMin(){
		return minn.top();
	}

	int getMax(){
		return maxx.top();
	}
};

int main(void){
	
	return 0;
}
