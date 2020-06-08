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
    int lengthOfLongestSubstring(string s) {
		map<char, int> hash;
		int ans = 0;
		int len = s.length();
		if(len == 0) return 0;
		int start = 0;
		for(int i = 0;i < len;i++){
			auto it = hash.find(s[i]);
			if(it == hash.end()){
				hash[s[i]] = i;
			}
			else{
				start = max(start, 1 + hash[s[i]]);
				hash[s[i]] = i;
			}
			ans = max(ans, i-start+1);
		}
		return ans;
    }
};

int main(void){
	Solution* s = new Solution();
	// add code below
	string str;
	cin >> str;
	cout << s->lengthOfLongestSubstring(str) << endl;
	return 0;
}
