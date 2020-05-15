#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int scoreOfParentheses(string s){
		int len = s.length();
		stack<int> lifo;
		for(int i = 0;i < len;i++){
			if(s[i] == '('){
				lifo.push(-1);
				continue;
			}
			int top = lifo.top();
			if(top == -1){
				lifo.pop();
				int to_push = 1;
				if(lifo.empty()){
					lifo.push(to_push);
					continue;
				}
				if(lifo.top() != -1){
					int temp = lifo.top();
					lifo.pop();
					to_push += temp;
				}
				lifo.push(to_push);
				continue;
			}
			int to_push = top;
			to_push *= 2;
			lifo.pop(); // top pop
			lifo.pop(); // -1 pop
			if(lifo.empty()){
				lifo.push(to_push);
				continue;
			}
			if(lifo.top() == -1){
				lifo.push(to_push);
				continue;
			}
			to_push += lifo.top();
			lifo.pop();
			lifo.push(to_push);
		}
		return lifo.top();
	}
	
};

int main(void){
	Solution* s = new Solution();
	cout << s->scoreOfParentheses("((()))") << endl;
	return 0;
}
