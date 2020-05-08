// Longest Common Subsequence - output string
// ganesh, mahesh -> aesh

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string lcs(string& s, string& t);

int main(void) {
	string s, t;
	cin >> s >> t;
	cout << lcs(s, t) << endl;
	return 0;
}

string lcs(string& s, string& t) {
	int slen = s.length();
	int tlen = t.length();
	vector<vector<int>> dp(slen+1, vector<int> (tlen+1, -1));
	for(int i = 0;i <= slen;i++)
		dp[i][0] = 0;
	for(int i = 0;i <= tlen;i++)
		dp[0][i] = 0;
	for(int i = 1;i <= slen;i++) {
		for(int j = 1;j <= tlen;j++) {
			if(s[i-1] == t[j-1])
				dp[i][j] = 1+dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int ans_len = dp[slen][tlen];
	cout << ans_len << endl;
	vector<char> ans;
	for(int i = slen, j = tlen;i > 0 && j > 0;) {
		if(s[i-1] == t[j-1]){
			ans.push_back(s[i-1]);
			i--,j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]) {
			i--;
		}
		else {
			j--;
		}
	}
	reverse(ans.begin(), ans.end());
	
	return string(ans.begin(), ans.end());
}
