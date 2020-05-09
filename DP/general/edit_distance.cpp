// insert, replace, remove - minimum no. of operations

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int distance(string& s, string& t);

int main(void) {
	string s, t; // convert s -> t
	cin >> s >> t;
	cout << distance(s, t) << endl;
	return 0;
}

int distance(string& s, string& t) {
	int slen = s.length();
	int tlen = t.length();
	vector<vector<int>> dp(tlen+1, vector<int>(slen+1, INT_MAX));
	for(int i = 0;i <= slen;i++)
		dp[0][i] = i;
	for(int i = 0;i <= tlen;i++)
		dp[i][0] = i;
	for(int i = 1;i <= tlen;i++) {
		for(int j = 1;j <= slen;j++) {
			dp[i][j] = min((s[j-1] == t[i-1]) ? dp[i-1][j-1] : dp[i-1][j-1]+1, dp[i-1][j]+1);
		}
	}
	return dp[tlen][slen];
}
