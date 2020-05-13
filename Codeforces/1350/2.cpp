#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long

const int mod = 1e9+7;

void add_self(int& x, int y){
	x += y;
	if(x >= mod)
		x -= mod;
	return;
}

int main(void){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0;i< n;i++)
			cin >> v[i];
		int x = 2;
		int ans = 0;
		vector<int> dp(n+1, 1);
		for(int i = n;i > 0;i--){
			int temp = dp[i];
			for(int j = i;j <= n;j = j + i){
				if(v[j-1] > v[i-1]){
					dp[i] = max(dp[i], temp + dp[j]);
				}
			}
		}
		for(int i = 0;i <= n;i++)
			ans = max(ans, dp[i]);
		cout << ans << endl;
	}
	return 0;
}
