// a2(a3(a)) -  aaaaaaaaa
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main(void){
	string s;
	cin >> s;
	stack <string> lifo;
	int len = s.length();
	for(int i = 0;i < len;i++){
		if(lifo.empty()){
			lifo.push(string(1, s[i]));
			continue;
		}
		string top_str = lifo.top();
		if(s[i] >= 'a' && s[i] <= 'z'){
			int top_len = top_str.length();
			if(top_str[top_len-1] >= 'a' && top_str[top_len-1] <= 'z'){
				lifo.pop();
				top_str += s[i];
				lifo.push(top_str);
				continue;
			}
			lifo.push(string(1, s[i]));
			continue;
		}
		if(s[i] >= '0' && s[i] <= '9'){
			int top_len = top_str.length();
			if(top_str[top_len-1] >= '0' && top_str[top_len-1] <= '9'){
				lifo.pop();
				top_str += s[i];
				lifo.push(top_str);
				continue;
			}
			lifo.push(string(1, s[i]));
			continue;
		}
		if(s[i] == '('){
			lifo.push(string(1, s[i]));
			continue;
		}
		if(s[i] == ')'){
			string top = lifo.top(); // abc - we need to multiply and push to stack
			lifo.pop();
			if((lifo.top()).compare("(") != 0){
				int stack_len = lifo.size();
				cout << top << endl;
				for(int j = 0;j < stack_len;j++){
					cout << lifo.top() << endl;
					lifo.pop();
				}
				cout << "u have done something not right" << endl;
				return 0;
			}
			lifo.pop(); // removes '('
			string number = lifo.top();
			lifo.pop();
			int x = stoi(number);
			string to_insert = "";
			for(int j = 0;j < x;j++){
				to_insert = to_insert + top;
			}
			if(lifo.empty()){
				lifo.push(to_insert);
				continue;
			}
			string temp_top = lifo.top();
			if(temp_top[0] >= 'a' && temp_top[0] <= 'z'){
				lifo.pop();
				string final_insert = temp_top + to_insert;
				lifo.push(final_insert);
				continue;
			}
			lifo.push(to_insert);
			continue;
		}
	}
	cout << lifo.top() << endl;
	return 0;
}
