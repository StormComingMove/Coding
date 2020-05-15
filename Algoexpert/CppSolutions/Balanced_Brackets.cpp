#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool balancedBrackets(string str){
	stack<char> lifo;
	int n = str.length();
	for(int i = 0;i < n;i++){
		if(lifo.empty()){
			if(str[i] == '{' || str[i] == '[' || str[i] == '(')
				lifo.push(str[i]);
			else
				return false;
			continue;
		}
		if(str[i] == '{' || str[i] == '[' || str[i] == '('){
			lifo.push(str[i]);
			continue;
		}
		if(str[i] == '}' && lifo.top() == '{')
			lifo.pop();
		else if(str[i] == ')' && lifo.top() == '(')
			lifo.pop();
		else if(str[i] == ']' && lifo.top() == '[')
			lifo.pop();
		else
			return false;
	}
	if(lifo.size() == 0)
		return true;
	return false;
}

int main(){
	
	return 0;
}
