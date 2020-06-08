#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

// add Solution class below

class Solution {
public:
    string longestPalindrome(string s) {
		int len = s.length();
		int n = len;
		if(len == 0)
			return "";
		vector<int> even(len, 1);
		vector<int> odd(len, 1);
		int odd_len = len;
		int even_len = odd_len-1;
		string ans = s.substr(0, 1);
		for(int i = 0;i < even_len;i++){
			if(s[i] == s[i+1]){
				even[i] = 1;
				if(ans.length() < 2)
					ans = s.substr(i, 2);
			}
			else
				even[i] = 0;
		}
		for(int i = 3;i <= n;i++){
			for(int j = 0;j <= n-i;j++){
				if(i%2){
					if(s[j] == s[j+i-1] && odd[j+1] == 1){
						odd[j] = 1;
						if(ans.length() < i){
							ans = s.substr(j, i);
						}
					}
					else
						odd[j] = 0;
				}
				else{
					if(s[j] == s[j+i-1] && even[j+1] == 1){
						even[j] = 1;
						if(ans.length() < i){
							ans = s.substr(j, i);
						}
					}
					else
						even[j] = 0;
				}
			}
		}
		return ans;
    }
};

int main(void){
	Solution* s = new Solution();
	// add code below
	string str;
	cin >> str;
	cout << s->longestPalindrome(str) << endl;
	return 0;
}
