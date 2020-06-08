#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int minAddToMakeValid(string s){
		int len = s.length();
		stack<char> lifo;
		int ans = 0;
		for(int i = 0;i < len;i++){
			if(s[i] == '('){
				lifo.push(s[i]);
				continue;
			}
			if(s[i] == ')'){
				if(lifo.empty()){
					ans++;
					continue;
				}
				else if(lifo.top() == '(')
					lifo.pop();
			}
		}
		ans += lifo.size();
		return ans;
	}
};

int main(void){
	
	return 0;
}
