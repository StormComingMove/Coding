#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

// add Solution class below

class Solution {
public:
    bool isValid(string s) {
		stack<char> lifo;
		const int len = s.length();
		for(int i = 0;i < len;i++){
			if(s[i] == '(' || s[i] == '{' || s[i] == '['){
				lifo.push(s[i]);
				continue;
			}
			if(lifo.empty())
				return false;
			if(s[i] == ')'){
				if(lifo.top() == '(')
					lifo.pop();
				else
					return false;
			}
			else if(s[i] == ']'){
				if(lifo.top() == '[')
					lifo.pop();
				else
					return false;
			}
			else if(s[i] == '}'){
				if(lifo.top() == '{')
					lifo.pop();
				else
					return false;
			}
		}
		if(lifo.size() == 0)
			return true;
		return false;
    }
};

int main(void){
	Solution* sol = new Solution();
	// add code below
	string s;
	cin >> s;
	cout << (sol->isValid(s) ? "true" : "false") << endl;
	return 0;
}
