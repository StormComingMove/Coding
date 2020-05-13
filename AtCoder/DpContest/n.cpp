#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define ll long long

int main(void){
	int n;
	cin >> n;
	vector<int> slime(n);
	for(int i= 0;i < n;i++)
		cin >> slime[i];
	vector<vector<ll> > dp(n, vector<ll>(n)); // x -> y substring - value
	vector<ll> pref_sum(n);
	pref_sum[0] = slime[0];
	for(int i = 1;i < n;i++)
		pref_sum[i] = pref_sum[i-1]+slime[i];
	for(int slen = 2;slen <= n;slen++){
		for(int start = 0;start <= n-slen;start++){
			int end = start+slen-1;
			ll minn = LLONG_MAX;
			for(int first_len = 1;first_len <= slen-1;first_len++){ // first substring, second substring
				ll first_ans = dp[start][start+first_len-1];
				ll second_ans = dp[start+first_len][end];
				minn = min(minn, first_ans + second_ans + (pref_sum[end] - pref_sum[start] + slime[start]));
			}
			dp[start][end] = minn;
		}
	}
	cout << dp[0][n-1] << endl;
	return 0;
}
